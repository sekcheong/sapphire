find_package(VTK CONFIG QUIET)

if(VTK_FOUND)
  get_property(_loc TARGET VTK::vtk PROPERTY LOCATION)
  message(STATUS "Found VTK: ${_loc} (found version ${VTK_VERSION})")
  add_library(vtk_external INTERFACE)  # dummy
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
      -DCMAKE_INSTALL_PREFIX = ${STAGED_INSTALL_PREFIX}
      -DBUILD_TESTS = OFF    
      -DBUILD_SHARED_LIBS = OFF
  )

  include(GNUInstallDirs)

  set(
    FFTW3_DIR ${STAGED_INSTALL_PREFIX}/${CMAKE_INSTALL_LIBDIR}/cmake/VTK
    CACHE PATH "Path to internally built VTKConfig.cmake"
    FORCE
  )

endif()