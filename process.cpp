#include "process.h"

process::process() {
    qmlscene = settings.value("qmlscenepath").toString();
    qmlfile  = settings.value("qmlfilepath").toString();
}

void process::timerEvent(QTimerEvent *event){
    if(event->timerId() == interval){
        if(checked){
            QStringList arg;
            arg << qmlfile;
            QFileInfo info;
            info.setFile(qmlfile);

            if(info.lastModified() != lastModified){
                if(proc->isOpen()) proc->close();
                proc->start(qmlscene, arg);
                lastModified = info.lastModified();
            }
        }
    }
}

void process::checkState(bool tf, QString scene, QString file){
    checked  = tf;
    qmlscene = scene;
    qmlfile  = file;

    if(qmlscene.contains("file:///")) qmlscene.remove("file:///");
    if(qmlfile.contains("file:///")) qmlfile.remove("file:///");

    settings.setValue("qmlscenepath", qmlscene);
    settings.setValue("qmlfilepath", qmlfile);
}
