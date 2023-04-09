
#ifndef TABLEWIDGET_H
#define TABLEWIDGET_H


#include <QWidget>


class TableWidget : public QWidget
{
    Q_OBJECT
public:
    explicit TableWidget(QWidget *parent = nullptr);

    void setTestColorVector(std::vector<QColor>);
    void setTestCodeVector(std::vector<uint8_t>);
    QColor getFirstColor();


protected:
    void paintEvent(QPaintEvent *event) override;

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

signals:

};

#endif // TABLEWIDGET_H
