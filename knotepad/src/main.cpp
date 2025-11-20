/*
    SPDX-FileCopyrightText: 2025 Mike Young <harnmaster@gmail.com>

    SPDX-License-Identifier: GPL-2.0-only OR GPL-3.0-only OR LicenseRef-KDE-Accepted-GPL
*/

// application header
#include "knotepadwindow.h"
#include "knotepaddebug.h"

// KF headers
#include <KCrash>
#include <KDBusService>
#include <KAboutData>
#include <KLocalizedString>

// Qt headers
#include <QApplication>
#include <QCommandLineParser>
#include <QIcon>
#include <QLoggingCategory>


int main(int argc, char **argv)
{
    QApplication application(argc, argv);

    KLocalizedString::setApplicationDomain("knotepad");
    KCrash::initialize();

    KAboutData aboutData(QStringLiteral("knotepad"),
                         i18n("knotepad"),
                         QStringLiteral("0.1"),
                         i18n("A Simple Application written with KDE Frameworks"),
                         KAboutLicense::GPL,
                         i18n("Copyright 2025, Mike Young <harnmaster@gmail.com>"));

    aboutData.addAuthor(i18n("Mike Young"),i18n("Author"), QStringLiteral("harnmaster@gmail.com"));
    aboutData.setOrganizationDomain("example.org");
    aboutData.setDesktopFileName(QStringLiteral("org.example.knotepad"));

    KAboutData::setApplicationData(aboutData);
    application.setWindowIcon(QIcon::fromTheme(QStringLiteral("knotepad")));

    QCommandLineParser parser;
    aboutData.setupCommandLine(&parser);

    parser.process(application);
    aboutData.processCommandLine(&parser);

    KDBusService appDBusService(KDBusService::Multiple | KDBusService::NoExitOnFailure);

    knotepadWindow *window = new knotepadWindow;
    window->show();

    return application.exec();
}
