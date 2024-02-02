cmake_minimum_required(VERSION 3.20)

project(vtk_testing)

find_package(VTK COMPONENTS
  CommonColor
  CommonCore
  CommonDataModel
  FiltersCore
  FiltersGeneral
  FiltersSources
  IOImage
  InteractionStyle
  RenderingContextOpenGL2
  RenderingCore
  RenderingFreeType
  RenderingGL2PSOpenGL2
  RenderingOpenGL2
)
if (NOT VTK_FOUND)
  message(FATAL_ERROR "vtk_test: Unable to find the VTK build folder.")
endif()

find_package(ITK REQUIRED)

include(${ITK_USE_FILE})

# Prevent a "command line is too long" failure in Windows.
set(CMAKE_NINJA_FORCE_RESPONSE_FILE "ON" CACHE BOOL "Force Ninja to use response files.")

add_executable(TissueLens MACOSX_BUNDLE TissueLens.cpp )
  target_link_libraries(${PROJECT_NAME} PRIVATE ${VTK_LIBRARIES} ${ITK_LIBRARIES}}
)
# vtk_module_autoinit is needed
vtk_module_autoinit(
  TARGETS ${PROJECT_NAME}
  MODULES ${VTK_LIBRARIES}
)