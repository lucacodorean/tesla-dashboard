cmake_minimum_required(VERSION 3.16)

project(teslaCP VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTORCC ON)

find_package(Qt6 6.5 REQUIRED COMPONENTS Quick)

qt_standard_project_setup(REQUIRES 6.5)

qt_add_executable(appteslaCP
    main.cpp
)

qt_add_qml_module(appteslaCP
    URI teslaCP
    VERSION 1.0
    QML_FILES
        QML_FILES ui/Main.qml
        QML_FILES ui/TaskBar/TaskBar.qml
        QML_FILES ui/TaskBar/Volume.qml
        QML_FILES ui/TaskBar/Acclimatization.qml

        QML_FILES ui/RightScreen/RightScreen.qml
        QML_FILES ui/LeftScreen/LeftScreen.qml

        QML_FILES ui/RightScreen/MapConfig.qml
        QML_FILES ui/RightScreen/TopBar.qml
        QML_FILES ui/RightScreen/SearchBar.qml
    RESOURCES qml.qrc

    SOURCES backend/Controllers/SystemController.h
    SOURCES backend/Controllers/Implementation/SystemController.cpp
    SOURCES backend/Controllers/TemperatureController.h
    SOURCES backend/Controllers/Implementation/TemperatureController.cpp
    SOURCES backend/Controllers/VolumeController.h
    SOURCES backend/Controllers/Implementation/VolumeController.cpp
)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
set_target_properties(appteslaCP PROPERTIES
#    MACOSX_BUNDLE_GUI_IDENTIFIER com.example.appteslaCP
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appteslaCP
    PRIVATE Qt6::Quick
)

include(GNUInstallDirs)
install(TARGETS appteslaCP
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
