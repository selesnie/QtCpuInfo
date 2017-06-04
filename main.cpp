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

    FileReader data;
    QVector<CpuCore> vec = data.readAndParseFile();

    CpuDataModel model;

    for (const auto& item : vec)
    {
        model.addCpuCore(item);
    }

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("myModel",
                                             &model);

    engine.load(QUrl(QLatin1String("qrc:/main.qml")));

    return app.exec();
}
