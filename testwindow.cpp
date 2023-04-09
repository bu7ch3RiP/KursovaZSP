#include "testwindow.h"
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

TestWindow::TestWindow(QWidget *parent)
    : QWidget{parent}
{
    // Створення кнопки "Повернутися"
    QPushButton *backButton = new QPushButton("X", this);
    backButton->setStyleSheet("background-color: #ff00ff;");
    connect(backButton, &QPushButton::clicked, this, &QWidget::close);

    // Розміщення кнопки на вікні
    QScreen *screen = QGuiApplication::primaryScreen();
    backButton->setGeometry(QRect(QPoint(screen->geometry().width()-35, 5), QSize(30, 30)));

    index_ = 0;
    setFocusPolicy( Qt::StrongFocus );
}

void TestWindow::setVectorValues(std::vector<const char *> v)
{
    this->testsVector = v;
}

void TestWindow::setCodeVector(std::vector<uint8_t> v){
    this->testCodeVector = v;
}

void TestWindow::setColorVector(std::vector<QColor> v){
    this->testColorVector = v;
}

const char *TestWindow::getFirstElement()
{
    return testsVector[0];
}

void TestWindow::paletteTest(const char *path)
{
    // Create a new widget
    QScreen *screen = QGuiApplication::primaryScreen();
    // Load the image to be displayed
    QPixmap pixmap(path);

    // Create a label to hold the image
    QLabel *label = new QLabel(this);
    label->setPixmap(pixmap);

    // Resize the label to fill the widget
    label->setFixedHeight(screen->geometry().height());
    label->setFixedWidth(screen->geometry().width());

    //label->setScaledContents(true);

    // Set the widget to be the top-level widget and display it in full screen
    //setWindowFlags(Qt::Window | Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);

}

void TestWindow::deleteAllWidgets()
{
    QLayoutItem* child;
    while ((child = layout()->takeAt(0)) != nullptr) {
        delete child->widget();
        delete child;
    }
}

void TestWindow::GradientTest(QColor color)
{
    QScreen *screen = QGuiApplication::primaryScreen();
    QLinearGradient gradient(0, 0, screen->geometry().width(), screen->geometry().height());
    gradient.setColorAt(0, Qt::black);
    gradient.setColorAt(1, color);

    // Set the widget's background to the gradient
    setAutoFillBackground(true);
    QPalette pal = palette();
    pal.setBrush(backgroundRole(), QBrush(gradient));
    setPalette(pal);
}

void TestWindow::keyPressEvent(QKeyEvent *event)
{
    switch (event->key()) {
    case Qt::Key_Left:
        index_ = (index_ - 1 + testCodeVector.size()) % testCodeVector.size();
        if(testCodeVector[index_] == 4)
            setStyleSheet(testsVector[index_]);
        if(testCodeVector[index_] == 5)
            GradientTest(testColorVector[index_]);
        if(testCodeVector[index_] == 6){
            paletteTest(":/color/palette/pictures/Palette.png");
        }
        if(testCodeVector[index_] == 7){
            paletteTest(":/color/palette/pictures/Palette180.png");
        }
        break;
    case Qt::Key_Right:
        index_ = (index_ + 1) % testCodeVector.size();
        if(testCodeVector[index_] == 4)
            this->setStyleSheet(testsVector[index_]);
        if(testCodeVector[index_] == 5)
            GradientTest(testColorVector[index_]);
        if(testCodeVector[index_] == 6){
            paletteTest(":/color/palette/pictures/Palette.png");
        }
        if(testCodeVector[index_] == 7){
            paletteTest(":/color/palette/pictures/Palette180.png");
        }
        break;
    default:
        QWidget::keyPressEvent(event);
        break;
    }
}

//void TestWindow::setImage(const QPixmap &pixmap)
//{
//    // Set background color to black
//    QPalette pal = palette();
//    pal.setColor(QPalette::Window, Qt::black);
//    setAutoFillBackground(true);
//    setPalette(pal);
//
//    // Scale image to fit the widget size
//    QPixmap scaledPixmap = pixmap.scaled(size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
//
//    // Set the image label
//    if (!imageLabel) {
//        imageLabel = new QLabel(this);
//    }
//    imageLabel->setPixmap(scaledPixmap);
//    imageLabel->setAlignment(Qt::AlignCenter);
//}



