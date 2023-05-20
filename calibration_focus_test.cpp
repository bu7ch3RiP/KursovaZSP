#include "calibration_focus_test.h"

#include <QtWidgets>
#include <QPushButton>
#include <QGuiApplication>
#include <QPainter>
#include <QRect>
#include <QPixmap>
#include <QScreen>
#include <QPaintEvent>
#include <QVBoxLayout>
#include <QKeyEvent>
#include <QLinearGradient>

std::unordered_map<uint8_t, const char *> calib_focus_test_map
    = {{4, ":/color/palette/pictures/LCD_Calibration.png"},
       {5, ":/color/palette/pictures/BrightnessAndContrast.png"},
       {6, ":/color/palette/pictures/Gamma.png"},
       {7, ":/color/palette/pictures/WhitePattern.png"},
       {8, ":/color/palette/pictures/BlackPattern.png"},
       {9, ":/color/palette/pictures/Sharpness.png"}};

CalibrationFocusTest::CalibrationFocusTest(QWidget *parent)
    : QWidget{parent}
{
    label = nullptr;
    backButton = new QPushButton("X", this);
    backButton->setStyleSheet("background-color: #ff00ff;");
    connect(backButton, &QPushButton::clicked, this, &QWidget::close);

    screen = QGuiApplication::primaryScreen();

    backButton->setGeometry(QRect(QPoint(screen->geometry().width()-35, 5), QSize(30, 30)));

    index_ = 0;
    draw_state = DrawType::kNone;
    setFocusPolicy( Qt::StrongFocus );
}

void CalibrationFocusTest::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    switch (draw_state) {
    case DrawType::kDots:
        for (int y = 0; y < screen->geometry().height(); y += kDelta) {
            for (int x = 0; x < screen->geometry().width(); x += kDelta) {
                painter.fillRect(x, y, kPixelsSize, kPixelsSize, Qt::black);
                painter.fillRect(x + kPixelsSize,
                                 y + kPixelsSize,
                                 kPixelsSize,
                                 kPixelsSize,
                                 Qt::black);
            }
        }
        break;
    case DrawType::kGorizontal: {
        painter.setPen(Qt::black);
        int y = 0;
        int spacing = kDelta;

        while (y < screen->geometry().height()) {
            painter.drawLine(0, y, screen->geometry().width(), y);
            y += spacing;
        }
    } break;
    case DrawType::kVertical: {
        painter.setPen(Qt::black);
        int x = 0;
        int spacing = kDelta;

        while (x < screen->geometry().width()) {
            painter.drawLine(x, 0, x, screen->geometry().height());
            x += spacing;
        }
    } break;
    case DrawType::kPicture:
        showCalibrationTest();
        break;
    }
}

void CalibrationFocusTest::setDrawState(DrawType state)
{
    this->draw_state = state;
}

DrawType CalibrationFocusTest::getDrawState()
{
    return draw_state;
}

void CalibrationFocusTest::setTestCodeVector(std::vector<uint8_t> code_vec)
{
    this->testCodeVector = code_vec;
}

void CalibrationFocusTest::setTestFocusVector(std::vector<uint8_t> focus_vec)
{
    this->testFocusVector = focus_vec;
}

void CalibrationFocusTest::setUpTest()
{
    if (testCodeVector[0] == 1) {
        switch (testFocusVector[0]) {
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
            draw_state = DrawType::kPicture;
            break;
        case 1:
            draw_state = DrawType::kDots;
            break;
        case 2:
            draw_state = DrawType::kVertical;
            break;
        case 3:
            draw_state = DrawType::kGorizontal;
            break;
        }
    }
}

void CalibrationFocusTest::showCalibrationTest()
{
    label = new QLabel(this);
    QRect screenGeometry = QGuiApplication::primaryScreen()->geometry();
    QSize screenSize = screenGeometry.size();
    QPixmap pixmap(calib_focus_test_map[testFocusVector[index_]]);
    label->setPixmap(pixmap.scaled(screenSize));
    label->setGeometry(QRect(QPoint(0, 0), screenSize));
    label->showFullScreen();
    backButton->raise();
}
