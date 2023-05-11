#ifndef CALIBRATION_FOCUS_TEST_H
#define CALIBRATION_FOCUS_TEST_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>

class CalibrationFocusTest : public QWidget
{
    Q_OBJECT
public:
    explicit CalibrationFocusTest(QWidget *parent = nullptr);

signals:

private:
    int index_ = 0;
    QPushButton *backButton;
    QScreen *screen;
    QLabel *label;
};

#endif // CALIBRATION_FOCUS_TEST_H
