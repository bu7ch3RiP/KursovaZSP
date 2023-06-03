
#ifndef READTEST_H
#define READTEST_H


#include <QWidget>
#include <QColor>
#include <QMap>

struct qColorMap {
    std::vector<QColor> key_;
    std::vector<QColor> value_;

    void insert(QColor keyColor, QColor valueColor)
    {
        key_.push_back(keyColor);
        value_.push_back(valueColor);
    }

    QColor value(QColor key){
        int index = 0;
        for(int i = 0; i < key_.size(); i++){
            if(key_[i] == key){
                index = i;
                break;
            }
        }

        return value_[index];
    }
};


class ReadTest : public QWidget
{
    Q_OBJECT
public:
    explicit ReadTest(const bool &auto_test, const size_t &timeout, QWidget *parent = nullptr);
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
    QColor m_backgroundColor{};
    QColor m_textColor{};

    qColorMap qCMap;

    std::vector<uint8_t> testCodeVector{};
    std::vector<QColor> testColorVector{};
    int index_{};

private:
    void updateImage();
};

#endif // READTEST_H
