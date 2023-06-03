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

class About : public QDialog
{
    Q_OBJECT
public:
    explicit About(QDialog *parent = nullptr)
    {
        QVBoxLayout *layout = new QVBoxLayout(this);
        QFont titleFont("Arial", 16, QFont::Bold);
        QFont productFont("Arial", 14, QFont::Bold);
        QFont infoFont("Arial", 14);
        setWindowTitle("About");
        QLabel *titleLabel = new QLabel("Monitor Testing");
        titleLabel->setAlignment(Qt::AlignCenter);
        titleLabel->setFont(titleFont);
        QLabel *productLabel = new QLabel(" Product information:");
        productLabel->setFont(productFont);
        QLabel *projectLabel = new QLabel("    This work was performed within the scope of the "
                                          "course\nproject in the discipline: \"System Software\"");
        projectLabel->setFont(infoFont);
        QLabel *authorLabel = new QLabel(" Author of the work:");
        authorLabel->setFont(productFont);
        QLabel *nameLabel = new QLabel(
            "    Name, student of group KI-3 of the National University\n"
            "\"Lviv Polytechnic\" majoring in Computer Engineering");
        nameLabel->setFont(infoFont);
        QLabel *versionLabel = new QLabel("Version: 1.0 beta");
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
