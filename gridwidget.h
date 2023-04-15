
#ifndef GRIDWIDGET_H
#define GRIDWIDGET_H


#include <QWidget>


class GridWidget : public QWidget
{
    Q_OBJECT
public:
    explicit GridWidget(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event) override;

    void setTestColorVector( std::vector<QColor> );
    void setTestCodeVector(std::vector<uint8_t> );
    QColor getFirstColor();


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
};

#endif // GRIDWIDGET_H
