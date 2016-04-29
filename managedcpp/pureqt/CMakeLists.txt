
# These headers need to go through Qt's MOC compiler
set(HEADERS_WITH_QOBJECT
    PureQt.h
)

set( HEADERS
    PureQt_global.h
)

set( QRC_FILES
)

set( CPP_FILES
    PureQt.cpp
)


set( SOURCES ${CPP_FILES} ${HEADERS} ${HEADERS_WITH_QOBJECT} )

# Add generated files to SOURCES
set( SOURCES ${SOURCES} ${UI_HEADERS} ${QRC_FILES_CPP} ${MOC_FILES_CPP} )

add_definitions(-DMANAGEDCPPQT_LIBRARY)

add_definitions( /EHa )

find_package(Qt5Core REQUIRED)
find_package(Qt5Sql REQUIRED)
find_package(Qt5Xml REQUIRED)

# if WIN_64 passed by command line
IF(DEFINED WIN64)
    add_definitions( /DWIN64 )
ENDIF(DEFINED WIN64)

ADD_LIBRARY(qtdll SHARED ${SOURCES})

TARGET_LINK_LIBRARIES(qtdll Qt5::Core)
TARGET_LINK_LIBRARIES(qtdll Qt5::Xml)
TARGET_LINK_LIBRARIES(qtdll Qt5::Sql)

set_target_properties(qtdll PROPERTIES LINK_FLAGS "/SUBSYSTEM:WINDOWS")

# set the name of the library file
SET_TARGET_PROPERTIES( qtdll PROPERTIES OUTPUT_NAME_DEBUG "qtdlld" )
SET_TARGET_PROPERTIES( qtdll PROPERTIES OUTPUT_NAME_RELEASE "qtdll" )
