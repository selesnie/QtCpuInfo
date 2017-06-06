#include "CpuDataModel.hpp"
#include "FileReader.hpp"
#include <TimerCallback.hpp>

#include <QGuiApplication>
#include <qqmlengine.h>
#include <qqmlcontext.h>
#include <qqml.h>
#include <QtQuick/qquickitem.h>
#include <QtQuick/qquickview.h>

#include <QQmlApplicationEngine>

#include <memory>
#include <future>

int main(int argc, char ** argv)
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    CpuDataModel cpuDataModel;

    FileReader fileReader;
    QVector<CpuCore> cpuCoreVec = fileReader.readAndParseFile();

    for (const auto& cpuCore : cpuCoreVec)
    {
        cpuDataModel.addToModel(cpuCore);
    }

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("cpuDataModel",
                                             &cpuDataModel);

    engine.load(QUrl(QLatin1String("qrc:/main.qml")));

    std::shared_ptr<TimerCallback> timer = std::make_shared<TimerCallback>();

    timer->registerTimerElapsedCallback([&cpuDataModel, &fileReader]()
    {
        cpuDataModel.clearModel();

        auto fut = std::async(std::launch::async, [&cpuDataModel, &fileReader]()
        {
            QVector<CpuCore> cpuCoreVec = fileReader.readAndParseFile();

            for (const auto& cpuCore : cpuCoreVec)
            {
                cpuDataModel.addToModel(cpuCore);
            }
        });
    });

    constexpr auto timeoutMilliseconds = 2000;

    timer->start(timeoutMilliseconds);

    return app.exec();
}
