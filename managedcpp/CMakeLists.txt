
    cmake_minimum_required( VERSION 2.6.3 )

    project( ManagedCppQt )

FIND_PACKAGE(QT5 REQUIRED)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
SET(QT_INCLUDE_DIR $ENV{QTDIR}/include)
SET(QT_PLUGINS_DIR $ENV{QTDIR}/plugins)
INCLUDE_DIRECTORIES(${QT_INCLUDE_DIR})

add_subdirectory(pureqt)

add_subdirectory(managedcpp)
