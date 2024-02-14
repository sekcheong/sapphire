cmake_minimum_required(VERSION 3.20)

if (CMAKE_VERSION VERSION_GREATER_EQUAL "3.24.0")
  cmake_policy(SET CMP0135 NEW)
endif()

find_package(DCMTK CONFIG QUIET)
if(DCMTK_FOUND)  
  message(STATUS "Found DCMTK version ${DCMTK_MAJOR_VERSION}.${DCMTK_MINOR_VERSION}.${DCMTK_BUILD_VERSION} in ${DCMTK_DIR}")
  add_library(DCMTK_external INTERFACE)
  return()
endif()

message(STATUS "Suitable DCMTK could not be located. Building from source.")

include(ExternalProject)
if (WIN32)
  ExternalProject_Add(DCMTK_support_lib
    URL  
      https://dicom.offis.de/download/dcmtk/dcmtk368/support/dcmtk-3.6.8-win64-support-MT-msvc-17.4.zip
    BUILD_COMMAND ""
    CONFIGURE_COMMAND ""
    INSTALL_COMMAND ""
  )

  set(
    DCMTK_SUPPORT_LIB ${STAGED_INSTALL_PREFIX}/SOURCE_DIR
    CACHE PATH "Path to DCMTK support library files."
    FORCE
  )
endif()  

ExternalProject_Add(DCMTK_external
  GIT_REPOSITORY
    https://github.com/DCMTK/dcmtk.git
  GIT_TAG
    DCMTK-3.6.8
  CMAKE_ARGS
    -DCMAKE_INSTALL_PREFIX=${STAGED_INSTALL_PREFIX}        
    -DBUILD_SHARED_LIBS=OFF
    -DBUILD_STATIC_LIBS=ON
    -DBUILD_TESTING=OFF
    -DBUILD_EXAMPLES=OFF
    -DBUILD_APPS=OFF
IF (WIN32)
  DEPENDS
    DCMTK_support_lib
endif()
)

message("**** DIR: ${STAGED_INSTALL_PREFIX}")

set(
  DCMTK_DIR ${STAGED_INSTALL_PREFIX}/${CMAKE_INSTALL_LIBDIR}/cmake/DCMTK-3.6
  CACHE PATH "Path to internally built DCMTKConfig.cmake"
  FORCE
)