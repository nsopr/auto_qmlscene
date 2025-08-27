#include "process.h"

process::process() {}

void process::timerEvent(QTimerEvent *event){
    if(event->timerId() == interval){
        if(checked){
            QProcess proc;
            QStringList arg;
            arg << qmlfile;
            proc.start(qmlscene, arg);
        }
    }
}

void process::checkState(bool tf, QString scene, QString file){
    checked  = tf;
    qmlscene = scene;
    qmlfile  = file;

    qDebug() << checked << qmlscene << qmlfile;
}
