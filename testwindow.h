
#ifndef TESTWINDOW_H
#define TESTWINDOW_H

#include <QWidget>
#include <QKeyEvent>


class TestWindow : public QWidget
{
    Q_OBJECT
public:
    explicit TestWindow(QWidget *parent = nullptr);

    void setVectorValues(std::vector<const char*>);
    const char *getFirstElement();

protected:
    void keyPressEvent(QKeyEvent *event) override;
signals:

private:
    std::vector<const char*> testsVector{};
    int index_ = 0;
};

#endif // TESTWINDOW_H
