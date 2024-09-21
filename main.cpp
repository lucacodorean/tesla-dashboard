#include <QQmlContext>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <backend/Controllers/SystemController.h>
#include <backend/Controllers/TemperatureController.h>
#include <backend/Controllers/VolumeController.h>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection
    );


    QQmlContext* context (engine.rootContext());
    backend::SystemController       m_systemHandler(nullptr);
    backend::TemperatureController  m_driver_temperatureHandler(nullptr);
    backend::TemperatureController  m_passenger_temperatureHandler(nullptr);
    backend::VolumeController       m_volumeHandler(nullptr);

    context->setContextProperty("systemHandler",        &m_systemHandler);
    context->setContextProperty("dTemperatureHandler",  &m_driver_temperatureHandler);
    context->setContextProperty("pTemperatureHandler",  &m_passenger_temperatureHandler);
    context->setContextProperty("volumeHandler",        &m_volumeHandler);

    engine.loadFromModule("teslaCP", "Main");
    return app.exec();
}
