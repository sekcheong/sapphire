cmake_minimum_required(VERSION 3.20)
find_package(VTK CONFIG QUIET)

if(VTK_FOUND)  
  message(STATUS "Found VTK version ${VTK_MAJOR_VERSION}.${VTK_MINOR_VERSION}.${VTK_BUILD_VERSION} in ${VTK_DIR}")
  add_library(VTK_external INTERFACE)
else()

  message(STATUS "Suitable VTK could not be located. Building from source.")

  include(ExternalProject)
  ExternalProject_Add(VTK_external
    URL
      https://github.com/Kitware/VTK/archive/refs/tags/v9.2.0.tar.gz    
    CMAKE_ARGS
      -DCMAKE_INSTALL_PREFIX=${STAGED_INSTALL_PREFIX}      
      -DVTK_WRAP_PYTHON=OFF
      -DVTK_WRAP_JAVA=OFF
      -DVTK_BUILD_TESTING=OFF      
      -DBUILD_SHARED_LIBS=OFF
  )

  include(GNUInstallDirs)

  set(
    VTK_DIR ${STAGED_INSTALL_PREFIX}/${CMAKE_INSTALL_LIBDIR}/cmake/vtk-9.2
    CACHE PATH "Path to internally built VTKConfig.cmake"
    FORCE
  )

endif()