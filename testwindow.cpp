
#include "testwindow.h"
#include <QtWidgets>
#include <QPushButton>
#include <QGuiApplication>
#include <QPainter>
#include <QRect>
#include <QScreen>
#include <QPaintEvent>
#include <QVBoxLayout>

TestWindow::TestWindow(QWidget *parent)
    : QWidget{parent}
{
    // Створення кнопки "Повернутися"
    QPushButton *backButton = new QPushButton("X", this);
    connect(backButton, &QPushButton::clicked, this, &QWidget::close);

    // Розміщення кнопки на вікні
    QScreen *screen = QGuiApplication::primaryScreen();
    backButton->setGeometry(QRect(QPoint(screen->geometry().width()-35, 5), QSize(30, 30)));;
}



