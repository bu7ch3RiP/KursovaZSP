
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

const char *TestWindow::getFirstElement()
{
    return testsVector[0];
}

void TestWindow::keyPressEvent(QKeyEvent *event)
{
    switch (event->key()) {
    case Qt::Key_Left:
        index_ = (index_ - 1 + testsVector.size()) % testsVector.size();
        setStyleSheet(testsVector[index_]);
        break;
    case Qt::Key_Right:
        index_ = (index_ + 1) % testsVector.size();
        this->setStyleSheet(testsVector[index_]);
        break;
    default:
        QWidget::keyPressEvent(event);
        break;
    }
}



