#include "CpuInfoDataModel.hpp"

#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include <qqmlengine.h>
#include <qqmlcontext.h>

namespace {
constexpr auto CPU_INFO_FILENAME = "/proc/cpuinfo";
}

int main(int argc, char ** argv)
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    //Create data model object
    CpuInfoDataModel cpuInfoDataModel(CPU_INFO_FILENAME);

    //Register data model object to QML UI
    engine.rootContext()->setContextProperty("cpuInfoDataModel",
                                             &cpuInfoDataModel);

    engine.load(QUrl(QLatin1String("qrc:/main.qml")));

    return app.exec();
}
