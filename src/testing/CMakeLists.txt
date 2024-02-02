cmake_minimum_required(VERSION 3.20)

project(testing)

set_property(DIRECTORY PROPERTY EP_BASE ${CMAKE_BINARY_DIR}/subprojects)

set(STAGED_INSTALL_PREFIX ${CMAKE_BINARY_DIR}/stage)
message(STATUS "${PROJECT_NAME} staged install: ${STAGED_INSTALL_PREFIX}")

include(ExternalProject)

ExternalProject_Add(${PROJECT_NAME}
  DEPENDS
    VTK_external
    ITK_external
  SOURCE_DIR
    ${CMAKE_CURRENT_LIST_DIR}/vtk_testing
  CMAKE_ARGS
    -DVTK_DIR=${VTK_DIR}
    -DITK_DIR=${ITK_DIR}
  CMAKE_CACHE_ARGS
    -DCMAKE_C_FLAGS:STRING=${CMAKE_C_FLAGS}
    -DCMAKE_PREFIX_PATH:PATH=${CMAKE_PREFIX_PATH}
  BUILD_ALWAYS
    1
  INSTALL_COMMAND
    ""
)