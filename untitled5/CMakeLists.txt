cmake_minimum_required(VERSION 3.5)

project(untitled5 VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets Core Gui Graphs Charts)
find_package(Qt6 REQUIRED COMPONENTS Graphs)
find_package(Qt6 REQUIRED COMPONENTS Charts)
find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core Gui Widgets Graphs Charts)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets PrintSupport)

set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(untitled5
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        dialog.h dialog.cpp
        dialog.ui
        data.csv
        ../.gitignore
        tables.h tables.cpp tables.ui
        customtablewidgetitem.h customtablewidgetitem.cpp
        structure_player.h
        players.h
    )
else()
    if(ANDROID)
        add_library(untitled5 SHARED
            ${PROJECT_SOURCES}
        )
    else()
        add_executable(untitled5
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(untitled5 PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
target_link_libraries(untitled5 PRIVATE Qt${QT_VERSION_MAJOR}::Graphs)
target_link_libraries(untitled5 PRIVATE Qt${QT_VERSION_MAJOR}::Core)
target_link_libraries(untitled5 PRIVATE Qt${QT_VERSION_MAJOR}::Gui)
target_link_libraries(untitled5 PRIVATE Qt${QT_VERSION_MAJOR}::Charts)
target_link_libraries(untitled5 PRIVATE Qt${QT_VERSION_MAJOR}::Widgets PRIVATE Qt${QT_VERSION_MAJOR}::PrintSupport)

if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.untitled5)
endif()
set_target_properties(untitled5 PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS untitled5
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(untitled5)
endif()
