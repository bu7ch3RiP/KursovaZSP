#ifndef CALIBRATION_FOCUS_TEST_H
#define CALIBRATION_FOCUS_TEST_H

#include <QGraphicsScene>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>
#include <unordered_map>

constexpr int kDelta{3};
constexpr int kPixelsSize{2};

enum class DrawType { kDots, kVertical, kGorizontal, kPicture, kScreenSize, kNone };

class CalibrationFocusTest : public QWidget
{
    Q_OBJECT
public:
    explicit CalibrationFocusTest(QWidget *parent = nullptr);
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
    QGraphicsScene *scene;
    QGraphicsView *view;
    QVBoxLayout *layout;

    std::vector<uint8_t> testCodeVector{};
    std::vector<uint8_t> testFocusVector{};

private:
    void showCalibrationTest();
    void screenTest();
    void drawCoordinateSystem(int screenWidth, int screenHeight);
    void setUpTest(uint8_t);
};

#endif // CALIBRATION_FOCUS_TEST_H
