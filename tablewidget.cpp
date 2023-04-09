
#include "tablewidget.h"

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

TableWidget::TableWidget(QWidget *parent)
    : QWidget{parent}
{
    setAttribute(Qt::WA_OpaquePaintEvent);
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

void TableWidget::setTestColorVector(std::vector<QColor> color)
{
    testColorVector = color;
}

void TableWidget::setTestCodeVector(std::vector<uint8_t> code)
{
    testCodeVector = code;
}

QColor TableWidget::getFirstColor()
{
    return testColorVector[0];
}

void TableWidget::paintEvent(QPaintEvent *event){
    QPainter painter(this);
    painter.fillRect(rect(), Qt::black); // Set background color to white
    painter.setPen(Qt::red); // Set pen color to black
    QFont font("Arial", 10); // Set font and font size
    painter.setFont(font);

    QScreen *screen = QGuiApplication::primaryScreen();


    int rowCount = 70;
    int colCount = 15;
    int cellWidth = screen->geometry().width() / colCount;
    int cellHeight = screen->geometry().height() / rowCount;

    for (int i = 0; i < rowCount; i++) {
        for (int j = 0; j < colCount; j++) {
            QRect rect(j * cellWidth, i * cellHeight + 15, cellWidth, cellHeight);
            painter.drawText(rect, Qt::AlignCenter, "Can you read text?");
        }
    }
}

void TableWidget::setColor(const QColor& color){
    m_color = color;
    update();
}

void TableWidget::keyPressEvent(QKeyEvent *event){

}
