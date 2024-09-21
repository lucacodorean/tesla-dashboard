#ifndef TEMPERATURECONTROLLER_H
#define TEMPERATURECONTROLLER_H

#include <QObject>

namespace backend {
    class TemperatureController : public QObject {
        Q_OBJECT

        Q_PROPERTY(double  inside_temperature READ inside_temperature    WRITE set_inside_temperature        NOTIFY inside_temperatureChanged)


        public:
            explicit TemperatureController(QObject* object = nullptr);

            Q_INVOKABLE double  inside_temperature() const;
            Q_INVOKABLE void    set_inside_temperature(double newInside_temperature);

        signals:
            void inside_temperatureChanged();

        private:
            double m_inside_temperature;
    };

}


#endif // TEMPERATURECONTROLLER_H
