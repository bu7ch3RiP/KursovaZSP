
#ifndef TESTWINDOW_H
#define TESTWINDOW_H

#include <QWidget>
#include <QKeyEvent>
#include <QColor>

class TestWindow : public QWidget
{
    Q_OBJECT
public:
    explicit TestWindow(QWidget *parent = nullptr);

    void setVectorValues(std::vector<const char*>);
    void setCodeVector(std::vector<uint8_t>);
    void setColorVector(std::vector<QColor>);

    void setPallete(const char*);

    const char *getFirstElement();


    void GradientTest(QColor);

protected:
    void keyPressEvent(QKeyEvent *event) override;
signals:

private:
    std::vector<const char*> testsVector{};
    std::vector<uint8_t> testCodeVector{};
    std::vector<QColor> testColorVector{};
    int index_ = 0;
};

#endif // TESTWINDOW_H
