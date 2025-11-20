/*
    SPDX-FileCopyrightText: 2025 Mike Young <harnmaster@gmail.com>

    SPDX-License-Identifier: GPL-2.0-only OR GPL-3.0-only OR LicenseRef-KDE-Accepted-GPL
*/

// application headers
#include "knotepadview.h"

#include "knotepadSettings.h"
#include "knotepaddebug.h"


knotepadView::knotepadView(QWidget *parent)
    : QWidget(parent)
{
    m_ui.setupUi(this);
    handleSettingsChanged();
}

knotepadView::~knotepadView()
{
}

void knotepadView::switchColors()
{
    // switch the foreground/background colors of the label
    QColor color = knotepadSettings::colorBackground();
    knotepadSettings::setColorBackground(knotepadSettings::colorForeground());
    knotepadSettings::setColorForeground(color);

    handleSettingsChanged();
}

void knotepadView::handleSettingsChanged()
{
    qCDebug(KNOTEPAD) << "knotepadView::handleSettingsChanged()";
    QPalette palette = m_ui.templateLabel->palette();
    palette.setColor(QPalette::Window, knotepadSettings::colorBackground());
    palette.setColor(QPalette::WindowText, knotepadSettings::colorForeground());
    m_ui.templateLabel->setPalette(palette);

    // i18n : internationalization
    m_ui.templateLabel->setText(i18n("This project is %1 days old", knotepadSettings::ageInDays()));
}

#include "moc_knotepadview.cpp"
