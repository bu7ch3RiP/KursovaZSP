#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QColor>
#include <QEvent>
#include <QLabel>
#include <QMainWindow>
#include <QMouseEvent>
#include "../Tests/calibration_focus_test.h"
#include "../Tests/color_test.h"
#include "../Tests/grid_test.h"
#include "../Tests/read_test.h"
#include "systray.h"
#include <vector>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class Preference;
class About;

enum class LanguageMode { kUA, kEN };

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void createTestWindow();
    std::vector<const char*> getVector();
    std::vector<uint8_t> getCodeVector();
    std::vector<QColor> getColorVector();
    std::vector<uint8_t> getFocusVector();

    bool eventFilter(QObject *obj, QEvent *event);

protected:
private slots:
    void on_CalibrationTests_clicked();
    void on_GridTests_clicked();
    void on_ColorTests_clicked();
    void on_ReadingTests_clicked();
    void on_actionSelect_all_triggered();
    void on_actionClear_All_triggered();
    void on_RunTests_clicked();
    void on_actionTests_for_LCD_monitors_triggered();
    void on_actionPreferences_triggered();
    void on_actionExit_triggered();
    void handlePreferenceClosed();
    void on_actionAbout_triggered();
    void on_AutoRunTests_clicked();

    void on_actionUkranian_triggered();

    void on_actionEnglish_triggered();

private:
    Ui::MainWindow *ui;
    bool isAutoTest{};
    size_t auto_test_timeout_{};
    bool save_settings_{};
    std::vector<const char*> testsVector{};
    std::vector<uint8_t> testCodeVector{};
    std::vector<QColor> testColorVector{};
    std::vector<uint8_t> testFocusVector{};
    ColorTest *colorTest = nullptr;
    GridTest *gridTest = nullptr;
    ReadTest *readTest = nullptr;
    CalibrationFocusTest *cf_test = nullptr;
    Preference *preference = nullptr;
    About *about = nullptr;
    SysTray *sys_tray = nullptr;
    LanguageMode language_state_;

private:
    void addSelectedColorTests();
    void addSelectedGridTests();
    void addReadTests();
    void addCalibrationTests();
    uint8_t getFirstCodeElement();
    QColor getFirstColorElement();
    void clearAllCheckBoxes();
    void clearAllVectors();
    void checkSelectedTests();
    void SetUALocalization();
    void SetENLocalization();

    void SetPreview(QLabel *preview_lable, const char *picture);
    void SetHoveredLables();

private:
    void closeEvent(QCloseEvent *event) override;
};

#endif // MAINWINDOW_H
