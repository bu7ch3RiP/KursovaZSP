
#ifndef TESTWINDOW_H
#define TESTWINDOW_H

#include <QWidget>
#include <QKeyEvent>
#include <QColor>
#include <QPixmap>

class ColorTest : public QWidget
{
    Q_OBJECT
public:
    explicit ColorTest(QWidget *parent = nullptr);

    void setVectorValues(std::vector<const char*>);
    void setCodeVector(std::vector<uint8_t>);
    void setColorVector(std::vector<QColor>);

    const char *getFirstElement();
    void paletteTest(const char*);

    void deleteAllWidgets();

    void GradientTest(QColor);

protected:
    void keyPressEvent(QKeyEvent *event) override;
signals:

private:
    std::vector<const char*> testsVector{};
    std::vector<uint8_t> testCodeVector{};
    std::vector<QColor> testColorVector{};
    int index_ = 0;

private:
    void setImage(const QPixmap &pixmap);
};

#endif // TESTWINDOW_H
