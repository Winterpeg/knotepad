/*
    SPDX-FileCopyrightText: 2025 Mike Young <harnmaster@gmail.com>

    SPDX-License-Identifier: GPL-2.0-only OR GPL-3.0-only OR LicenseRef-KDE-Accepted-GPL
*/

#ifndef KNOTEPADVIEW_H
#define KNOTEPADVIEW_H

#include "ui_knotepadview.h"


/**
 * This class serves as the main window for knotepad.  It handles the
 * menus, toolbars and status bars.
 *
 * @short Main window class
 * @author Mike Young <harnmaster@gmail.com>
 * @version 0.1
 */
class knotepadView : public QWidget
{
    Q_OBJECT
public:
    /**
     * Default Constructor
     */
    explicit knotepadView(QWidget *parent);

    /**
     * Default Destructor
     */
    ~knotepadView() override;

public Q_SLOTS:
    void switchColors();
    void handleSettingsChanged();

private:
    // this is the name of the root widget inside our Ui file
    // you can rename it in designer and then change it here
    Ui::knotepadView m_ui;
};

#endif // KNOTEPADVIEW_H
