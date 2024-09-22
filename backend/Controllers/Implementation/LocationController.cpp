#include "../LocationController.h"

backend::LocationController::LocationController(QObject* parent) : QObject(parent), m_start_point(""), m_end_point(""), m_reset(false), m_ready(false) {}
backend::LocationController::LocationController(QString  start, QString  stop , QObject* parent) : QObject(parent), m_start_point(start), m_end_point(stop), m_reset(false), m_ready(false) {}

QString backend::LocationController::end_point()    { return this->m_end_point;   }
QString backend::LocationController::start_point()  { return this->m_start_point; }

bool backend::LocationController::matching_location(QString first, QString second) { return first == second; }

void backend::LocationController::set_end_point(QString newEnd_point) {
    if (this->matching_location(this->end_point(), newEnd_point)) return;
    m_end_point = newEnd_point;

    emit end_pointChanged();
}


void backend::LocationController::set_start_point(QString newStart_point) {
    if (this->matching_location(this->start_point(), newStart_point)) return;
    m_start_point = newStart_point;

    emit start_pointChanged();
}


namespace backend {
    double LocationController::y2() const
    {
        return m_y2;
    }

    void LocationController::set_y2(double newY2)
    {
        if (qFuzzyCompare(m_y2, newY2))
            return;
        m_y2 = newY2;
        emit y2Changed();
    }

    double LocationController::x2() const
    {
        return m_x2;
    }

    void LocationController::set_x2(double newX2)
    {
        if (qFuzzyCompare(m_x2, newX2))
            return;
        m_x2 = newX2;
        emit x2Changed();
    }

    double LocationController::y1() const
    {
        return m_y1;
    }

    void LocationController::set_y1(double newY1)
    {
        if (qFuzzyCompare(m_y1, newY1))
            return;
        m_y1 = newY1;
        emit y1Changed();
    }

    double LocationController::x1() const
    {
        return m_x1;
    }

    void LocationController::set_x1(double newX1)
    {
        if (qFuzzyCompare(m_x1, newX1))
            return;
        m_x1 = newX1;
        emit x1Changed();
    }

    bool LocationController::reset() const
    {
        return m_reset;
    }

    void LocationController::set_reset(bool newReset)
    {
        if (m_reset == newReset)
            return;
        m_reset = newReset;
        emit resetChanged();
    }

    bool LocationController::ready() const
    {
        return m_ready;
    }

    void LocationController::set_ready(bool newReady)
    {
        if (m_ready == newReady)
            return;
        m_ready = newReady;
        emit readyChanged();
    }
}
