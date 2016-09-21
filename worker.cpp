#include "worker.h"
#include <QDebug>
#include <QTime>
#include <QLatin1Char>
#include <QThread>
#include <math.h>

Worker::Worker(QObject *parent) :
    QObject(parent)
{
    giStopFlag = 0;
    minutes = 0;
    seconds = 0;
    time = 0;
    milis = 0;
    start = 0;
}

void Worker::launchChrono()
{

    gobTime = QTime::currentTime();
    gobTime.start();
    QThread::msleep(20);
    time += gobTime.elapsed();
    milis = time % 1000;
    if(time >= 1000){
        time = time - 1000;
        seconds++;
    }
    if(seconds == 60){
        if(time >= 1000) time = time - 1000;
        seconds = 0;
        minutes++;
    }

    emit(resultReady(QString("%3:%2:%1")
            .arg(milis,3,10,QLatin1Char('0'))
            .arg(seconds,2,10,QLatin1Char('0'))
            .arg(minutes,2,10,QLatin1Char('0'))));


}

void Worker::resetChrono()
{
    milis = 0;
    seconds = 0;
    minutes = 0;
    time = 0;
}
