#ifndef CALIBRATION_FOCUS_TEST_H
#define CALIBRATION_FOCUS_TEST_H

#include <QLabel>
#include <QPushButton>
#include <QWidget>
#include <unordered_map>

constexpr int kDelta{3};
constexpr int kPixelsSize{2};

enum class DrawType { kDots, kVertical, kGorizontal, kPicture, kNone };

class CalibrationFocusTest : public QWidget
{
    Q_OBJECT
public:
    explicit CalibrationFocusTest(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event);
    void setDrawState(DrawType);
    DrawType getDrawState();

    void setTestCodeVector(std::vector<uint8_t>);
    void setTestFocusVector(std::vector<uint8_t>);

    void setUpTest();
signals:

private:
    int index_ = 0;
    DrawType draw_state;
    QPushButton *backButton;
    QScreen *screen;
    QLabel *label;

    std::vector<uint8_t> testCodeVector{};
    std::vector<uint8_t> testFocusVector{};

private:
    void showCalibrationTest();
};

#endif // CALIBRATION_FOCUS_TEST_H
