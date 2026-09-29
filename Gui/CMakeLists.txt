cmake_minimum_required(VERSION 3.16)

project(Gui VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Quick QuickControls2)
qt_standard_project_setup()

set(QWINDOWKIT_BUILD_INSTALL OFF CACHE BOOL "" FORCE)
set(QWINDOWKIT_BUILD_QUICK ON CACHE BOOL "" FORCE)
set(QWINDOWKIT_BUILD_WIDGETS OFF CACHE BOOL "" FORCE)
set(QWINDOWKIT_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(QWINDOWKIT_ENABLE_WINDOWS_SYSTEM_BORDERS OFF CACHE BOOL "" FORCE)
add_subdirectory(3rdparty/qwindowkit)

qt_add_executable(appGui
    main.cpp
)

qt_add_qml_module(appGui
    URI Gui
    VERSION 1.0
    QML_FILES
        Main.qml
        tabs/CombatTab.qml
        tabs/EffectsTab.qml
        tabs/MovementTab.qml
        components/NeonButton.qml
        components/CustomCheckbox.qml
        components/MenuTabButton.qml
)

set_target_properties(appGui PROPERTIES
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appGui
    PRIVATE
        Qt6::Quick
        Qt6::QuickControls2
        QWindowKit::Quick
)

include(GNUInstallDirs)
install(TARGETS appGui
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
