#ifndef PREFERENCE_H
#define PREFERENCE_H

#include <QCheckBox>
#include <QDialog>
#include <QGroupBox>
#include <QLabel>
#include <QMessageBox>
#include <QPushButton>
#include <QSpinBox>
#include <QVBoxLayout>
#include <QWidget>

#include "language.h"

class Preference : public QDialog
{
    Q_OBJECT
public:
    explicit Preference(size_t &auto_timeout, bool &to_save, bool english, QDialog *parent = nullptr)
        : p_auto_test_{&auto_timeout}
        , p_save_{&to_save}
        , english_{english}
    {
        QVBoxLayout *layout = new QVBoxLayout(this);
        setWindowTitle(english == true ? title_en[2] : title_ua[2]);
        QGroupBox *automaticGroupBox = new QGroupBox(english == true ? preferences_en[2]
                                                                     : preferences_ua[2]);
        spinBox = new QSpinBox;
        spinBox->setRange(4, 20);
        QLabel *label = new QLabel(english == true ? preferences_en[3] : preferences_ua[3]);
        QVBoxLayout *automaticLayout = new QVBoxLayout;
        automaticLayout->addWidget(label);
        automaticLayout->addWidget(spinBox);
        automaticGroupBox->setLayout(automaticLayout);
        spinBox->setValue(auto_timeout);

        QGroupBox *generalGroupBox = new QGroupBox(english == true ? preferences_en[0]
                                                                   : preferences_ua[0]);
        checkBox = new QCheckBox(english == true ? preferences_en[1] : preferences_ua[1]);
        QVBoxLayout *generalLayout = new QVBoxLayout;
        checkBox->setChecked((to_save == true) ? true : false);
        generalLayout->addWidget(checkBox);
        generalGroupBox->setLayout(generalLayout);

        QPushButton *saveButton = new QPushButton(english == true ? preferences_en[4]
                                                                  : preferences_ua[4]);
        connect(saveButton, &QPushButton::clicked, this, &Preference::saveButtonClicked);

        layout->addWidget(generalGroupBox);
        layout->addWidget(automaticGroupBox);
        layout->addWidget(saveButton);

        setLayout(layout);
        setFixedSize(300, 230);
    }

    ~Preference() { emit preferenceClosed(); }

signals:
    void preferenceClosed();

private slots:
    void saveButtonClicked()
    {
        *p_auto_test_ = static_cast<size_t>(spinBox->value());
        *p_save_ = checkBox->isChecked();
        QMessageBox::information(this,
                                 english_ == true ? preferences_en[5] : preferences_ua[5],
                                 english_ == true ? preferences_en[6] : preferences_ua[6]);
        close();
    }

private:
    size_t *p_auto_test_;
    bool *p_save_;
    bool english_;
    QSpinBox *spinBox;
    QCheckBox *checkBox;
};

#endif // PREFERENCE_H
