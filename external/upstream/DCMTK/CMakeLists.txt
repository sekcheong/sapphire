cmake_minimum_required(VERSION 3.20)
find_package(DCMTK CONFIG QUIET)

if (CMAKE_VERSION VERSION_GREATER_EQUAL "3.24.0")
  cmake_policy(SET CMP0135 NEW)
endif()

if(DCMTK_FOUND)  
  message(STATUS "Found DCMTK version ${DCMTK_MAJOR_VERSION}.${DCMTK_MINOR_VERSION}.${DCMTK_BUILD_VERSION} in ${DCMTK_DIR}")
  add_library(DCMTK_external INTERFACE)
else()

  message(STATUS "Suitable DCMTK could not be located. Building from source.")

  include(ExternalProject)
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
  )

  include(GNUInstallDirs)

  set(
    DCMTK_DIR ${STAGED_INSTALL_PREFIX}/${CMAKE_INSTALL_LIBDIR}/cmake/DCMTK-3.6
    CACHE PATH "Path to internally built DCMTKConfig.cmake"
    FORCE
  )

endif()