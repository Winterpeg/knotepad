/*
    SPDX-FileCopyrightText: 2025 Mike Young <harnmaster@gmail.com>

    SPDX-License-Identifier: GPL-2.0-only OR GPL-3.0-only OR LicenseRef-KDE-Accepted-GPL
*/

// application headers
#include "knotepadwindow.h"

#include "knotepadview.h"
#include "knotepaddebug.h"

// KF headers
#include <KActionCollection>
#include <KConfigDialog>


knotepadWindow::knotepadWindow()
    : KXmlGuiWindow()
{
    m_knotepadView = new knotepadView(this);
    setCentralWidget(m_knotepadView);

    KActionCollection* actionCollection = this->actionCollection();
    m_switchAction = actionCollection->addAction(QStringLiteral("switch_action"));
    m_switchAction->setText(i18nc("@action", "Switch Colors"));
    m_switchAction->setIcon(QIcon::fromTheme(QStringLiteral("fill-color")));
    connect(m_switchAction, &QAction::triggered, m_knotepadView, &knotepadView::switchColors);

    KStandardAction::openNew(this, SLOT(fileNew()), actionCollection);
    KStandardAction::quit(qApp, SLOT(closeAllWindows()), actionCollection);
    KStandardAction::preferences(this, SLOT(settingsConfigure()), actionCollection);

    setupGUI();
}

knotepadWindow::~knotepadWindow()
{
}

void knotepadWindow::fileNew()
{
    qCDebug(KNOTEPAD) << "knotepadWindow::fileNew()";
    (new knotepadWindow)->show();
}

void knotepadWindow::settingsConfigure()
{
    qCDebug(KNOTEPAD) << "knotepadWindow::settingsConfigure()";
    // The preference dialog is derived from prefs_base.ui
    //
    // compare the names of the widgets in the .ui file
    // to the names of the variables in the .kcfg file
    //avoid to have 2 dialogs shown
    if (KConfigDialog::showDialog(QStringLiteral("settings"))) {
        return;
    }

    KConfigDialog *dialog = new KConfigDialog(this, QStringLiteral("settings"), knotepadSettings::self());
    QWidget *generalSettingsPage = new QWidget;
    m_settings.setupUi(generalSettingsPage);
    dialog->addPage(generalSettingsPage, i18nc("@title:tab", "General"), QStringLiteral("package_setting"));
    connect(dialog, &KConfigDialog::settingsChanged, m_knotepadView, &knotepadView::handleSettingsChanged);
    dialog->setAttribute(Qt::WA_DeleteOnClose);
    dialog->show();
}

#include "moc_knotepadwindow.cpp"
