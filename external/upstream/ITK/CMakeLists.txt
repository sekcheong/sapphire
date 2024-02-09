cmake_minimum_required(VERSION 3.20)
find_package(ITK CONFIG QUIET)

if (CMAKE_VERSION VERSION_GREATER_EQUAL "3.24.0")
  cmake_policy(SET CMP0135 NEW)
endif()

if(ITK_FOUND)  
  message(STATUS "Found ITK version ${ITK_MAJOR_VERSION}.${ITK_MINOR_VERSION}.${ITK_BUILD_VERSION} in ${ITK_DIR}")
  add_library(ITK_external INTERFACE)
else()

  message(STATUS "Suitable ITK could not be located. Building from source.")

  include(ExternalProject)
  ExternalProject_Add(ITK_external
    URL
      https://github.com/InsightSoftwareConsortium/ITK/archive/refs/tags/v5.3.0.tar.gz    
    CMAKE_ARGS
      -DCMAKE_INSTALL_PREFIX=${STAGED_INSTALL_PREFIX}        
      -DBUILD_SHARED_LIBS=OFF
      -DBUILD_STATIC_LIBS=ON
      -DBUILD_TESTING=OFF
      -DBUILD_EXAMPLES=OFF
      -DITK_SKIP_PATH_LENGTH_CHECKS=ON
  )

  include(GNUInstallDirs)

  set(
    ITK_DIR ${STAGED_INSTALL_PREFIX}/${CMAKE_INSTALL_LIBDIR}/cmake/ITK-5.3
    CACHE PATH "Path to internally built ITKConfig.cmake"
    FORCE
  )

endif()