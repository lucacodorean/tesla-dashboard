#include <QQmlContext>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <backend/Controllers/SystemController.h>
#include <backend/Controllers/TemperatureController.h>
#include <backend/Controllers/VolumeController.h>
#include <backend/Controllers/LocationController.h>

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
    backend::LocationController     m_gpsHandler(nullptr);

    context->setContextProperty("systemHandler",        &m_systemHandler);
    context->setContextProperty("dTemperatureHandler",  &m_driver_temperatureHandler);
    context->setContextProperty("pTemperatureHandler",  &m_passenger_temperatureHandler);
    context->setContextProperty("volumeHandler",        &m_volumeHandler);
    context->setContextProperty("gpsHandler",           &m_gpsHandler);

    context->setContextProperty("__ML_API_KEY", "eyJhbGciOiJFUzI1NiIsInR5cCI6IkpXVCJ9.eyJhdWQiOiI4ZWFkMWNjOS0wYWJhLTRkNDAtOTU0NS02ZWVkMTljNTA3MjEiLCJleHAiOjE3Mjc0NzA4MDAsImlzcyI6Ik1hZ2ljIExhbmUiLCJqdGkiOiJhYmQzYWQzYi01ZmM4LTRjNGYtOTEwYi1kMWZlYTYwYjExNjcifQ.gyjGRL8Tu_kHey5xAPRPbpLGKGYrtmtTVAt7ZAI_jds_fFjBlGLWpl64-JlnxAyOXvkn5sIA6o27awex6gvJJw");


    engine.loadFromModule("teslaCP", "Main");
    return app.exec();
}
