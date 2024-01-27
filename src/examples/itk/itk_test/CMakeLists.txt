project(itk_test)

find_package(ITK REQUIRED)
include(${ITK_USE_FILE})

add_executable(itk_test itk_test.cpp)

target_link_libraries(itk_test PRIVATE ${ITK_LIBRARIES})
