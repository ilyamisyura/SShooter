#ifndef SSHOTFILE_H
#define SSHOTFILE_H

#include <QObject>
#include <QDebug>
#include "screenshot.h"

class SShotFile : public QObject
{
    Q_OBJECT
public:
    explicit SShotFile(QObject *parent = 0);

private:
    QString format;
    QString name;
    QString path;
    bool isReadyForSaving();

signals:
    void fileSaved(bool saveSuccess);

public slots:
    void setPath(QString path);
    void setName(QString name);
    void setFormat(QString format);
    QString fullFilename();
    void save();


};

#endif // SSHOTFILE_H
