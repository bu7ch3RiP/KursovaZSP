cmake_minimum_required(VERSION 3.5)

project(DisplayTesting VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(PROJECT_SOURCES
        main.cpp
        UI/mainwindow.cpp
        Tests/color_test.cpp
        Tests/grid_test.cpp
        UI/systray.cpp
        Tests/read_test.cpp
        Tests/calibration_focus_test.cpp
        Tests/calibration_focus_test.h
        Tests/read_test.h
        Tests/grid_test.h
        Language/language.h
        UI/systray.h
        UI/preference.h
        UI/about.h
        Tests/color_test.h
        UI/mainwindow.h
        UI/mainwindow.ui
)

qt6_add_resources(PROJECT_SOURCES Res.qrc)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(DisplayTesting
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET DisplayTesting APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(DisplayTesting SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(DisplayTesting
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(DisplayTesting PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

set_target_properties(DisplayTesting PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

install(TARGETS DisplayTesting
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(DisplayTesting)
endif()