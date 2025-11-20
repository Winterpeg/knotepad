add_executable(knotepad)

target_sources(knotepad PRIVATE
    main.cpp
    knotepadwindow.cpp
    knotepadview.cpp
    knotepad.qrc
)

ecm_qt_declare_logging_category(knotepad
    HEADER knotepaddebug.h
    IDENTIFIER KNOTEPAD
    CATEGORY_NAME "knotepad"
)
kconfig_add_kcfg_files(knotepad knotepadSettings.kcfgc)
ki18n_wrap_ui(knotepad
    knotepadview.ui
    settings.ui
)

target_link_libraries(knotepad
    KF6::CoreAddons
    KF6::I18n
    KF6::XmlGui
    KF6::ConfigWidgets
    KF6::DBusAddons
    KF6::Crash
    Qt6::Widgets
)

install(TARGETS knotepad ${KDE_INSTALL_TARGETS_DEFAULT_ARGS})
install(PROGRAMS org.example.knotepad.desktop  DESTINATION ${KDE_INSTALL_APPDIR})
install(FILES org.example.knotepad.metainfo.xml DESTINATION ${KDE_INSTALL_METAINFODIR})
