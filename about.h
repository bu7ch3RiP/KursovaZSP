#ifndef ABOUT_H
#define ABOUT_H

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

class About : public QDialog
{
    Q_OBJECT
public:
    explicit About(const bool english, QDialog *parent = nullptr)
    {
        QVBoxLayout *layout = new QVBoxLayout(this);
        QFont titleFont("Arial", 16, QFont::Bold);
        QFont productFont("Arial", 14, QFont::Bold);
        QFont infoFont("Arial", 14);
        setWindowTitle(english == true ? title_en[1] : title_ua[1]);
        QLabel *titleLabel = new QLabel(english == true ? about_en[0] : about_ua[0]);
        titleLabel->setAlignment(Qt::AlignCenter);
        titleLabel->setFont(titleFont);
        QLabel *productLabel = new QLabel(english == true ? about_en[1] : about_ua[1]);
        productLabel->setFont(productFont);
        QLabel *projectLabel = new QLabel(english == true ? about_en[2] : about_ua[2]);
        projectLabel->setFont(infoFont);
        QLabel *authorLabel = new QLabel(english == true ? about_en[3] : about_ua[3]);
        authorLabel->setFont(productFont);
        QLabel *nameLabel = new QLabel(english == true ? about_en[4] : about_ua[4]);
        nameLabel->setFont(infoFont);
        QLabel *versionLabel = new QLabel(english == true ? about_en[5] : about_ua[5]);
        versionLabel->setAlignment(Qt::AlignCenter);
        versionLabel->setFont(productFont);
        layout->addWidget(titleLabel);
        layout->addSpacing(10);
        layout->addWidget(productLabel);
        layout->addWidget(projectLabel);
        layout->addSpacing(20);
        layout->addWidget(authorLabel);
        layout->addWidget(nameLabel);
        layout->addWidget(new QLabel(""));
        layout->addWidget(versionLabel);
        setLayout(layout);
        setFixedSize(520, 300);
    }
    ~About() {}
};

#endif // ABOUT_H
