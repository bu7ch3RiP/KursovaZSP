
#ifndef SYSTRAY_H
#define SYSTRAY_H

#include <QMainWindow>
#include "QSystemTrayIcon"

class SysTray : public QMainWindow
{
    Q_OBJECT
public:
    SysTray();
    ~SysTray();
    void showMessage();

private:
    QSystemTrayIcon *sysTrayIcon{};

    QMenu *menu{};
    QAction *viewWindow{};
    QAction *minimazeAction{};
    QAction *quitAction{};
    QAction *showWidgetAction{};
signals:
    void showApp(bool checked);
    void closeApp(bool checked);
    void hideApp(bool checked);
    void activateTray(QSystemTrayIcon::ActivationReason reason);
};

#endif // SYSTRAY_H
