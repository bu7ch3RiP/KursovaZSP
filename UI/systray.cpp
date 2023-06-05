#include "systray.h"
#include "qmenu.h"

const static QString styleTray
    = "QMenu { background-color: rgb(33, 37, 43); color : white; }"
      "QMenu::item:selected { background-color: rgb(26, 58, 85);} "
      "QMenu::separator { background-color: white; height: 1px; margin: 5px 0px 5px 0px; }";

SysTray::SysTray()
{
    sysTrayIcon = new QSystemTrayIcon(this);
    sysTrayIcon->setToolTip(tr("Display testing"));
    sysTrayIcon->setIcon(QIcon(":/color/palette/pictures/MonitorTesting.ico"));

    /* Also connect clicking on the icon to the signal processor of this press  */
    connect(sysTrayIcon,
            &QSystemTrayIcon::activated,
            this,
            [this](QSystemTrayIcon::ActivationReason reason) { emit this->activateTray(reason); });

    /*Create context menu for sys tray*/
    menu = new QMenu(this);
    viewWindow = new QAction(tr("Open"), this);
    minimazeAction = new QAction(tr("Minimaze"), this);
    quitAction = new QAction(tr("Quit"), this);

    QFont font("Segoe UI", 12);

    menu->addAction(viewWindow);
    menu->addAction(minimazeAction);
    menu->addAction(quitAction);
    menu->addSeparator();
    menu->addAction(showWidgetAction);

    menu->setStyleSheet(styleTray);
    menu->setFont(font);

    sysTrayIcon->setContextMenu(menu);
    sysTrayIcon->show();

    // connect(sysTrayIcon, &QSystemTrayIcon::activated, )
    connect(viewWindow, &QAction::triggered, [this](bool checked = false) {
        emit this->showApp(checked);
    });
    connect(minimazeAction, &QAction::triggered, [this](bool checked = false) {
        emit this->hideApp(checked);
    });
    connect(quitAction, &QAction::triggered, [this](bool checked = false) {
        emit this->closeApp(checked);
    });
}

SysTray::~SysTray()
{
    delete sysTrayIcon;
    delete menu;
    delete viewWindow;
    delete minimazeAction;
    delete quitAction;
    delete showWidgetAction;
}

void SysTray::showMessage()
{
    QSystemTrayIcon::MessageIcon i = QSystemTrayIcon::MessageIcon(QSystemTrayIcon::Information);
    sysTrayIcon->showMessage(
        "Display testing",
        (tr("The application is minimized to the tray. To maximize the application window "
            "click on the application icon in the tray")),
        i,
        2000);
}
