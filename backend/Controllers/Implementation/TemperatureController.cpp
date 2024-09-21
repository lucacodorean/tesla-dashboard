#include "../TemperatureController.h"

#include <QDebug>

backend::TemperatureController::TemperatureController(QObject* parent) : QObject(parent), m_inside_temperature(20.0) { }

double backend::TemperatureController::inside_temperature() const {
    return m_inside_temperature;
}

void backend::TemperatureController::set_inside_temperature(double newInside_temperature) {
    if (qFuzzyCompare(m_inside_temperature, newInside_temperature)) return;
    if(newInside_temperature < 16.0 || newInside_temperature > 30.0) return;

    m_inside_temperature = static_cast<int>(newInside_temperature*10);
    m_inside_temperature /= 10.0;
    emit inside_temperatureChanged();
}
