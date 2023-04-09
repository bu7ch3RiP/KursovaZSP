
#include "gridwidget.h"

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

#include <unordered_map>

GridWidget::GridWidget(QWidget *parent)
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

void GridWidget::paintEvent(QPaintEvent *event)
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

void GridWidget::setTestColorVector(std::vector<QColor> color)
{
    testColorVector = color;
}

void GridWidget::setTestCodeVector(std::vector<uint8_t> code)
{
    testCodeVector = code;
}

QColor GridWidget::getFirstColor()
{
    return testColorVector[0];
}

void GridWidget::setColor(const QColor &color)
{
    m_color = color;
    update();
}


void GridWidget::keyPressEvent(QKeyEvent *event)
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


    //switch (event->key()) {
    //case Qt::Key_Left:
    //    setColor(Qt::red);
    //    break;
    //case Qt::Key_Right:
    //    setColor(Qt::green);
    //    break;
    //case Qt::Key_Up:
    //    setColor(Qt::blue);
    //    break;
    //case Qt::Key_Down:
    //    setColor(Qt::black);
    //    break;
    //default:
    //    QWidget::keyPressEvent(event);
    //}
}

