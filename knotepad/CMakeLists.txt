cmake_minimum_required(VERSION 3.30)

project(knotepad)

set(QT_MIN_VERSION "6.9.3")
set(KF_MIN_VERSION "6.19.0")

find_package(ECM ${KF_MIN_VERSION} REQUIRED)
set(CMAKE_MODULE_PATH ${ECM_MODULE_PATH} ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

include(KDEInstallDirs)
include(KDECMakeSettings)
include(KDECompilerSettings NO_POLICY_SCOPE)

#include(ECMInstallIcons)
#include(ECMQtDeclareLoggingCategory)
include(FeatureSummary)

find_package(Qt6 ${QT_MIN_VERSION} REQUIRED COMPONENTS
    Core
    #Gui
    Widgets
)

find_package(KF6 ${KF_MIN_VERSION} REQUIRED COMPONENTS
    ConfigWidgets
    CoreAddons
    Crash
    DBusAddons
    DocTools
    I18n
    XmlGui
    TextWidgets
    WidgetsAddons
    KIO
)

add_executable(knotepad)

target_sources(knotepad
    PRIVATE
    main.cpp
    knotepad.cpp
)

target_link_libraries(knotepad
    Qt6::Widgets
    KF6::CoreAddons
    KF6::XmlGui
    KF6::TextWidgets
    KF6::I18n
    KF6::ConfigWidgets
    KF6::WidgetsAddons
    KF6::KIOCore
)

# add_subdirectory(doc)
# add_subdirectory(src)
# add_subdirectory(icons)
#
# # Make it possible to use the po files fetched by the fetch-translations step
# ki18n_install(po)
# kdoctools_install(po)
#

install(TARGETS knotepad ${KDE_INSTALL_TARGETS_DEFAULT_ARGS})
install(FILES knotepadui.rc DESTINATION ${KDE_INSTALL_KXMLGUIDIR}/knotepad)

feature_summary(WHAT ALL INCLUDE_QUIET_PACKAGES FATAL_ON_MISSING_REQUIRED_PACKAGES)
