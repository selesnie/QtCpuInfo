#include "CpuDataModel.hpp"

#include <QGuiApplication>
#include <qqmlengine.h>
#include <qqmlcontext.h>
#include <qqml.h>
#include <QtQuick/qquickitem.h>
#include <QtQuick/qquickview.h>

#include "FileReader.hpp"

#include <QQmlApplicationEngine>

int main(int argc, char ** argv)
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    FileReader fileReader;
    QVector<CpuCore> cpuCoreVec = fileReader.readAndParseFile();

    CpuDataModel cpuDataModel;

    for (const auto& cpuCore : cpuCoreVec)
    {
        cpuDataModel.addCpuCore(cpuCore);
    }

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("cpuDataModel",
                                             &cpuDataModel);

    engine.load(QUrl(QLatin1String("qrc:/main.qml")));
    return app.exec();
}
