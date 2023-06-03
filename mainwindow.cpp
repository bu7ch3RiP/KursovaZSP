
#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "about.h"
#include "language.h"
#include "preference.h"

#include <QAction>
#include <QCheckBox>
#include <QCoreApplication>
#include <QKeyEvent>
#include <QList>
#include <QMessageBox>
#include <QScreen>
#include <QWidget>
#include <unordered_map>

std::unordered_map<int, double> window_height_size_{{1080, 1.6},
                                                    {1050, 1.6},
                                                    {1024, 1.4},
                                                    {960, 1.3},
                                                    {900, 1.4},
                                                    {800, 1.2},
                                                    {768, 1.3},
                                                    {720, 1.15}};

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , auto_test_timeout_{4}
    , save_settings_{true}
    , isAutoTest{false}
    , language_state_{LanguageMode::kEN}
{
    ui->setupUi(this);
    setWindowTitle("Monitor testing");
    int width_window_size_ = ui->line->width() + 20;
    int height_ = QGuiApplication::primaryScreen()->geometry().height();
    double delta_height_ = window_height_size_.find(height_) != window_height_size_.end()
                               ? window_height_size_[height_]
                               : 1;
    this->setFixedSize(QSize(width_window_size_, height_ / delta_height_));
    ui->Lable1Hider->installEventFilter(this);
    ui->LHints->setText(language_state_ == LanguageMode::kEN ? page_hints_en[0] : page_hints_ua[0]);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::SetUALocalization()
{
    setWindowTitle(title_ua[0]);

    //bar menu
    ui->menuFile->setTitle(menu_ua[0]);
    ui->menuSelection->setTitle(menu_ua[1]);
    ui->menuHelp->setTitle(menu_ua[2]);
    ui->actionExit->setText(menu_ua[3]);
    ui->actionPreferences->setText(menu_ua[4]);
    ui->actionSelect_all->setText(menu_ua[5]);
    ui->actionClear_All->setText(menu_ua[6]);
    ui->actionTests_for_LCD_monitors->setText(menu_ua[7]);
    ui->actionAbout->setText(menu_ua[8]);
    ui->menuLanguage->setTitle(menu_ua[9]);
    ui->actionUkranian->setText(menu_ua[10]);
    ui->actionEnglish->setText(menu_ua[11]);

    //buttons
    ui->RunTests->setText(buttons_ua[0]);
    ui->RunTests->setGeometry(QRect(535, 430, 240, 30));

    ui->AutoRunTests->setText(buttons_ua[1]);
    ui->AutoRunTests->setGeometry(QRect(250, 430, 280, 30));

    ui->CalibrationTests->setText(buttons_ua[2]);
    ui->CalibrationTests->setGeometry(QRect(21, 11, 185, 34));

    ui->GridTests->setText(buttons_ua[3]);
    ui->GridTests->setGeometry(QRect(212, 11, 120, 34));

    ui->ColorTests->setText(buttons_ua[4]);
    ui->ColorTests->setGeometry(QRect(338, 11, 160, 34));

    ui->ReadingTests->setText(buttons_ua[5]);
    ui->ReadingTests->setGeometry(QRect(504, 11, 200, 34));

    //group boxes
    ui->groupBox->setTitle(group_box_ua[0]);
    ui->groupBox_2->setTitle(group_box_ua[1]);
    ui->groupBox_3->setTitle(group_box_ua[2]);
    ui->groupBox_4->setTitle(group_box_ua[3]);
    ui->groupBox_5->setTitle(group_box_ua[4]);
    ui->groupBox_6->setTitle(group_box_ua[5]);
    ui->groupBox_7->setTitle(group_box_ua[6]);
    ui->groupBox_8->setTitle(group_box_ua[7]);

    //lables
    ui->LCDCalibration->setText(lables_ua[0]);
    ui->Brightness->setText(lables_ua[1]);
    ui->Scope->setText(lables_ua[2]);
    ui->Gamma->setText(lables_ua[3]);
    ui->Convergence->setText(lables_ua[4]);
    ui->ScreenSize->setText(lables_ua[5]);
    ui->WhitePattern->setText(lables_ua[6]);
    ui->BlackPattern->setText(lables_ua[7]);
    ui->Sharpness->setText(lables_ua[8]);
    ui->Dots->setText(lables_ua[9]);
    ui->VerticalLines->setText(lables_ua[10]);
    ui->HorisontalLines->setText(lables_ua[11]);
    ui->WhiteGrid->setText(lables_ua[12]);
    ui->RedGrid->setText(lables_ua[13]);
    ui->GreenGrid->setText(lables_ua[14]);
    ui->BlueGrid->setText(lables_ua[15]);
    ui->MagentaGrid->setText(lables_ua[16]);
    ui->YellowGrid->setText(lables_ua[17]);
    ui->BlackGrid->setText(lables_ua[18]);
    ui->RedGridBlack->setText(lables_ua[19]);
    ui->GreenGridBlack->setText(lables_ua[20]);
    ui->BlueGridBlack->setText(lables_ua[21]);
    ui->MagentaGridBlack->setText(lables_ua[22]);
    ui->YellowGridBlack->setText(lables_ua[23]);
    ui->Red->setText(lables_ua[24]);
    ui->Green->setText(lables_ua[25]);
    ui->Blue->setText(lables_ua[26]);
    ui->Orange->setText(lables_ua[27]);
    ui->White->setText(lables_ua[28]);
    ui->Black->setText(lables_ua[29]);
    ui->Gray50->setText(lables_ua[30]);
    ui->RedGradient->setText(lables_ua[31]);
    ui->GreenGradient->setText(lables_ua[32]);
    ui->BlueGradient->setText(lables_ua[33]);
    ui->OrangeGradient->setText(lables_ua[34]);
    ui->GrayGradient->setText(lables_ua[35]);
    ui->ColorPalette->setText(lables_ua[36]);
    ui->ColorPalette180->setText(lables_ua[37]);
    ui->WhiteText->setText(lables_ua[38]);
    ui->BlackText->setText(lables_ua[39]);
    ui->RedText->setText(lables_ua[40]);
    ui->BlueText->setText(lables_ua[41]);
    ui->MagentaText->setText(lables_ua[42]);
    ui->YellowText->setText(lables_ua[43]);

    ui->groupBox_8->setGeometry(409, 30, 290, 251);

    QFont lable_font_("Segoe UI", 12);
    ui->LCDCalibration->setFont(lable_font_);
    ui->Brightness->setFont(lable_font_);
    ui->Scope->setFont(lable_font_);
    ui->Gamma->setFont(lable_font_);
    ui->Convergence->setFont(lable_font_);
    ui->ScreenSize->setFont(lable_font_);
    ui->WhitePattern->setFont(lable_font_);
    ui->BlackPattern->setFont(lable_font_);
    ui->Sharpness->setFont(lable_font_);
    ui->Dots->setFont(lable_font_);
    ui->VerticalLines->setFont(lable_font_);
    ui->HorisontalLines->setFont(lable_font_);
    ui->WhiteGrid->setFont(lable_font_);
    ui->RedGrid->setFont(lable_font_);
    ui->GreenGrid->setFont(lable_font_);
    ui->BlueGrid->setFont(lable_font_);
    ui->MagentaGrid->setFont(lable_font_);
    ui->YellowGrid->setFont(lable_font_);
    ui->BlackGrid->setFont(lable_font_);
    ui->RedGridBlack->setFont(lable_font_);
    ui->GreenGridBlack->setFont(lable_font_);
    ui->BlueGridBlack->setFont(lable_font_);
    ui->MagentaGridBlack->setFont(lable_font_);
    ui->YellowGridBlack->setFont(lable_font_);
    ui->Red->setFont(lable_font_);
    ui->Green->setFont(lable_font_);
    ui->Blue->setFont(lable_font_);
    ui->Orange->setFont(lable_font_);
    ui->White->setFont(lable_font_);
    ui->Black->setFont(lable_font_);
    ui->Gray50->setFont(lable_font_);
    ui->RedGradient->setFont(lable_font_);
    ui->GreenGradient->setFont(lable_font_);
    ui->BlueGradient->setFont(lable_font_);
    ui->OrangeGradient->setFont(lable_font_);
    ui->GrayGradient->setFont(lable_font_);
    ui->ColorPalette->setFont(lable_font_);
    ui->ColorPalette180->setFont(lable_font_);
    ui->WhiteText->setFont(lable_font_);
    ui->BlackText->setFont(lable_font_);
    ui->RedText->setFont(lable_font_);
    ui->BlueText->setFont(lable_font_);
    ui->MagentaText->setFont(lable_font_);
    ui->YellowText->setFont(lable_font_);

    ui->LHints->setText(page_hints_ua[ui->stackedWidget->currentIndex()]);
}

void MainWindow::SetENLocalization()
{
    setWindowTitle(title_en[0]);
    //bar menu
    ui->menuFile->setTitle(menu_en[0]);
    ui->menuSelection->setTitle(menu_en[1]);
    ui->menuHelp->setTitle(menu_en[2]);
    ui->actionExit->setText(menu_en[3]);
    ui->actionPreferences->setText(menu_en[4]);
    ui->actionSelect_all->setText(menu_en[5]);
    ui->actionClear_All->setText(menu_en[6]);
    ui->actionTests_for_LCD_monitors->setText(menu_en[7]);
    ui->actionAbout->setText(menu_en[8]);
    ui->menuLanguage->setTitle(menu_en[9]);
    ui->actionUkranian->setText(menu_en[10]);
    ui->actionEnglish->setText(menu_en[11]);

    //buttons
    ui->RunTests->setText(buttons_en[0]);
    ui->RunTests->setGeometry(QRect(600, 430, 165, 30));

    ui->AutoRunTests->setText(buttons_en[1]);
    ui->AutoRunTests->setGeometry(QRect(374, 430, 211, 30));

    ui->CalibrationTests->setText(buttons_en[2]);
    ui->CalibrationTests->setGeometry(QRect(21, 11, 144, 34));

    ui->GridTests->setText(buttons_en[3]);
    ui->GridTests->setGeometry(QRect(171, 11, 87, 34));

    ui->ColorTests->setText(buttons_en[4]);
    ui->ColorTests->setGeometry(QRect(264, 11, 97, 34));

    ui->ReadingTests->setText(buttons_en[5]);
    ui->ReadingTests->setGeometry(QRect(367, 11, 119, 34));

    //group boxes
    ui->groupBox->setTitle(group_box_en[0]);
    ui->groupBox_2->setTitle(group_box_en[1]);
    ui->groupBox_3->setTitle(group_box_en[2]);
    ui->groupBox_4->setTitle(group_box_en[3]);
    ui->groupBox_5->setTitle(group_box_en[4]);
    ui->groupBox_6->setTitle(group_box_en[5]);
    ui->groupBox_7->setTitle(group_box_en[6]);
    ui->groupBox_8->setTitle(group_box_en[7]);

    //lables
    ui->LCDCalibration->setText(lables_en[0]);
    ui->Brightness->setText(lables_en[1]);
    ui->Scope->setText(lables_en[2]);
    ui->Gamma->setText(lables_en[3]);
    ui->Convergence->setText(lables_en[4]);
    ui->ScreenSize->setText(lables_en[5]);
    ui->WhitePattern->setText(lables_en[6]);
    ui->BlackPattern->setText(lables_en[7]);
    ui->Sharpness->setText(lables_en[8]);
    ui->Dots->setText(lables_en[9]);
    ui->VerticalLines->setText(lables_en[10]);
    ui->HorisontalLines->setText(lables_en[11]);
    ui->WhiteGrid->setText(lables_en[12]);
    ui->RedGrid->setText(lables_en[13]);
    ui->GreenGrid->setText(lables_en[14]);
    ui->BlueGrid->setText(lables_en[15]);
    ui->MagentaGrid->setText(lables_en[16]);
    ui->YellowGrid->setText(lables_en[17]);
    ui->BlackGrid->setText(lables_en[18]);
    ui->RedGridBlack->setText(lables_en[19]);
    ui->GreenGridBlack->setText(lables_en[20]);
    ui->BlueGridBlack->setText(lables_en[21]);
    ui->MagentaGridBlack->setText(lables_en[22]);
    ui->YellowGridBlack->setText(lables_en[23]);
    ui->Red->setText(lables_en[24]);
    ui->Green->setText(lables_en[25]);
    ui->Blue->setText(lables_en[26]);
    ui->Orange->setText(lables_en[27]);
    ui->White->setText(lables_en[28]);
    ui->Black->setText(lables_en[29]);
    ui->Gray50->setText(lables_en[30]);
    ui->RedGradient->setText(lables_en[31]);
    ui->GreenGradient->setText(lables_en[32]);
    ui->BlueGradient->setText(lables_en[33]);
    ui->OrangeGradient->setText(lables_en[34]);
    ui->GrayGradient->setText(lables_en[35]);
    ui->ColorPalette->setText(lables_en[36]);
    ui->ColorPalette180->setText(lables_en[37]);
    ui->WhiteText->setText(lables_en[38]);
    ui->BlackText->setText(lables_en[39]);
    ui->RedText->setText(lables_en[40]);
    ui->BlueText->setText(lables_en[41]);
    ui->MagentaText->setText(lables_en[42]);
    ui->YellowText->setText(lables_en[43]);

    ui->groupBox_8->setGeometry(409, 30, 231, 251);

    QFont lable_font_("Segoe UI", 14);
    ui->LCDCalibration->setFont(lable_font_);
    ui->Brightness->setFont(lable_font_);
    ui->Scope->setFont(lable_font_);
    ui->Gamma->setFont(lable_font_);
    ui->Convergence->setFont(lable_font_);
    ui->ScreenSize->setFont(lable_font_);
    ui->WhitePattern->setFont(lable_font_);
    ui->BlackPattern->setFont(lable_font_);
    ui->Sharpness->setFont(lable_font_);
    ui->Dots->setFont(lable_font_);
    ui->VerticalLines->setFont(lable_font_);
    ui->HorisontalLines->setFont(lable_font_);
    ui->WhiteGrid->setFont(lable_font_);
    ui->RedGrid->setFont(lable_font_);
    ui->GreenGrid->setFont(lable_font_);
    ui->BlueGrid->setFont(lable_font_);
    ui->MagentaGrid->setFont(lable_font_);
    ui->YellowGrid->setFont(lable_font_);
    ui->BlackGrid->setFont(lable_font_);
    ui->RedGridBlack->setFont(lable_font_);
    ui->GreenGridBlack->setFont(lable_font_);
    ui->BlueGridBlack->setFont(lable_font_);
    ui->MagentaGridBlack->setFont(lable_font_);
    ui->YellowGridBlack->setFont(lable_font_);
    ui->Red->setFont(lable_font_);
    ui->Green->setFont(lable_font_);
    ui->Blue->setFont(lable_font_);
    ui->Orange->setFont(lable_font_);
    ui->White->setFont(lable_font_);
    ui->Black->setFont(lable_font_);
    ui->Gray50->setFont(lable_font_);
    ui->RedGradient->setFont(lable_font_);
    ui->GreenGradient->setFont(lable_font_);
    ui->BlueGradient->setFont(lable_font_);
    ui->OrangeGradient->setFont(lable_font_);
    ui->GrayGradient->setFont(lable_font_);
    ui->ColorPalette->setFont(lable_font_);
    ui->ColorPalette180->setFont(lable_font_);
    ui->WhiteText->setFont(lable_font_);
    ui->BlackText->setFont(lable_font_);
    ui->RedText->setFont(lable_font_);
    ui->BlueText->setFont(lable_font_);
    ui->MagentaText->setFont(lable_font_);
    ui->YellowText->setFont(lable_font_);

    ui->LHints->setText(page_hints_en[ui->stackedWidget->currentIndex()]);
}

void MainWindow::createTestWindow()
{
    if (ui->stackedWidget->currentIndex() == 0) {
        cf_test = new CalibrationFocusTest(isAutoTest, auto_test_timeout_);
        cf_test->setTestCodeVector(getCodeVector());
        cf_test->setTestFocusVector(getFocusVector());
        cf_test->setUpTest();
        cf_test->showFullScreen();
    } else if (ui->stackedWidget->currentIndex() == 1) {
        gridTest = new GridTest(isAutoTest, auto_test_timeout_);
        gridTest->setTestCodeVector(getCodeVector());
        gridTest->setTestColorVector(getColorVector());
        gridTest->setFirstGrid(gridTest->getFirstColor());
        gridTest->showFullScreen();
    } else if (ui->stackedWidget->currentIndex() == 2) {
        colorTest = new ColorTest(isAutoTest, auto_test_timeout_);
        colorTest->setVectorValues(getVector());
        colorTest->setCodeVector(getCodeVector());
        colorTest->setColorVector(getColorVector());
        colorTest->showFullScreen();
    } else if (ui->stackedWidget->currentIndex() == 3) {
        readTest = new ReadTest(isAutoTest, auto_test_timeout_);
        readTest->setTestCodeVector(getCodeVector());
        readTest->setTestColorVector(getColorVector());
        readTest->setColor(readTest->getFirstColor());
        readTest->showFullScreen();
    }

    switch (getFirstCodeElement()) {
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
}

std::vector<uint8_t> MainWindow::getCodeVector()
{
    return testCodeVector;
}
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
    ui->LHints->setText(language_state_ == LanguageMode::kEN ? page_hints_en[0] : page_hints_ua[0]);
}


void MainWindow::on_GridTests_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    ui->LHints->setText(language_state_ == LanguageMode::kEN ? page_hints_en[1] : page_hints_ua[1]);
}


void MainWindow::on_ColorTests_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
    ui->LHints->setText(language_state_ == LanguageMode::kEN ? page_hints_en[2] : page_hints_ua[2]);
}


void MainWindow::on_ReadingTests_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
    ui->LHints->setText(language_state_ == LanguageMode::kEN ? page_hints_en[3] : page_hints_ua[3]);
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
    isAutoTest = false;
    checkSelectedTests();
}

void MainWindow::on_AutoRunTests_clicked()
{
    isAutoTest = true;
    checkSelectedTests();
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

void MainWindow::checkSelectedTests()
{
    if (ui->stackedWidget->currentIndex() == 0)
        addCalibrationTests();

    if (ui->stackedWidget->currentIndex() == 1)
        addSelectedGridTests();

    if (ui->stackedWidget->currentIndex() == 2)
        addSelectedColorTests();

    if (ui->stackedWidget->currentIndex() == 3)
        addReadTests();

    if (!testCodeVector.empty())
        createTestWindow();
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

void MainWindow::on_actionPreferences_triggered()
{
    if (preference == nullptr) {
        preference = new Preference(auto_test_timeout_,
                                    save_settings_,
                                    language_state_ == LanguageMode::kEN ? true : false);
        connect(preference,
                &Preference::preferenceClosed,
                this,
                &MainWindow::handlePreferenceClosed);
    }

    preference->show();
    preference->exec();

    if (preference != nullptr) {
        delete preference;
        preference = nullptr;
    }
}

bool MainWindow::eventFilter(QObject *obj, QEvent *event)
{
    if (obj == (QObject *) ui->Lable1Hider) {
        if (event->type() == QEvent::Enter) {
            ui->LHints->setText("Here loh\n");
        } else if (event->type() == QEvent::Leave) {
            ui->LHints->setText("Here ne loh\n");
        }
        return true;
    } else {
        // pass the event on to the parent class
        return QWidget::eventFilter(obj, event);
    }
}

void MainWindow::on_actionExit_triggered()
{
    this->close();
}

void MainWindow::handlePreferenceClosed()
{
    //Here must be saving :)
}

void MainWindow::on_actionAbout_triggered()
{
    if (about == nullptr) {
        about = new About(language_state_ == LanguageMode::kEN ? true : false);
    }

    about->show();
    about->exec();

    if (about != nullptr) {
        delete about;
        about = nullptr;
    }
}

void MainWindow::on_actionUkranian_triggered()
{
    if (language_state_ == LanguageMode::kUA)
        return;
    SetUALocalization();
    language_state_ = LanguageMode::kUA;
}

void MainWindow::on_actionEnglish_triggered()
{
    if (language_state_ == LanguageMode::kEN)
        return;
    SetENLocalization();
    language_state_ = LanguageMode::kEN;
}
