#include "CpuInfoDataModel.hpp"

#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include <qqmlengine.h>
#include <qqmlcontext.h>

int main(int argc, char ** argv)
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    CpuInfoDataModel cpuInfoDataModel;

    //Register data model object to QML UI
    engine.rootContext()->setContextProperty("cpuInfoDataModel",
                                             &cpuInfoDataModel);

    engine.load(QUrl(QLatin1String("qrc:/main.qml")));

    return app.exec();
}
