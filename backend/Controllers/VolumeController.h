#ifndef VOLUMECONTROLLER_H
#define VOLUMECONTROLLER_H

#include <QObject>


namespace backend {
    class VolumeController : public QObject {
        Q_OBJECT
        Q_PROPERTY(int volume  READ volume  WRITE set_volume NOTIFY volumeChanged)

    public:
        explicit VolumeController(QObject* parent = nullptr);

        Q_INVOKABLE int      volume() const;
        Q_INVOKABLE void     set_volume(const int newVolume);

    signals:
        void volumeChanged();

    private:
        int m_volume;
    };
}

#endif // VOLUMECONTROLLER_H
