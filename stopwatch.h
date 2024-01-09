#ifndef STOPWATCH_H
#define STOPWATCH_H

#include <QObject>
#include <QWidget>
#include <QTimer>
#include <QTime>
#include <QDebug>

class StopWatch : public QObject
{
    Q_OBJECT

public:

    QString strCurrentTime;
    QString strCircleTime;

    explicit StopWatch(QObject *parent = nullptr);

    ~StopWatch();

    void updateTime();
    void startTimer();
    void stopTimer();

public slots:

    void rcv_circleTime();
    void rcv_clearTime();


signals:

    void sig_updateTime(QString &strCurrentTime);

private:

    QTimer *timer;
    QTime time;
    QTime stopTime;
    int circleTime;
    int count;

};

#endif // STOPWATCH_H
