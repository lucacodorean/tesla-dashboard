#ifndef LOCATIONCONTROLLER_H
#define LOCATIONCONTROLLER_H

#include <QObject>

namespace backend {
    class LocationController : public QObject {

        Q_OBJECT
        Q_PROPERTY(QString  start_point   READ start_point  WRITE set_start_point   NOTIFY   start_pointChanged)
        Q_PROPERTY(QString    end_point   READ end_point    WRITE set_end_point     NOTIFY     end_pointChanged)
        Q_PROPERTY(bool         reset     READ reset        WRITE set_reset         NOTIFY         resetChanged)
        Q_PROPERTY(bool         ready     READ ready        WRITE set_ready         NOTIFY         readyChanged)

        Q_PROPERTY(double  x1   READ x1     WRITE set_x1    NOTIFY   x1Changed)
        Q_PROPERTY(double  y1   READ y1     WRITE set_y1    NOTIFY   y1Changed)

        Q_PROPERTY(double  x2   READ x2     WRITE set_x2    NOTIFY   x2Changed)
        Q_PROPERTY(double  y2   READ y2     WRITE set_y2    NOTIFY   y2Changed)

        public:
            LocationController(QObject* parent = nullptr);
            LocationController(QString start_point, QString end_point, QObject* parent = nullptr);

            Q_INVOKABLE QString end_point();
            Q_INVOKABLE void set_end_point(QString newEnd_point);

            Q_INVOKABLE QString start_point();
            Q_INVOKABLE void set_start_point(QString newStart_point);

            Q_INVOKABLE double y2() const;
            Q_INVOKABLE void set_y2(double newY2);

            Q_INVOKABLE double x2() const;
            Q_INVOKABLE void set_x2(double newX2);

            Q_INVOKABLE double y1() const;
            Q_INVOKABLE void set_y1(double newY1);

            Q_INVOKABLE double x1() const;
            Q_INVOKABLE void set_x1(double newX1);

            Q_INVOKABLE bool reset() const;
            Q_INVOKABLE void set_reset(bool newReset);

            Q_INVOKABLE bool ready() const;
            Q_INVOKABLE void set_ready(bool newReady);

        signals:
            void start_pointChanged();
            void end_pointChanged();

            void y2Changed();
            void x2Changed();

            void y1Changed();
            void x1Changed();

            void resetChanged();
            void readyChanged();

        private:
            QString  m_end_point;
            QString  m_start_point;

            bool matching_location(QString, QString);
            double m_y2;
            double m_x2;
            double m_y1;
            double m_x1;
            bool m_reset;
            bool m_ready;
    };
}

#endif // LOCATIONCONTROLLER_H
