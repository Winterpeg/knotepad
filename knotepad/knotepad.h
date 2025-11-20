#ifndef KNOTEPAD_H
#define KNOTEPAD_H

#include <KXmlGuiWindow>

class KTextEdit;
class KJob;

class MainWindow : public KXmlGuiWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent=nullptr);
    void openFileFromURL(const QUrl &outputFileName);

private:
    void setupActions();
    void safeFileToDisk(const QString & outputFileName);

private:
    void newFile();
    void openFile();
    void saveFile();
    void saveFileAs();

    void downloadFinished(KJob *job);

private:
    KTextEdit *textArea;
    QString fileName;

};
#endif //KNOTEPAD_H
