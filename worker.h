#ifndef WORKER_H
#define WORKER_H

#include <QObject>
#include <QMutex>
#include <QTime>

class Worker : public QObject
{
    Q_OBJECT
public:
    explicit Worker(QObject *parent = 0);

private:
    QString *gsChronoValue;
    QTime gobTime;
    long start;
    long end;
    unsigned long time;
    unsigned long milis;
    unsigned int seconds;
    unsigned int minutes;
    int giStopFlag;

signals:
    void resultReady(QString result);
    void finished();

public slots:
    void launchChrono();
    void resetChrono();
};

#endif // WORKER_H
