cmake_minimum_required(VERSION 3.20)

project(vtk_test)

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

add_executable(vtk_test vtk_test.cpp)

target_link_libraries(vtk_test PRIVATE ${ITK_LIBRARIES} ${VTK_IBRARIES})

# vtk_module_autoinit is needed
vtk_module_autoinit(
  TARGETS ${PROJECT_NAME}
  MODULES ${VTK_LIBRARIES}
)