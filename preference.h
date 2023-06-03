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

class Preference : public QDialog
{
    Q_OBJECT
public:
    explicit Preference(size_t &auto_timeout, bool &to_save, QDialog *parent = nullptr)
        : p_auto_test_{&auto_timeout}
        , p_save_{&to_save}
    {
        QVBoxLayout *layout = new QVBoxLayout(this);

        QGroupBox *automaticGroupBox = new QGroupBox("Automatic mode");
        spinBox = new QSpinBox;
        spinBox->setRange(4, 20);
        QLabel *label = new QLabel("Seconds that each test screen will be shown");
        QVBoxLayout *automaticLayout = new QVBoxLayout;
        automaticLayout->addWidget(label);
        automaticLayout->addWidget(spinBox);
        automaticGroupBox->setLayout(automaticLayout);
        spinBox->setValue(auto_timeout);

        QGroupBox *generalGroupBox = new QGroupBox("General settings");
        checkBox = new QCheckBox("Save test selection state on exit");
        QVBoxLayout *generalLayout = new QVBoxLayout;
        checkBox->setChecked((to_save == true) ? true : false);
        generalLayout->addWidget(checkBox);
        generalGroupBox->setLayout(generalLayout);

        QPushButton *saveButton = new QPushButton("Save");
        connect(saveButton, &QPushButton::clicked, this, &Preference::saveButtonClicked);

        layout->addWidget(generalGroupBox);
        layout->addWidget(automaticGroupBox);
        layout->addWidget(saveButton);

        setLayout(layout);
        setFixedSize(300, 200);
    }

    ~Preference() { emit preferenceClosed(); }

signals:
    void preferenceClosed();

private slots:
    void saveButtonClicked()
    {
        *p_auto_test_ = static_cast<size_t>(spinBox->value());
        *p_save_ = checkBox->isChecked();
        QMessageBox::information(this, "Settings Saved", "The settings have been saved.");
        close();
    }

private:
    size_t *p_auto_test_;
    bool *p_save_;
    QSpinBox *spinBox;
    QCheckBox *checkBox;
};

#endif // PREFERENCE_H
