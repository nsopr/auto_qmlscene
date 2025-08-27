#include <QApplication>
#include <QQmlApplicationEngine>
#include <QFontDatabase>
#include <QQmlContext>
#include <QStyle>

#include "process.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QStyle *style = a.style();
    a.setWindowIcon(style->standardIcon(QStyle::SP_TitleBarMenuButton));

    QCoreApplication::setOrganizationName("nsopr");
    QCoreApplication::setApplicationName("autoQMLscene");

    process p;

    //QML
    QQmlApplicationEngine engine;
    QUrl url("qrc:/Main.qml");

    engine.rootContext()->setContextProperty("process", &p);
    engine.rootContext()->setContextProperty("qmlscenepath", p.qmlscene);
    engine.rootContext()->setContextProperty("qmlfilepath", p.qmlfile);

    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &a, [url](QObject *obj, const QUrl &objUrl) {
                         if (!obj && url == objUrl)
                             QCoreApplication::exit(-1);
                     }, Qt::QueuedConnection);
    engine.load(url);

    return a.exec();
}
