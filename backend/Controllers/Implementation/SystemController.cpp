#include "../SystemController.h"
#include <QDateTime>
backend::SystemController::SystemController(QObject *parent) : QObject(parent), m_car_locked(true), m_temperature(23.4), m_user("Luca") {
    m_current_time = new QTimer(this);
    m_current_time->setInterval(500);
    this->current_time_checkout();

    // de fiecare data cand timerul isi termina intervalul de 500 de ms, face cheama functia de checkout
    // o singura data, din cauza liniei 11.
    m_current_time->setSingleShot(true);
    connect(m_current_time, &QTimer::timeout, this, &SystemController::current_time_checkout);
}


namespace backend {

    bool    SystemController::car_locked()   const { return m_car_locked; }
    double  SystemController::temperature()  const { return m_temperature; }
    QString SystemController::user()         const { return m_user; }
    QString SystemController::current_time() const { return m_current_time_display; }

    void SystemController::set_car_locked(bool newCar_locked) {
        if (m_car_locked == newCar_locked) return;
        m_car_locked = newCar_locked;

        emit car_lockedChanged();
    }

    void SystemController::set_car_temperature(double newTemperature) {
        if (qFuzzyCompare(m_temperature, newTemperature)) return;
        m_temperature = newTemperature;

        emit temperatureChanged();
    }

    void SystemController::set_user(const QString &newUser) {
        if (m_user == newUser) return;
        m_user = newUser;

        emit userChanged();
    }


    void SystemController::set_current_time(const QString &newCurrent_time) {
        if (m_current_time_display == newCurrent_time) return;

        m_current_time_display = newCurrent_time;
        emit timeChanged();
    }


    void SystemController::current_time_checkout() {
        this->set_current_time(QDateTime().currentDateTime().toString("h:m ap"));
        m_current_time->start();
    }

}
