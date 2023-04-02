
#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "testwindow.h"

#include <QList>
#include <QCheckBox>
#include <QAction>
#include <QWidget>
#include <QScreen>



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::createTestWindow(const char *str)
{
    // Створення нового вікна
    TestWindow *newWindow = new TestWindow();
    newWindow->setStyleSheet(str);
    // Показ вікна на повний екран
    newWindow->showFullScreen();
}



void MainWindow::on_CalibrationTests_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);

}


void MainWindow::on_GridTests_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_ColorTests_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}


void MainWindow::on_ReadingTests_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}


void MainWindow::on_actionSelect_all_triggered()
{
    for (int i = 0; i < ui->stackedWidget->count(); i++)
    {
        QList<QCheckBox*> checkBoxes = ui->stackedWidget->widget(i)->findChildren<QCheckBox*>();
        for (int j = 0; j < checkBoxes.count(); j++)
        {
            checkBoxes.at(j)->setChecked(true);
        }
    }
}


void MainWindow::on_actionClear_All_triggered()
{
    for (int i = 0; i < ui->stackedWidget->count(); i++)
    {
        QList<QCheckBox*> checkBoxes = ui->stackedWidget->widget(i)->findChildren<QCheckBox*>();
        for (int j = 0; j < checkBoxes.count(); j++)
        {
            checkBoxes.at(j)->setChecked(false);
        }
    }
}


void MainWindow::on_RunTests_clicked()
{
    createTestWindow("background-color: blue;");
}

