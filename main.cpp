#include <QApplication>
#include <QCoreApplication>
#include <QTime>
#include <QTimer>
#include <QDebug>
#include "sshotfile.h"

QCoreApplication* createApplication(int &argc, char *argv[])
{
    for (int i = 1; i < argc; ++i)
        if (!qstrcmp(argv[i], "-no-gui"))
            return new QCoreApplication(argc, argv);
    return new QApplication(argc, argv);
}

int main(int argc, char *argv[])
{
    QScopedPointer<QCoreApplication> a(createApplication(argc, argv));

    SShotFile *sfile = new SShotFile;

    QString format;
    QString path;

    format = "png";
    path = "/Users/ilyamisyura/";

    sfile->setFormat(format);
    sfile->setPath(path);

    QTimer *timer = new QTimer;
    QObject::connect(timer, &QTimer::timeout, sfile, &SShotFile::save);
    timer->start(3000);

    return a->exec();
}
