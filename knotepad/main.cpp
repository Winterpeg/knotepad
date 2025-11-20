#include <QApplication>
#include <QCommandLineParser>
#include <QDir>
#include <QUrl>
#include <KAboutData>
#include <KLocalization>
#include "knotepad.h"

int main (int argc, char *argv[])
{
    using namespace Qt::Literals::StringLiterals;

    QApplication app(argc, argv);
    KLocalizedString::setApplicationDomain("knotepad");
    KAboutData aboutData(
        u"Knotepad"_s,
        i18n("Knotepad"),
        u"1.0"_s,
        i18n("A simple ASCII text editor"),
        KAboutLicense::GPL_V2,
        i18n("(c) 2025"),
        u"https://github.com/Winterpeg/knotepad"_s,
        u"submit@harnmaster@gmail.com"_s);

    aboutData.addAuthor(
        i18n("Michael Young"),
        i18n("Based on code from kxmlgui_tutorial"),
        u"harnmaster@gmail.com"_s,
        u"Winterpeg"_s
    );

    KAboutData::setApplicationData(aboutData);

    QCommandLineParser parser;
    aboutData.setupCommandLine(&parser);
    parser.addPositionalArgument(u"file"_s, i18n("Document to open"));

    parser.process(app);
    aboutData.processCommandLine(&parser);

    MainWindow *window = new MainWindow();
    window->show();

    if (parser.positionalArguments().count() > 0) {
        window->openFileFromURL(QUrl::fromUserInput(
            parser.positionalArguments().at(0),
            QDir::currentPath()));
    }

    return app.exec();
}

