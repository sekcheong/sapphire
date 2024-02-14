cmake_minimum_required(VERSION 3.20)

if (CMAKE_VERSION VERSION_GREATER_EQUAL "3.24.0")
  cmake_policy(SET CMP0135 NEW)
endif()

find_package(VTK CONFIG QUIET)

if(VTK_FOUND)  
  message(STATUS "Found VTK version ${VTK_MAJOR_VERSION}.${VTK_MINOR_VERSION}.${VTK_BUILD_VERSION} in ${VTK_DIR}")
  add_library(VTK_external INTERFACE)
  return()
endif()

message(STATUS "Suitable VTK could not be located. Building from source.")

include(ExternalProject)
ExternalProject_Add(VTK_external
  GIT_REPOSITORY
    https://github.com/Kitware/VTK.git
  GIT_TAG      
    v9.2.6
  CMAKE_ARGS
    -DCMAKE_INSTALL_PREFIX=${STAGED_INSTALL_PREFIX}      
    -DVTK_WRAP_PYTHON=OFF
    -DVTK_WRAP_JAVA=OFF
    -DVTK_BUILD_TESTING=OFF      
    -DBUILD_SHARED_LIBS=OFF
)

set(
  VTK_DIR ${STAGED_INSTALL_PREFIX}/${CMAKE_INSTALL_LIBDIR}/cmake/vtk-9.2
  CACHE PATH "Path to internally built VTKConfig.cmake"
  FORCE
)