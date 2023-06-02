
#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QAction>
#include <QCheckBox>
#include <QCoreApplication>
#include <QKeyEvent>
#include <QList>
#include <QMessageBox>
#include <QScreen>
#include <QWidget>

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
        if (ui->stackedWidget->currentIndex() == 0) {
            cf_test = new CalibrationFocusTest();
            cf_test->setTestCodeVector(getCodeVector());
            cf_test->setTestFocusVector(getFocusVector());
            cf_test->setUpTest();
            cf_test->showFullScreen();
        } else if (ui->stackedWidget->currentIndex() == 1) {
            gridTest = new GridTest();
            gridTest->setTestCodeVector(getCodeVector());
            gridTest->setTestColorVector(getColorVector());
            gridTest->setFirstGrid(gridTest->getFirstColor());
            gridTest->showFullScreen();
        } else if (ui->stackedWidget->currentIndex() == 2) {
            colorTest = new ColorTest();
            colorTest->setVectorValues(getVector());
            colorTest->setCodeVector(getCodeVector());
            colorTest->setColorVector(getColorVector());
            colorTest->showFullScreen();
        } else if (ui->stackedWidget->currentIndex() == 3) {
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

std::vector<uint8_t> MainWindow::getFocusVector()
{
    return testFocusVector;
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

void MainWindow::clearAllCheckBoxes()
{
    for (int i = 0; i < ui->stackedWidget->count(); i++) {
        QList<QCheckBox *> checkBoxes = ui->stackedWidget->widget(i)->findChildren<QCheckBox *>();
        for (int j = 0; j < checkBoxes.count(); j++) {
            checkBoxes.at(j)->setChecked(false);
        }
    }
}

void MainWindow::on_actionClear_All_triggered()
{
    clearAllCheckBoxes();
}


void MainWindow::on_RunTests_clicked()
{
    isOneTest = true;

    if (ui->stackedWidget->currentIndex() == 0)
        addCalibrationTests();

    if (ui->stackedWidget->currentIndex() == 1)
        addSelectedGridTests();

    if(ui->stackedWidget->currentIndex() == 2)
        addSelectedColorTests();

    if(ui->stackedWidget->currentIndex() == 3)
        addReadTests();

    if (!testCodeVector.empty())
        createTestWindow();
}

void MainWindow::addSelectedColorTests()
{
    clearAllVectors();

    //Solid Tests
    if(ui->Red->isChecked()){
        testsVector.push_back("background-color: #FF0000;");
        testCodeVector.push_back(4);
        testColorVector.push_back(Qt::white);
    }
    if(ui->Green->isChecked()){
        testsVector.push_back("background-color: #00FF00;");
        testCodeVector.push_back(4);
        testColorVector.push_back(Qt::white);
    }
    if(ui->Blue->isChecked()){
        testsVector.push_back("background-color: #0000FF;");
        testCodeVector.push_back(4);
        testColorVector.push_back(Qt::white);
    }
    if(ui->Orange->isChecked()){
        testsVector.push_back("background-color: #FFB400;");
        testCodeVector.push_back(4);
        testColorVector.push_back(Qt::white);
    }
    if(ui->White->isChecked()){
        testsVector.push_back("background-color: #FFFFFF;");
        testCodeVector.push_back(4);
        testColorVector.push_back(Qt::white);
    }
    if(ui->Black->isChecked()){
        testsVector.push_back("background-color: #000000;");
        testCodeVector.push_back(4);
        testColorVector.push_back(Qt::white);
    }
    if(ui->Gray50->isChecked()){
        testsVector.push_back("background-color: #7F7F7F;");
        testCodeVector.push_back(4);
        testColorVector.push_back(Qt::white);
    }

    //Gradient
    if(ui->RedGradient->isChecked()){
        testsVector.push_back("background-color: #FF0000;");
        testCodeVector.push_back(5);
        testColorVector.push_back(QColor("#FF0000"));
    }

    if(ui->GreenGradient->isChecked()){
        testsVector.push_back("background-color: #FF0000;");
        testCodeVector.push_back(5);
        testColorVector.push_back(QColor("#00FF00"));
    }

    if(ui->BlueGradient->isChecked()){
        testsVector.push_back("background-color: #FF0000;");
        testCodeVector.push_back(5);
        testColorVector.push_back(QColor("#0000FF"));
    }

    if(ui->OrangeGradient->isChecked()){
        testsVector.push_back("background-color: #FF0000;");
        testCodeVector.push_back(5);
        testColorVector.push_back(QColor("#FFB400"));
    }

    if(ui->GrayGradient->isChecked()){
        testsVector.push_back("background-color: #FF0000;");
        testCodeVector.push_back(5);
        testColorVector.push_back(Qt::gray);
    }

    //ColorPallet
    if(ui->ColorPalette->isChecked()){
        testsVector.push_back("background-color: #FF0000;");
        testColorVector.push_back(Qt::black);
        testCodeVector.push_back(6);
    }
    if(ui->ColorPalette180->isChecked()){
        testsVector.push_back("background-color: #FF0000;");
        testColorVector.push_back(Qt::black);
        testCodeVector.push_back(7);
    }
}

void MainWindow::addSelectedGridTests()
{
    clearAllVectors();

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
    clearAllVectors();

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

void MainWindow::addCalibrationTests()
{
    clearAllVectors();

    //Calibration test
    if (ui->LCDCalibration->isChecked()) {
        testFocusVector.push_back(4);
        testCodeVector.push_back(1);
    }

    if (ui->Brightness->isChecked()) {
        testFocusVector.push_back(5);
        testCodeVector.push_back(1);
    }

    if (ui->Scope->isChecked()) {
        testFocusVector.push_back(11);
        testCodeVector.push_back(1);
    }

    if (ui->Gamma->isChecked()) {
        testFocusVector.push_back(6);
        testCodeVector.push_back(1);
    }
    if (ui->Convergence->isChecked()) {
        testFocusVector.push_back(12);
        testCodeVector.push_back(1);
    }
    if (ui->ScreenSize->isChecked()) {
        testFocusVector.push_back(10);
        testCodeVector.push_back(1);
    }

    //Focus test
    if(ui->WhitePattern->isChecked()){
        testFocusVector.push_back(7);
        testCodeVector.push_back(1);
    }
    if(ui->BlackPattern->isChecked()){
        testFocusVector.push_back(8);
        testCodeVector.push_back(1);
    }
    if(ui->Sharpness->isChecked()){
        testFocusVector.push_back(9);
        testCodeVector.push_back(1);
    }
    if(ui->Dots->isChecked()){
        // Dots
        testFocusVector.push_back(1);
        testCodeVector.push_back(1);
    }
    if(ui->VerticalLines->isChecked()){
        // Vertical lines
        testFocusVector.push_back(2);
        testCodeVector.push_back(1);
    }
    if(ui->HorisontalLines->isChecked()){
        // Horisontal lines
        testFocusVector.push_back(3);
        testCodeVector.push_back(1);
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

void MainWindow::clearAllVectors()
{
    if (!testsVector.empty())
        testsVector.clear();
    if (!testCodeVector.empty())
        testCodeVector.clear();
    if (!testColorVector.empty())
        testColorVector.clear();
    if (!testFocusVector.empty())
        testFocusVector.clear();
}

void MainWindow::on_actionTests_for_LCD_monitors_triggered()
{
    clearAllCheckBoxes();
    ui->LCDCalibration->setChecked(true);
    ui->Brightness->setChecked(true);
    ui->Scope->setChecked(true);
    ui->Gamma->setChecked(true);
    ui->ScreenSize->setChecked(true);
    ui->Sharpness->setChecked(true);
    ui->Dots->setChecked(true);
    ui->MagentaGrid->setChecked(true);
    ui->MagentaGridBlack->setChecked(true);
    ui->YellowGridBlack->setChecked(true);
    ui->YellowGrid->setChecked(true);
    ui->Red->setChecked(true);
    ui->Green->setChecked(true);
    ui->Blue->setChecked(true);
    ui->Orange->setChecked(true);
    ui->White->setChecked(true);
    ui->Black->setChecked(true);
    ui->Gray50->setChecked(true);
    ui->RedGradient->setChecked(true);
    ui->GreenGradient->setChecked(true);
    ui->BlueGradient->setChecked(true);
    ui->OrangeGradient->setChecked(true);
    ui->GrayGradient->setChecked(true);
    ui->ColorPalette->setChecked(true);
    ui->ColorPalette180->setChecked(true);
    ui->WhiteText->setChecked(true);
    ui->BlackText->setChecked(true);
    ui->RedText->setChecked(true);
    ui->BlueText->setChecked(true);
    ui->MagentaText->setChecked(true);
    ui->YellowText->setChecked(true);
}

void MainWindow::on_actionPreferences_triggered() {}

void MainWindow::on_actionExit_triggered()
{
    this->close();
}
