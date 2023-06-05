
#include "grid_test.h"

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

#include <unordered_map>

GridTest::GridTest(const bool &auto_test, const size_t &timeout, QWidget *parent)
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

    if (auto_test) {
        QTimer *timer = new QTimer(this);
        connect(timer, &QTimer::timeout, this, &GridTest::updateImage);
        timer->start(timeout * 1000);
    }
}

void GridTest::updateImage()
{
    // Create a QKeyEvent object for the right key press event
    QKeyEvent *event = new QKeyEvent(QKeyEvent::KeyPress, Qt::Key_Right, Qt::NoModifier);

    // Call the keyPressEvent function with the simulated event
    keyPressEvent(event);

    // Clean up the allocated event object
    delete event;
}

void GridTest::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);
    QScreen *screen = QGuiApplication::primaryScreen();
    painter.setPen(QPen(m_color, 1, Qt::SolidLine));
    const int cell_size = screen->geometry().width() / 20;
    const int cell_size2 = screen->geometry().height() / 20;
    const int rows = 20;
    const int cols = 20;
    const int grid_width = cell_size * cols;
    const int grid_height = cell_size2 * rows;
    const int x_offset = (screen->geometry().width() - grid_width) / 2;
    const int y_offset = (screen->geometry().height() - grid_height) / 2;
    for (int i = 0; i <= cols; i++) {
        const int x = x_offset + i * cell_size;
        painter.drawLine(x, y_offset, x, y_offset + grid_height);
    }
    for (int i = 0; i <= rows; i++) {
        const int y = y_offset + i * cell_size2;
        painter.drawLine(x_offset, y, x_offset + grid_width, y);
    }
}

void GridTest::setTestColorVector(std::vector<QColor> color)
{
    testColorVector = color;
}

void GridTest::setTestCodeVector(std::vector<uint8_t> code)
{
    testCodeVector = code;
}

QColor GridTest::getFirstColor()
{
    return testColorVector[0];
}

void GridTest::setFirstGrid(QColor color)
{
    std::unordered_map<uint8_t, QColor> mColor = {{2, Qt::black}, {3, Qt::white}};
    QPalette palette = this->palette();
    palette.setColor(QPalette::Window, mColor[testCodeVector[0]]);
    this->setAutoFillBackground(true);
    this->setPalette(palette);
    setColor(testColorVector[0]);
}

void GridTest::setColor(const QColor &color)
{
    m_color = color;
    update();
}


void GridTest::keyPressEvent(QKeyEvent *event)
{
    std::unordered_map<uint8_t, QColor> mColor = {{2, Qt::black}, {3, Qt::white}};
    QPalette palette = this->palette();

    switch (event->key()) {
    case Qt::Key_Left:
        index_ = (index_ - 1 + testCodeVector.size()) % testCodeVector.size();
        palette.setColor(QPalette::Window, mColor[testCodeVector[index_]]);
        this->setAutoFillBackground(true);
        this->setPalette(palette);
        setColor(testColorVector[index_]);
        break;
    case Qt::Key_Right:
        index_ = (index_ + 1) % testCodeVector.size();
        palette.setColor(QPalette::Window, mColor[testCodeVector[index_]]);
        this->setAutoFillBackground(true);
        this->setPalette(palette);
        setColor(testColorVector[index_]);
        break;
    default:
        QWidget::keyPressEvent(event);
        break;
    }
}

