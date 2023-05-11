
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <vector>
#include <QColor>
#include "color_test.h"
#include "grid_test.h"
#include "read_test.h"



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

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

protected:

private slots:
    void on_CalibrationTests_clicked();
    void on_GridTests_clicked();
    void on_ColorTests_clicked();
    void on_ReadingTests_clicked();

    void on_actionSelect_all_triggered();
    void on_actionClear_All_triggered();
    void on_RunTests_clicked();

private:
    Ui::MainWindow *ui;
    bool isOneTest{};
    std::vector<const char*> testsVector{};
    std::vector<uint8_t> testCodeVector{};
    std::vector<QColor> testColorVector{};
    std::vector<uint8_t> testFocusVector{};
    ColorTest *colorTest = nullptr;
    GridTest *gridTest = nullptr;
    ReadTest *readTest = nullptr;

private:
    void addSelectedColorTests();
    void addSelectedGridTests();
    void addReadTests();
    void addCalibrationTests();
    uint8_t getFirstCodeElement();
    QColor getFirstColorElement();
};

#endif // MAINWINDOW_H
