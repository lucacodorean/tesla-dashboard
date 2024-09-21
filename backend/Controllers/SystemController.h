#ifndef SYSTEMCONTROLLER_H
#define SYSTEMCONTROLLER_H

#include <qobject.h>
#include <QTimer>

namespace backend {
    class SystemController : public QObject {

        Q_OBJECT
        Q_PROPERTY(bool    car_locked               READ car_locked    WRITE set_car_locked        NOTIFY car_lockedChanged)
        Q_PROPERTY(double  temperature              READ temperature   WRITE set_car_temperature   NOTIFY temperatureChanged)
        Q_PROPERTY(QString user                     READ user          WRITE set_user              NOTIFY userChanged)
        Q_PROPERTY(QString current_time_display     READ current_time  WRITE set_current_time      NOTIFY timeChanged)


        public:
            explicit SystemController(QObject *parent = nullptr);

            Q_INVOKABLE bool car_locked() const;
            Q_INVOKABLE void set_car_locked(bool newCar_locked);

            Q_INVOKABLE double temperature() const;
            Q_INVOKABLE void set_car_temperature(double newTemperatue);


            Q_INVOKABLE QString user() const;
            Q_INVOKABLE void set_user(const QString &newUser);

            Q_INVOKABLE QString current_time() const;
            Q_INVOKABLE void set_current_time(const QString &newCurrent_time);



        signals:
            void car_lockedChanged();
            void temperatureChanged();
            void userChanged();
            void timeChanged();

        private:
            bool     m_car_locked;
            double   m_temperature;
            QString  m_user;
            QString  m_current_time_display;
            QTimer  *m_current_time;

            void     current_time_checkout();
    };
}

#endif // SYSTEMCONTROLLER_H
