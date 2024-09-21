#include <QtQml/qqmlprivate.h>
#include <QtCore/qdir.h>
#include <QtCore/qurl.h>
#include <QtCore/qhash.h>
#include <QtCore/qstring.h>

namespace QmlCacheGeneratedCode {
namespace _qt_qml_teslaCP_ui_Main_qml { 
    extern const unsigned char qmlData[];
    extern const QQmlPrivate::AOTCompiledFunction aotBuiltFunctions[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), &aotBuiltFunctions[0], nullptr
    };
}
namespace _qt_qml_teslaCP_ui_TaskBar_TaskBar_qml { 
    extern const unsigned char qmlData[];
    extern const QQmlPrivate::AOTCompiledFunction aotBuiltFunctions[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), &aotBuiltFunctions[0], nullptr
    };
}
namespace _qt_qml_teslaCP_ui_TaskBar_Volume_qml { 
    extern const unsigned char qmlData[];
    extern const QQmlPrivate::AOTCompiledFunction aotBuiltFunctions[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), &aotBuiltFunctions[0], nullptr
    };
}
namespace _qt_qml_teslaCP_ui_TaskBar_Acclimatization_qml { 
    extern const unsigned char qmlData[];
    extern const QQmlPrivate::AOTCompiledFunction aotBuiltFunctions[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), &aotBuiltFunctions[0], nullptr
    };
}
namespace _qt_qml_teslaCP_ui_RightScreen_RightScreen_qml { 
    extern const unsigned char qmlData[];
    extern const QQmlPrivate::AOTCompiledFunction aotBuiltFunctions[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), &aotBuiltFunctions[0], nullptr
    };
}
namespace _qt_qml_teslaCP_ui_LeftScreen_LeftScreen_qml { 
    extern const unsigned char qmlData[];
    extern const QQmlPrivate::AOTCompiledFunction aotBuiltFunctions[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), &aotBuiltFunctions[0], nullptr
    };
}
namespace _qt_qml_teslaCP_ui_RightScreen_MapConfig_qml { 
    extern const unsigned char qmlData[];
    extern const QQmlPrivate::AOTCompiledFunction aotBuiltFunctions[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), &aotBuiltFunctions[0], nullptr
    };
}
namespace _qt_qml_teslaCP_ui_RightScreen_TopBar_qml { 
    extern const unsigned char qmlData[];
    extern const QQmlPrivate::AOTCompiledFunction aotBuiltFunctions[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), &aotBuiltFunctions[0], nullptr
    };
}
namespace _qt_qml_teslaCP_ui_RightScreen_SearchBar_qml { 
    extern const unsigned char qmlData[];
    extern const QQmlPrivate::AOTCompiledFunction aotBuiltFunctions[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), &aotBuiltFunctions[0], nullptr
    };
}

}
namespace {
struct Registry {
    Registry();
    ~Registry();
    QHash<QString, const QQmlPrivate::CachedQmlUnit*> resourcePathToCachedUnit;
    static const QQmlPrivate::CachedQmlUnit *lookupCachedUnit(const QUrl &url);
};

Q_GLOBAL_STATIC(Registry, unitRegistry)


Registry::Registry() {
    resourcePathToCachedUnit.insert(QStringLiteral("/qt/qml/teslaCP/ui/Main.qml"), &QmlCacheGeneratedCode::_qt_qml_teslaCP_ui_Main_qml::unit);
    resourcePathToCachedUnit.insert(QStringLiteral("/qt/qml/teslaCP/ui/TaskBar/TaskBar.qml"), &QmlCacheGeneratedCode::_qt_qml_teslaCP_ui_TaskBar_TaskBar_qml::unit);
    resourcePathToCachedUnit.insert(QStringLiteral("/qt/qml/teslaCP/ui/TaskBar/Volume.qml"), &QmlCacheGeneratedCode::_qt_qml_teslaCP_ui_TaskBar_Volume_qml::unit);
    resourcePathToCachedUnit.insert(QStringLiteral("/qt/qml/teslaCP/ui/TaskBar/Acclimatization.qml"), &QmlCacheGeneratedCode::_qt_qml_teslaCP_ui_TaskBar_Acclimatization_qml::unit);
    resourcePathToCachedUnit.insert(QStringLiteral("/qt/qml/teslaCP/ui/RightScreen/RightScreen.qml"), &QmlCacheGeneratedCode::_qt_qml_teslaCP_ui_RightScreen_RightScreen_qml::unit);
    resourcePathToCachedUnit.insert(QStringLiteral("/qt/qml/teslaCP/ui/LeftScreen/LeftScreen.qml"), &QmlCacheGeneratedCode::_qt_qml_teslaCP_ui_LeftScreen_LeftScreen_qml::unit);
    resourcePathToCachedUnit.insert(QStringLiteral("/qt/qml/teslaCP/ui/RightScreen/MapConfig.qml"), &QmlCacheGeneratedCode::_qt_qml_teslaCP_ui_RightScreen_MapConfig_qml::unit);
    resourcePathToCachedUnit.insert(QStringLiteral("/qt/qml/teslaCP/ui/RightScreen/TopBar.qml"), &QmlCacheGeneratedCode::_qt_qml_teslaCP_ui_RightScreen_TopBar_qml::unit);
    resourcePathToCachedUnit.insert(QStringLiteral("/qt/qml/teslaCP/ui/RightScreen/SearchBar.qml"), &QmlCacheGeneratedCode::_qt_qml_teslaCP_ui_RightScreen_SearchBar_qml::unit);
    QQmlPrivate::RegisterQmlUnitCacheHook registration;
    registration.structVersion = 0;
    registration.lookupCachedQmlUnit = &lookupCachedUnit;
    QQmlPrivate::qmlregister(QQmlPrivate::QmlUnitCacheHookRegistration, &registration);
}

Registry::~Registry() {
    QQmlPrivate::qmlunregister(QQmlPrivate::QmlUnitCacheHookRegistration, quintptr(&lookupCachedUnit));
}

const QQmlPrivate::CachedQmlUnit *Registry::lookupCachedUnit(const QUrl &url) {
    if (url.scheme() != QLatin1String("qrc"))
        return nullptr;
    QString resourcePath = QDir::cleanPath(url.path());
    if (resourcePath.isEmpty())
        return nullptr;
    if (!resourcePath.startsWith(QLatin1Char('/')))
        resourcePath.prepend(QLatin1Char('/'));
    return unitRegistry()->resourcePathToCachedUnit.value(resourcePath, nullptr);
}
}
int QT_MANGLE_NAMESPACE(qInitResources_qmlcache_appteslaCP)() {
    ::unitRegistry();
    return 1;
}
Q_CONSTRUCTOR_FUNCTION(QT_MANGLE_NAMESPACE(qInitResources_qmlcache_appteslaCP))
int QT_MANGLE_NAMESPACE(qCleanupResources_qmlcache_appteslaCP)() {
    return 1;
}
