
#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QList>
#include <QCheckBox>
#include <QAction>
#include <QWidget>
#include <QScreen>
#include <QKeyEvent>



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

void MainWindow::createTestWindow()
{
    // Створення нового вікна
    //TestWindow *newWindow = new TestWindow();
    newWindow = new TestWindow();
    newWindow->setVectorValues(getVector());
    newWindow->setStyleSheet(newWindow->getFirstElement());
    // Показ вікна на повний екран
    newWindow->showFullScreen();

    //newWindow->resize(400, 400);
    //newWindow->show();
}

std::vector<const char *> MainWindow::getVector()
{
    return testsVector;
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
    //createTestWindow("background-color: blue;");
    if(ui->stackedWidget->currentIndex() == 2)
        addSelectedColorTests();

    if(testsVector.empty()){
        //to do qmessageBox not selected test
        return;
    }
    createTestWindow();
}

void MainWindow::addSelectedColorTests()
{
    if(!testsVector.empty())
        testsVector.clear();

    if(ui->Red->isChecked())
        testsVector.push_back("background-color: #FF0000;");

    if(ui->Green->isChecked())
        testsVector.push_back("background-color: #00FF00;");

    if(ui->Blue->isChecked())
        testsVector.push_back("background-color: #0000FF;");

    if(ui->Orange->isChecked())
        testsVector.push_back("background-color: #FFB400;");

    if(ui->White->isChecked())
        testsVector.push_back("background-color: #FFFFFF;");

    if(ui->Black->isChecked())
        testsVector.push_back("background-color: #000000;");

    if(ui->Gray50->isChecked())
        testsVector.push_back("background-color: #7F7F7F;");
}



