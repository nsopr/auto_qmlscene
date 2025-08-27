#ifndef PROCESS_H
#define PROCESS_H

#include <QObject>
#include <QProcess>
#include <QTimerEvent>
#include <QDebug>

class process : public QObject
{
    Q_OBJECT
public:
    process();

    int interval = startTimer(1000 * 5);

    //from QML
    bool checked = false;
    QString qmlscene, qmlfile;

protected:
    void timerEvent(QTimerEvent *event);

public slots:
    void checkState(bool tf, QString scene, QString file);
};

#endif // PROCESS_H
