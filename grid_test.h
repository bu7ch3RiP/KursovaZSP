
#ifndef GRIDWIDGET_H
#define GRIDWIDGET_H


#include <QWidget>


class GridTest : public QWidget
{
    Q_OBJECT
public:
    explicit GridTest(const bool &auto_test, const size_t &timeout, QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event) override;

    void setTestColorVector( std::vector<QColor> );
    void setTestCodeVector(std::vector<uint8_t> );
    QColor getFirstColor();
    void setFirstGrid(QColor);

signals:

public slots:
    void setColor(const QColor& color);

protected:
    void keyPressEvent(QKeyEvent *event) override;

private:
    int index_;
    std::vector<uint8_t> testCodeVector{};
    std::vector<QColor> testColorVector{};
    QColor m_color = Qt::black;
    QColor m_backGround = Qt::white;

private:
    void updateImage();
};

#endif // GRIDWIDGET_H
