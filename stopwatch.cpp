#include "stopwatch.h"
//#include <QTimer>

StopWatch::StopWatch(QObject *parent) : QObject{parent}
{
    time.setHMS(0, 0, 0, 0);
    stopTime.setHMS(0, 0, 0, 0);
    circleTime = 0;
    count = 1;

    timer = new QTimer(this);
    timer->setInterval(100);
    connect(timer, &QTimer::timeout, this, &StopWatch::updateTime);
}

StopWatch::~StopWatch()
{
    delete timer;
}

void StopWatch::updateTime()
{
    time = time.addMSecs(100);
    strCurrentTime = time.toString("mm:ss.z");
    emit sig_updateTime(strCurrentTime);
}

void StopWatch::startTimer()
{
    timer->start();
    updateTime();
}

void StopWatch::stopTimer()
{
    timer->stop();
}

void StopWatch::rcv_circleTime()
{
    circleTime = stopTime.secsTo(time);
    strCircleTime = "Круг " + QString::number(count) + " , время: " + QString::number(circleTime) + " сек";
    stopTime = time;
    count++;
}

void StopWatch::rcv_clearTime()
{
    count = 1;
    time.setHMS(0, 0, 0, 0);
    stopTime.setHMS(0, 0, 0, 0);
}
