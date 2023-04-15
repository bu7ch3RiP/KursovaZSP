
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
    if(isOneTest){
        if(ui->stackedWidget->currentIndex() == 1){
            gridTest = new GridWidget();
            gridTest->setTestCodeVector(getCodeVector());
            gridTest->setTestColorVector(getColorVector());
            gridTest->setColor(gridTest->getFirstColor());
            gridTest->showFullScreen();
        }else if (ui->stackedWidget->currentIndex() == 2){
            colorTest = new ColorTest();
            colorTest->setVectorValues(getVector());
            colorTest->setCodeVector(getCodeVector());
            colorTest->setColorVector(getColorVector());
            colorTest->showFullScreen();
        }else if (ui->stackedWidget->currentIndex() == 3){
            readTest = new ReadTest();
            readTest->setTestCodeVector(getCodeVector());
            readTest->setTestColorVector(getColorVector());
            readTest->setColor(readTest->getFirstColor());
            readTest->showFullScreen();
        }
    }

    switch(getFirstCodeElement()){

    case 2:
        break;
    case 3:
        break;
    case 4:
        colorTest->setStyleSheet(colorTest->getFirstElement());
        break;
    case 5:
        colorTest->GradientTest(getFirstColorElement());
        break;
    case 6:
        colorTest->paletteTest(":/color/palette/pictures/Palette.png");
        break;
    case 7:
        colorTest->paletteTest(":/color/palette/pictures/Palette180.png");
        break;
    case 8:
        break;
    }
    // Показ вікна на повний екран
    //newWindow->showFullScreen();

    //newWindow->resize(400, 400);
    //newWindow->show();
}


std::vector<uint8_t> MainWindow::getCodeVector(){return testCodeVector;}
std::vector<QColor> MainWindow::getColorVector(){return testColorVector;}

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

    isOneTest = true;

    if(ui->stackedWidget->currentIndex() == 1)
        addSelectedGridTests();

    if(ui->stackedWidget->currentIndex() == 2)
        addSelectedColorTests();

    if(ui->stackedWidget->currentIndex() == 3)
        addReadTests();

    //if(testsVector.empty()){
        //to do qmessageBox not selected test
        //return;
    //}
    createTestWindow();
}

void MainWindow::addSelectedColorTests()
{

    if(!testCodeVector.empty())
        testCodeVector.clear();

    if(!testColorVector.empty())
        testColorVector.clear();

    if(!testsVector.empty())
        testsVector.clear();

    //Solid Tests
    if(ui->Red->isChecked()){
        testsVector.push_back("background-color: #FF0000;");
        testCodeVector.push_back(4);
    }
    if(ui->Green->isChecked()){
        testsVector.push_back("background-color: #00FF00;");
        testCodeVector.push_back(4);
    }
    if(ui->Blue->isChecked()){
        testsVector.push_back("background-color: #0000FF;");
        testCodeVector.push_back(4);
    }
    if(ui->Orange->isChecked()){
        testsVector.push_back("background-color: #FFB400;");
        testCodeVector.push_back(4);
    }
    if(ui->White->isChecked()){
        testsVector.push_back("background-color: #FFFFFF;");
        testCodeVector.push_back(4);
    }
    if(ui->Black->isChecked()){
        testsVector.push_back("background-color: #000000;");
        testCodeVector.push_back(4);
    }
    if(ui->Gray50->isChecked()){
        testsVector.push_back("background-color: #7F7F7F;");
        testCodeVector.push_back(4);
    }

    //Gradient
    if(ui->RedGradient->isChecked()){
        testCodeVector.push_back(5);
        testColorVector.push_back(QColor("#FF0000"));
    }

    if(ui->GreenGradient->isChecked()){
        testCodeVector.push_back(5);
        testColorVector.push_back(QColor("#00FF00"));
    }

    if(ui->BlueGradient->isChecked()){
        testCodeVector.push_back(5);
        testColorVector.push_back(QColor("#0000FF"));
    }

    if(ui->OrangeGradient->isChecked()){
        testCodeVector.push_back(5);
        testColorVector.push_back(QColor("#FFB400"));
    }

    if(ui->GrayGradient->isChecked()){
        testCodeVector.push_back(5);
        testColorVector.push_back(Qt::gray);
    }

    //ColorPallet
    if(ui->ColorPalette->isChecked()){
        testCodeVector.push_back(6);
    }
    if(ui->ColorPalette180->isChecked()){
        testCodeVector.push_back(7);
    }
}

void MainWindow::addSelectedGridTests()
{
    if(!testCodeVector.empty())
        testCodeVector.clear();

    if(!testColorVector.empty())
        testColorVector.clear();

    //White background
    if(ui->BlackGrid->isChecked())
    {
        testCodeVector.push_back(3);
        testColorVector.push_back(Qt::black);
    }

    if(ui->RedGridBlack->isChecked())
    {
        testCodeVector.push_back(3);
        testColorVector.push_back(Qt::red);
    }

    if(ui->GreenGridBlack->isChecked())
    {
        testCodeVector.push_back(3);
        testColorVector.push_back(Qt::green);
    }

    if(ui->BlueGridBlack->isChecked())
    {
        testCodeVector.push_back(3);
        testColorVector.push_back(Qt::blue);
    }

    if(ui->MagentaGridBlack->isChecked())
    {
        testCodeVector.push_back(3);
        testColorVector.push_back(Qt::magenta);
    }

    if(ui->YellowGridBlack->isChecked())
    {
        testCodeVector.push_back(3);
        testColorVector.push_back(Qt::yellow);
    }

    //Black background 2

    if(ui->WhiteGrid->isChecked()){
        testCodeVector.push_back(2);
        testColorVector.push_back(Qt::white);
    }

    if(ui->RedGrid->isChecked()){
        testCodeVector.push_back(2);
        testColorVector.push_back(Qt::red);
    }

    if(ui->GreenGrid->isChecked()){
        testCodeVector.push_back(2);
        testColorVector.push_back(Qt::green);
    }

    if(ui->BlueGrid->isChecked()){
        testCodeVector.push_back(2);
        testColorVector.push_back(Qt::blue);
    }

    if(ui->MagentaGrid->isChecked()){
        testCodeVector.push_back(2);
        testColorVector.push_back(Qt::magenta);
    }

    if(ui->YellowGrid->isChecked()){
        testCodeVector.push_back(2);
        testColorVector.push_back(Qt::yellow);
    }

}

void MainWindow::addReadTests()
{
    if(!testCodeVector.empty())
        testCodeVector.clear();

    if(!testColorVector.empty())
        testColorVector.clear();

    if(ui->WhiteText->isChecked()){
        testCodeVector.push_back(8);
        testColorVector.push_back(Qt::white);
    }

    if(ui->BlackText->isChecked()){
        testCodeVector.push_back(8);
        testColorVector.push_back(Qt::black);
    }

    if(ui->RedText->isChecked()){
        testCodeVector.push_back(8);
        testColorVector.push_back(Qt::red);
    }

    if(ui->BlueText->isChecked()){
        testCodeVector.push_back(8);
        testColorVector.push_back(Qt::blue);
    }

    if(ui->MagentaText->isChecked()){
        testCodeVector.push_back(8);
        testColorVector.push_back(Qt::magenta);
    }

    if(ui->YellowText->isChecked()){
        testCodeVector.push_back(8);
        testColorVector.push_back(Qt::yellow);
    }

}

uint8_t MainWindow::getFirstCodeElement()
{
    return testCodeVector[0];
}

QColor MainWindow::getFirstColorElement()
{
    return testColorVector[0];
}



