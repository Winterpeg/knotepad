/*
    SPDX-FileCopyrightText: 2025 Mike Young <harnmaster@gmail.com>

    SPDX-License-Identifier: GPL-2.0-only OR GPL-3.0-only OR LicenseRef-KDE-Accepted-GPL
*/

#ifndef KNOTEPADWINDOW_H
#define KNOTEPADWINDOW_H

#include <KXmlGuiWindow>

#include "ui_settings.h"
#include "knotepadSettings.h"

class knotepadView;

/**
 * This class serves as the main window for knotepad.  It handles the
 * menus, toolbars and status bars.
 *
 * @short Main window class
 * @author Mike Young <harnmaster@gmail.com>
 * @version 0.1
 */
class knotepadWindow : public KXmlGuiWindow
{
    Q_OBJECT
public:
    /**
     * Default Constructor
     */
    knotepadWindow();

    /**
     * Default Destructor
     */
    ~knotepadWindow() override;

private Q_SLOTS:
    /**
     * Create a new window
     */
    void fileNew();

    /**
     * Open the settings dialog
     */
    void settingsConfigure();

private:
    // this is the name of the root widget inside our Ui file
    // you can rename it in designer and then change it here
    Ui::Settings m_settings;
    QAction *m_switchAction;
    knotepadView *m_knotepadView;
};

#endif // KNOTEPADWINDOW_H
