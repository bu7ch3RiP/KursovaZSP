#include "calibration_focus_test.h"

#include <QFont>
#include <QGraphicsTextItem>
#include <QGraphicsView>
#include <QGuiApplication>
#include <QKeyEvent>
#include <QLinearGradient>
#include <QPaintEvent>
#include <QPainter>
#include <QPen>
#include <QPixmap>
#include <QPushButton>
#include <QRect>
#include <QScreen>
#include <QVBoxLayout>
#include <QtWidgets>

const QColor AxisColor = Qt::white; // Change coordinate system color to white
const QColor GridColor = Qt::white; // Set grid color to black
const QFont TextFont("Arial", 8, QFont::Bold);

std::unordered_map<uint8_t, const char *> calib_focus_test_map
    = {{4, ":/color/palette/pictures/LCD_Calibration.png"},
       {5, ":/color/palette/pictures/BrightnessAndContrast.png"},
       {6, ":/color/palette/pictures/Gamma.png"},
       {7, ":/color/palette/pictures/WhitePattern.png"},
       {8, ":/color/palette/pictures/BlackPattern.png"},
       {9, ":/color/palette/pictures/Sharpness.png"},
       {11, ":/color/palette/pictures/Scope.png"},
       {12, ":/color/palette/pictures/Converage.png"}};

CalibrationFocusTest::CalibrationFocusTest(const bool &auto_test,
                                           const size_t &timeout,
                                           QWidget *parent)
    : QWidget{parent}
//, painter{this}
{
    label = nullptr;
    backButton = new QPushButton("X", this);
    backButton->setStyleSheet("background-color: #ff00ff;");
    connect(backButton, &QPushButton::clicked, this, &QWidget::close);

    screen = QGuiApplication::primaryScreen();

    backButton->setGeometry(QRect(QPoint(screen->geometry().width() - 35, 5), QSize(30, 30)));

    index_ = 0;
    draw_state = DrawType::kNone;
    scene = nullptr;
    view = nullptr;
    layout = nullptr;
    firstScreenSizeEnter = true;
    firstCalibrationTest = true;
    setFocusPolicy(Qt::StrongFocus);

    if (auto_test) {
        // Set up the QTimer to update the image every 4 seconds
        QTimer *timer = new QTimer(this);
        connect(timer, &QTimer::timeout, this, &CalibrationFocusTest::updateImage);
        timer->start(timeout * 1000); // Change the image every 4 seconds
    }
}

CalibrationFocusTest::~CalibrationFocusTest()
{
    if (backButton != nullptr)
        delete backButton;
    if (screen != nullptr)
        delete screen;
    if (label != nullptr)
        delete label;
    if (scene != nullptr)
        delete scene;
    if (view != nullptr)
        delete view;
    if (layout != nullptr)
        delete layout;
}

void CalibrationFocusTest::paintEvent(QPaintEvent *event)
{
    if (firstCalibrationTest) {
        firstCalibrationTest = false;
        QPainter painter(this);
        switch (draw_state) {
        case DrawType::kNone:
            break;
        case DrawType::kHorizontal:
        case DrawType::kVertical:
        case DrawType::kDots:
            saveDrawedPicture(draw_state);
            showPictureToTheScreen();
            break;
        case DrawType::kPicture:
            showCalibrationTest();
            break;
        case DrawType::kScreenSize:
            if (firstScreenSizeEnter)
                screenTest();
            firstScreenSizeEnter = false;
            break;
        }
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
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
        case 11:
        case 12:
            draw_state = DrawType::kPicture;
            break;
        case 1:
            draw_state = DrawType::kDots;
            break;
        case 2:
            draw_state = DrawType::kVertical;
            break;
        case 3:
            draw_state = DrawType::kHorizontal;
            break;
        case 10:
            draw_state = DrawType::kScreenSize;
            break;
        }
    }
}

void CalibrationFocusTest::showCalibrationTest()
{
    label = new QLabel(this);
    QRect screenGeometry = QGuiApplication::primaryScreen()->geometry();
    QSize screenSize = screenGeometry.size();
    QPixmap pixmap(calib_focus_test_map[testFocusVector[index_]]);
    label->setPixmap(pixmap.scaled(screenSize));
    label->setGeometry(QRect(QPoint(0, 0), screenSize));
    label->showFullScreen();
    backButton->raise();
}

void CalibrationFocusTest::drawCoordinateSystem(int screenWidth, int screenHeight)
{
    // Calculate the size of the coordinate system based on screen size
    int coordWidth = screenWidth;
    int coordHeight = screenHeight;

    // Calculate the center of the coordinate system
    int centerX = screenWidth / 2;
    int centerY = screenHeight / 2;

    // Draw the grid
    QPen gridPen(GridColor);
    for (int x = 0; x <= coordWidth; x += 50) {
        scene->addLine(x, 0, x, coordHeight, gridPen);
    }
    for (int y = 0; y <= coordHeight; y += 50) {
        scene->addLine(0, y, coordWidth, y, gridPen);
    }

    // Draw the x-axis
    QPen xPen(AxisColor);
    xPen.setWidth(2);
    scene->addLine(centerX - coordWidth / 2, centerY, centerX + coordWidth / 2, centerY, xPen);
    QGraphicsTextItem *textItemX = new QGraphicsTextItem("(" + QString::number(screenWidth) + ")");
    textItemX->setDefaultTextColor(Qt::white);
    textItemX->setFont(TextFont);
    textItemX->setPos(centerX + coordWidth / 2 - 40, centerY - 40);
    scene->addItem(textItemX);

    // Draw the y-axis
    QPen yPen(AxisColor);
    yPen.setWidth(2);
    scene->addLine(centerX, centerY - coordHeight / 2, centerX, centerY + coordHeight / 2, yPen);
    QGraphicsTextItem *textItemY = new QGraphicsTextItem("(" + QString::number(screenHeight) + ")");
    textItemY->setDefaultTextColor(Qt::white);
    textItemY->setFont(TextFont);
    textItemY->setPos(centerX - 40, centerY + coordHeight / 2 - 20);
    scene->addItem(textItemY);

    // Calculate the number of points to mark on the x-axis
    int numPointsX = coordWidth / 50;
    int startX = centerX - coordWidth / 2;

    // Draw the points on the x-axis
    for (int i = 0; i <= numPointsX; ++i) {
        int x = startX + i * 50;
        scene->addLine(x, centerY - 2, x, centerY + 2, xPen);
        QGraphicsTextItem *textItemX = new QGraphicsTextItem(QString::number(i * 50));
        textItemX->setDefaultTextColor(Qt::white);
        textItemX->setFont(TextFont);
        if (i == 0) {
            textItemX->setPos(x, centerY + 10);
        } else if (i % 2 == 0) {
            textItemX->setPos(x - 10, centerY + 10);
        } else {
            textItemX->setPos(x - 10, centerY - 20);
        }
        scene->addItem(textItemX);
    }

    // Calculate the number of points to mark on the y-axis
    int numPointsY = coordHeight / 50;
    int startY = centerY - coordHeight / 2;

    // Draw the points on the y-axis
    for (int i = 0; i <= numPointsY; ++i) {
        int y = startY + i * 50;
        scene->addLine(centerX - 2, y, centerX + 2, y, yPen);
        QGraphicsTextItem *textItemY = new QGraphicsTextItem(QString::number(i * 50));
        textItemY->setDefaultTextColor(Qt::white);
        textItemY->setFont(TextFont);
        if (i == 0) {
            textItemY->setPos(centerX - 40, y);
        } else if (i % 2 == 0) {
            textItemY->setPos(centerX - 40, y - 10);
        } else {
            textItemY->setPos(centerX + 10, y - 10);
        }
        scene->addItem(textItemY);
    }
}

void CalibrationFocusTest::setUpTest(uint8_t code)
{
    firstCalibrationTest = true;
    switch (code) {
    case 1:
        draw_state = DrawType::kDots;
        break;
    case 2:
        draw_state = DrawType::kVertical;
        break;
    case 3:
        draw_state = DrawType::kHorizontal;
        break;
    case 10:
        firstScreenSizeEnter = true;
        draw_state = DrawType::kScreenSize;
        break;
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 11:
    case 12:
        draw_state = DrawType::kPicture;
        break;
    }
}

void CalibrationFocusTest::updateImage()
{
    // Create a QKeyEvent object for the right key press event
    QKeyEvent *event = new QKeyEvent(QKeyEvent::KeyPress, Qt::Key_Right, Qt::NoModifier);

    // Call the keyPressEvent function with the simulated event
    keyPressEvent(event);

    // Clean up the allocated event object
    delete event;
}

void CalibrationFocusTest::screenTest()
{
    layout = new QVBoxLayout(this);
    setLayout(layout);
    layout->setContentsMargins(0, 0, 0, 0); // Remove layout margins

    scene = new QGraphicsScene(this);
    scene->setBackgroundBrush(Qt::black);
    view = new QGraphicsView(scene, this);
    view->setRenderHint(QPainter::Antialiasing);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setBackgroundBrush(Qt::black); // Set the background color to black
    layout->addWidget(view);

    setStyleSheet("QWidget { background-color: black; }");
    // Get the screen size
    QScreen *screen = QGuiApplication::primaryScreen();
    QRect screenRect = screen->geometry();
    int screenWidth = screenRect.width();
    int screenHeight = screenRect.height();

    // Set the scene rect to match the screen size
    scene->setSceneRect(0, 0, screenWidth, screenHeight);
    view->setGeometry(screenRect); // Set the view's geometry to fill the entire window

    // Draw the coordinate system
    drawCoordinateSystem(screenWidth, screenHeight);
    backButton->raise();
}

void CalibrationFocusTest::keyPressEvent(QKeyEvent *event)
{
    if (label != nullptr) {
        delete label;
        label = nullptr;
    }
    if (scene != nullptr) {
        delete scene;
        scene = nullptr;
    }

    if (view != nullptr) {
        delete view;
        view = nullptr;
    }

    if (layout != nullptr) {
        delete layout;
        layout = nullptr;
    }

    switch (event->key()) {
    case Qt::Key_Left:
        index_ = (index_ - 1 + testFocusVector.size()) % testFocusVector.size();
        setUpTest(testFocusVector[index_]);
        break;
    case Qt::Key_Right:
        index_ = (index_ + 1) % testFocusVector.size();
        setUpTest(testFocusVector[index_]);
        break;
    default:
        QWidget::keyPressEvent(event);
        break;
    }
}

bool CalibrationFocusTest::saveDrawedPicture(DrawType type)
{
    // Create a QPixmap object with the size of the widget
    QPixmap pixmap(screen->geometry().size());
    pixmap.fill(Qt::white); // Optional: Set the background to transparent

    QPainter painter(&pixmap); // Set the pixmap as the painter's device

    switch (type) {
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
    case DrawType::kVertical: {
        painter.setPen(QPen(Qt::black, kLineWidth));
        int x = 0;
        int spacing = kLineDelta;

        while (x < screen->geometry().width()) {
            painter.drawLine(x, 0, x, screen->geometry().height());
            x += spacing;
        }
    } break;
    case DrawType::kHorizontal: {
        painter.setPen(QPen(Qt::black, kLineWidth));
        int y = 0;
        int spacing = kLineDelta;

        while (y < screen->geometry().height()) {
            painter.drawLine(0, y, screen->geometry().width(), y);
            y += spacing;
        }
    } break;
    }
    painter.end(); // Release the painter

    pixmap.save("PictureOutput.png"); // Save the pixmap as an image file
}

void CalibrationFocusTest::showPictureToTheScreen()
{
    label = new QLabel(this);
    QRect screenGeometry = QGuiApplication::primaryScreen()->geometry();
    QSize screenSize = screenGeometry.size();
    QPixmap pixmap("PictureOutput.png");
    label->setPixmap(pixmap.scaled(screenSize));
    label->setGeometry(QRect(QPoint(0, 0), screenSize));
    label->showFullScreen();
    backButton->raise();
}
