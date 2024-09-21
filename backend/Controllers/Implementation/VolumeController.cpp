#include "../VolumeController.h"
#include <QDebug>
namespace backend {

    VolumeController::VolumeController(QObject* parent) : QObject(parent), m_volume(20) { }

    int VolumeController::volume() const{ return m_volume; }

    void VolumeController::set_volume(const int newVolume) {
        if (m_volume == newVolume) return;
        if(newVolume < 0 || newVolume > 100) return;

        m_volume = newVolume;
        emit volumeChanged();
    }
}
