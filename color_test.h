
#ifndef TESTWINDOW_H
#define TESTWINDOW_H

#include <QWidget>
#include <QKeyEvent>
#include <QColor>
#include <QLabel>
#include <QPushButton>
#include <QPixmap>



class ColorTest : public QWidget
{
    Q_OBJECT
public:
    explicit ColorTest(const bool &auto_test, const size_t &timeout, QWidget *parent = nullptr);

    void setVectorValues(std::vector<const char*>);
    void setCodeVector(std::vector<uint8_t>);
    void setColorVector(std::vector<QColor>);

    const char *getFirstElement();
    void paletteTest(const char*);

    void GradientTest(QColor);

protected:
    void keyPressEvent(QKeyEvent *event) override;
signals:

private:
    std::vector<const char*> testsVector{};
    std::vector<uint8_t> testCodeVector{};
    std::vector<QColor> testColorVector{};
    int index_ = 0;
    QPushButton *backButton;
    QScreen *screen;
    QLabel *label;

private:
    void updateImage();
};

#endif // TESTWINDOW_H
