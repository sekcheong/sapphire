find_package(VTK CONFIG QUIET)

if(VTK_FOUND)  
  message(STATUS "Found VTK version ${VTK_MAJOR_VERSION}.${VTK_MINOR_VERSION}.${VTK_BUILD_VERSION} in ${VTK_DIR}")
  add_library(VTK_external INTERFACE)
else()

  message(STATUS "Suitable VTK could not be located. Downloading and building!")

  include(ExternalProject)
  ExternalProject_Add(VTK_external
    URL
      https://github.com/Kitware/VTK/archive/refs/tags/v9.3.0.tar.gz    
    DOWNLOAD_NO_PROGRESS
      1
    UPDATE_COMMAND
      ""
    LOG_CONFIGURE
      1
    LOG_BUILD
      1
    LOG_INSTALL
      1
    CMAKE_ARGS
      -DCMAKE_INSTALL_PREFIX=${STAGED_INSTALL_PREFIX}
      -DBUILD_TESTS=OFF
  )

  include(GNUInstallDirs)

  set(
    VTK_DIR ${STAGED_INSTALL_PREFIX}/${CMAKE_INSTALL_LIBDIR}/cmake/vtk-9.3
    CACHE PATH "Path to internally built VTKConfig.cmake"
    FORCE
  )

endif()