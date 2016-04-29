
# These headers need to go through Qt's MOC compiler
set(HEADERS_WITH_QOBJECT
    #SignalProxy.h
)

set( HEADERS
    ManagedCppQt.h
    conversion.h
)

set( QRC_FILES
)

set( CPP_FILES
    ManagedCppQt.cpp
    #SignalProxy.cpp
)


set( SOURCES ${CPP_FILES} ${HEADERS} ${HEADERS_WITH_QOBJECT} )


# Add generated files to SOURCES
set( SOURCES ${SOURCES} ${UI_HEADERS} ${QRC_FILES_CPP} ${MOC_FILES_CPP} )

add_definitions( /EHa )

# if WIN_64 passed by command line
IF(DEFINED WIN64)
    add_definitions( /DWIN64 )
ENDIF(DEFINED WIN64)

ADD_LIBRARY(managedqtdll SHARED ${SOURCES})

if(CMAKE_CXX_FLAGS_DEBUG MATCHES "/RTC1")
    string(REPLACE "/RTC1" " " CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG}")
endif()

if(CMAKE_CXX_FLAGS MATCHES "/EHsc")
    string(REPLACE "/EHsc" "" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
endif()

                MESSAGE("[managedcppqt]     CMAKE_CXX_FLAGS_DEBUG               " ${CMAKE_CXX_FLAGS_DEBUG})
                MESSAGE("[managedcppqt]     CMAKE_CXX_FLAGS                     " ${CMAKE_CXX_FLAGS})
find_package(Qt5Core REQUIRED)

set_target_properties(managedqtdll PROPERTIES COMPILE_FLAGS "/clr")

TARGET_LINK_LIBRARIES(managedqtdll Qt5::Core)
TARGET_LINK_LIBRARIES(managedqtdll qtdll)

set_target_properties(managedqtdll PROPERTIES LINK_FLAGS "/SUBSYSTEM:WINDOWS")

# set the name of the library file
SET_TARGET_PROPERTIES( managedqtdll PROPERTIES OUTPUT_NAME_DEBUG "managedqtdlld" )
SET_TARGET_PROPERTIES( managedqtdll PROPERTIES OUTPUT_NAME_RELEASE "managedqtdll" )
