
#include "read_test.h"
#include <QWidget>

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

ReadTest::ReadTest(const bool &auto_test, const size_t &timeout, QWidget *parent)
    : QWidget{parent}
{
    qCMap.insert(Qt::white, Qt::black);
    qCMap.insert(Qt::black, Qt::white);
    qCMap.insert(Qt::red, Qt::blue);
    qCMap.insert(Qt::blue, Qt::green);
    qCMap.insert(Qt::magenta, Qt::black);
    qCMap.insert(Qt::yellow, Qt::blue);

    // Створення кнопки "Повернутися"
    QPushButton *backButton = new QPushButton("X", this);
    backButton->setStyleSheet("background-color: #ff00ff;");
    connect(backButton, &QPushButton::clicked, this, &QWidget::close);

    // Розміщення кнопки на вікні
    QScreen *screen = QGuiApplication::primaryScreen();
    backButton->setGeometry(QRect(QPoint(screen->geometry().width()-35, 5), QSize(30, 30)));

    index_ = 0;
    setFocusPolicy(Qt::StrongFocus);

    if (auto_test) {
        // Set up the QTimer to update the image every 4 seconds
        QTimer *timer = new QTimer(this);
        connect(timer, &QTimer::timeout, this, &ReadTest::updateImage);
        timer->start(timeout * 1000); // Change the image every 4 seconds
    }
}

void ReadTest::updateImage()
{
    // Create a QKeyEvent object for the right key press event
    QKeyEvent *event = new QKeyEvent(QKeyEvent::KeyPress, Qt::Key_Right, Qt::NoModifier);

    // Call the keyPressEvent function with the simulated event
    keyPressEvent(event);

    // Clean up the allocated event object
    delete event;
}

QColor ReadTest::getFirstColor()
{
    return testColorVector[0];
}

void ReadTest::setColor(const QColor &color)
{
    m_textColor = color;
    m_backgroundColor = qCMap.value(color);
    update();
}

void ReadTest::setTestColorVector(std::vector<QColor> color)
{
    testColorVector = color;
}

void ReadTest::setTestCodeVector(std::vector<uint8_t> code)
{
    testCodeVector = code;
}

void ReadTest::paintEvent(QPaintEvent *event){
    QPainter painter(this);
    painter.fillRect(rect(), m_backgroundColor);
    painter.setPen(m_textColor);
    QFont font("Arial", 10);
    painter.setFont(font);

    QScreen *screen = QGuiApplication::primaryScreen();

    QString can_you_read_text = "Can you read text?";
    long long text_length = (can_you_read_text.length() + 15) * 4;

    int rowCount = screen->geometry().height() / 15;
    int colCount = screen->geometry().width() / text_length;
    int cellWidth = screen->geometry().width() / colCount;
    int cellHeight = screen->geometry().height() / rowCount;

    for (int i = 0; i < rowCount; i++) {
        for (int j = 0; j < colCount; j++) {
            QRect rect(j * cellWidth, i * cellHeight + 15, cellWidth, cellHeight);
            painter.drawText(rect, Qt::AlignCenter, "Can you read text?");
        }
    }
}

void ReadTest::keyPressEvent(QKeyEvent *event){

    switch (event->key()) {
    case Qt::Key_Left:
        index_ = (index_ - 1 + testCodeVector.size()) % testCodeVector.size();
        setColor(testColorVector[index_]);
        break;
    case Qt::Key_Right:
        index_ = (index_ + 1) % testCodeVector.size();
        setColor(testColorVector[index_]);
        break;
    default:
        QWidget::keyPressEvent(event);
        break;
    }
}
