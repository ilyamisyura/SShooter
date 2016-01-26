#include "screenshot.h"

Screenshot::Screenshot()
{

}

void Screenshot::shoot()
{
    QScreen *screen = QGuiApplication::primaryScreen();
    if (screen) {
        this->shotMoment = QDateTime::currentDateTime();
        this->screenData = screen->grabWindow(0);
    }
}

QString Screenshot::timeWhen()
{
    return this->shotMoment.time().toString();
}

QString Screenshot::dateWhen()
{
    return this->shotMoment.date().toString();
}

bool Screenshot::gotData()
{
    return !this->screenData.isNull();
}

QPixmap Screenshot::getData()
{
    return this->screenData;
}
