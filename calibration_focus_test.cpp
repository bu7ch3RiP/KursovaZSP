#include "calibration_focus_test.h"

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

CalibrationFocusTest::CalibrationFocusTest(QWidget *parent)
    : QWidget{parent}
{
    label = nullptr;
    backButton = new QPushButton("X", this);
    backButton->setStyleSheet("background-color: #ff00ff;");
    connect(backButton, &QPushButton::clicked, this, &QWidget::close);

    screen = QGuiApplication::primaryScreen();

    backButton->setGeometry(QRect(QPoint(screen->geometry().width()-35, 5), QSize(30, 30)));

    index_ = 0;
    draw_state = DrawType::kNone;
    setFocusPolicy( Qt::StrongFocus );
}

void CalibrationFocusTest::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    switch (draw_state) {
    case DrawType::kDots:
        for (int y = 0; y < screen->geometry().height(); y += kDelta) {
            for (int x = 0; x < screen->geometry().width(); x += kDelta) {
                painter.fillRect(x, y, kPixelsSize, kPixelsSize, Qt::black);
                painter.fillRect(x + kPixelsSize,
                                 y + kPixelsSize,
                                 kPixelsSize,
                                 kPixelsSize,
                                 Qt::black);
            }
        }
        break;
    case DrawType::kGorizontal: {
        painter.setPen(Qt::black);
        int y = 0;
        int spacing = kDelta;

        while (y < screen->geometry().height()) {
            painter.drawLine(0, y, screen->geometry().width(), y);
            y += spacing;
        }
    } break;
    case DrawType::kVertical: {
        painter.setPen(Qt::black);
        int x = 0;
        int spacing = kDelta;

        while (x < screen->geometry().width()) {
            painter.drawLine(x, 0, x, screen->geometry().height());
            x += spacing;
        }
    } break;
    }
}

void CalibrationFocusTest::setDrawState(DrawType state)
{
    this->draw_state = state;
}

DrawType CalibrationFocusTest::getDrawState()
{
    return draw_state;
}

void CalibrationFocusTest::setTestCodeVector(std::vector<uint8_t> code_vec)
{
    this->testCodeVector = code_vec;
}

void CalibrationFocusTest::setTestFocusVector(std::vector<uint8_t> focus_vec)
{
    this->testFocusVector = focus_vec;
}

void CalibrationFocusTest::setUpTest()
{
    if (testCodeVector[0] == 1) {
        switch (testFocusVector[0]) {
        case 0:
            draw_state = DrawType::kPicture;
            break;
        case 1:
            draw_state = DrawType::kDots;
            break;
        case 2:
            draw_state = DrawType::kVertical;
            break;
        case 3:
            draw_state = DrawType::kGorizontal;
            break;
        }
    }
}
