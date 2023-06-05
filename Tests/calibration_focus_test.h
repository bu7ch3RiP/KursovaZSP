#ifndef CALIBRATION_FOCUS_TEST_H
#define CALIBRATION_FOCUS_TEST_H

#include <QGraphicsScene>
#include <QLabel>
#include <QPainter>
#include <QPushButton>
#include <QTimer>
#include <QVBoxLayout>
#include <QWidget>
#include <unordered_map>

constexpr int kDelta{3};
constexpr int kLineDelta{4};
constexpr int kLineWidth{3};
constexpr int kPixelsSize{2};

enum class DrawType { kDots, kVertical, kHorizontal, kPicture, kScreenSize, kNone };

class CalibrationFocusTest : public QWidget
{
    Q_OBJECT
public:
    explicit CalibrationFocusTest(const bool &auto_test,
                                  const size_t &timeout,
                                  QWidget *parent = nullptr);
    ~CalibrationFocusTest();
    void paintEvent(QPaintEvent *event);
    void setDrawState(DrawType);
    DrawType getDrawState();

    void setTestCodeVector(std::vector<uint8_t>);
    void setTestFocusVector(std::vector<uint8_t>);

    void setUpTest();

protected:
    void keyPressEvent(QKeyEvent *event) override;

signals:

private:
    int index_ = 0;
    bool firstScreenSizeEnter;
    bool firstCalibrationTest;
    DrawType draw_state;
    QPushButton *backButton;
    QScreen *screen;
    QLabel *label;
    //QPainter painter;
    QGraphicsScene *scene;
    QGraphicsView *view;
    QVBoxLayout *layout;

    std::vector<uint8_t> testCodeVector{};
    std::vector<uint8_t> testFocusVector{};

private:
    bool saveDrawedPicture(DrawType type);
    void showPictureToTheScreen();
    void showCalibrationTest();
    void screenTest();
    void drawCoordinateSystem(int screenWidth, int screenHeight);
    void setUpTest(uint8_t);
    void updateImage();
};

#endif // CALIBRATION_FOCUS_TEST_H
