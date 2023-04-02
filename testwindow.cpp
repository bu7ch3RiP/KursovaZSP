#include "testwindow.h"
#include <QtWidgets>
#include <QPushButton>
#include <QGuiApplication>
#include <QPainter>
#include <QRect>
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

void TestWindow::setPallete(const char *path)
{
    QLabel label(this);
    QPixmap pixmap(path);
    label.setPixmap(pixmap);
    label.setAlignment(Qt::AlignCenter);

    //setCentralWidget(&label);
    setWindowState(Qt::WindowFullScreen);

}

const char *TestWindow::getFirstElement()
{
    return testsVector[0];
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
        if(testCodeVector[index_] == 6)
            qDebug() << "Good";
        if(testCodeVector[index_] == 7)
            qDebug() << "Bad180";
        break;
    case Qt::Key_Right:
        index_ = (index_ + 1) % testCodeVector.size();
        if(testCodeVector[index_] == 4)
            this->setStyleSheet(testsVector[index_]);
        if(testCodeVector[index_] == 5)
            GradientTest(testColorVector[index_]);
        if(testCodeVector[index_] == 6)
            qDebug() << "Good";
        if(testCodeVector[index_] == 7)
            qDebug() << "Bad180";
        break;
    default:
        QWidget::keyPressEvent(event);
        break;
    }
}



