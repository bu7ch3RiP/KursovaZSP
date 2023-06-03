#include "color_test.h"
#include <QGuiApplication>
#include <QKeyEvent>
#include <QLinearGradient>
#include <QPaintEvent>
#include <QPainter>
#include <QPixmap>
#include <QPushButton>
#include <QRect>
#include <QScreen>
#include <QTimer>
#include <QVBoxLayout>
#include <QtWidgets>

ColorTest::ColorTest(const bool &auto_test, const size_t &timeout, QWidget *parent)
    : QWidget{parent}
{
    label = nullptr;
    backButton = new QPushButton("X", this);
    backButton->setStyleSheet("background-color: #ff00ff;");
    connect(backButton, &QPushButton::clicked, this, &QWidget::close);

    screen = QGuiApplication::primaryScreen();

    backButton->setGeometry(QRect(QPoint(screen->geometry().width()-35, 5), QSize(30, 30)));

    index_ = 0;
    setFocusPolicy(Qt::StrongFocus);

    if (auto_test) {
        // Set up the QTimer to update the image every 4 seconds
        QTimer *timer = new QTimer(this);
        connect(timer, &QTimer::timeout, this, &ColorTest::updateImage);
        timer->start(timeout * 1000); // Change the image every 4 seconds
    }
}

void ColorTest::updateImage()
{
    // Create a QKeyEvent object for the right key press event
    QKeyEvent *event = new QKeyEvent(QKeyEvent::KeyPress, Qt::Key_Right, Qt::NoModifier);

    // Call the keyPressEvent function with the simulated event
    keyPressEvent(event);

    // Clean up the allocated event object
    delete event;
}

void ColorTest::setVectorValues(std::vector<const char *> v)
{
    this->testsVector = v;
}

void ColorTest::setCodeVector(std::vector<uint8_t> v){
    this->testCodeVector = v;
}

void ColorTest::setColorVector(std::vector<QColor> v){
    this->testColorVector = v;
}

const char *ColorTest::getFirstElement()
{
    return testsVector[0];
}

void ColorTest::paletteTest(const char *path)
{
    label = new QLabel(this);
    QRect screenGeometry = QGuiApplication::primaryScreen()->geometry();
    QSize screenSize = screenGeometry.size();
    QPixmap pixmap(path);
    label->setPixmap(pixmap.scaled(screenSize));
    label->setGeometry(QRect(QPoint(0, 0), screenSize));
    label->showFullScreen();
    backButton->raise();
}

void ColorTest::GradientTest(QColor color)
{
    setStyleSheet("QWidget {"
                  "background-color: palette(Window);"
                  "color: palette(WindowText);"
                  "}");
    QPalette defaultPalette = QApplication::palette();
    setPalette(defaultPalette);

    QLinearGradient gradient(0, 0, screen->geometry().width(), screen->geometry().height());
    gradient.setColorAt(0, QColor(0, 0, 0, 0));
    gradient.setColorAt(1, color);

    // Set the widget's background to the gradient
    setAutoFillBackground(false);
    QPalette pal = palette();
    pal.setBrush(QPalette::Window, QBrush(gradient));
    setPalette(pal);
}

void ColorTest::keyPressEvent(QKeyEvent *event)
{
    if(label != nullptr){
        delete label;
        label = nullptr;
    }
    switch (event->key()) {
    case Qt::Key_Left:
        index_ = (index_ - 1 + testCodeVector.size()) % testCodeVector.size();
        if(testCodeVector[index_] == 4){
            setStyleSheet(testsVector[index_]);
        }
        if(testCodeVector[index_] == 5){
            GradientTest(testColorVector[index_]);
        }
        if(testCodeVector[index_] == 6){
            paletteTest(":/color/palette/pictures/Palette.png");
        }
        if(testCodeVector[index_] == 7){
            paletteTest(":/color/palette/pictures/Palette180.png");
        }
        break;
    case Qt::Key_Right:
        index_ = (index_ + 1) % testCodeVector.size();
        if(testCodeVector[index_] == 4){
            this->setStyleSheet(testsVector[index_]);
        }
        if(testCodeVector[index_] == 5){
            GradientTest(testColorVector[index_]);
        }
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
