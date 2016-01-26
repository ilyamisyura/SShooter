#include "sshotfile.h"

SShotFile::SShotFile(QObject *parent) : QObject(parent)
{

}

void SShotFile::setPath(QString path)
{
    this->path = path;
}

void SShotFile::setName(QString name)
{
    this->name = name.replace(":","-");
}

void SShotFile::setFormat(QString format)
{
    this->format = format;
}

QString SShotFile::fullFilename()
{
    return this->path + this->name + "." + this->format;
}

bool SShotFile::isReadyForSaving()
{
    bool ready;
    ready = !this->path.isEmpty() && !this->name.isEmpty() &&
            !this->format.isEmpty();
    return ready;
}

void SShotFile::save()
{

    Screenshot *screenshot = new Screenshot;
    screenshot->shoot();

    this->setName(screenshot->dateWhen()+"-"+screenshot->timeWhen());

    if (this->isReadyForSaving() && screenshot->gotData())
    {
        QPixmap *tmpPixmap = new QPixmap;
        *tmpPixmap = screenshot->getData();
        bool saveSuccess;
        saveSuccess = tmpPixmap->save(this->fullFilename(),0,-1);
        emit fileSaved(saveSuccess);
    }

    delete screenshot;
}
