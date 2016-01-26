#ifndef SCREENSHOT_H
#define SCREENSHOT_H

#include <QPixmap>
#include <QScreen>
#include <QDateTime>
#include <QApplication>
#include <QDesktopWidget>

class Screenshot
{

public:
    Screenshot();

private:
    QPixmap screenData;
    QDateTime shotMoment;


public:
    void shoot();
    QString timeWhen();
    QString dateWhen();
    bool gotData();
    QPixmap getData();
};

#endif // SCREENSHOT_H
