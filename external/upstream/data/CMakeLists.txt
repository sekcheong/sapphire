
cmake_minimum_required(VERSION 3.20)
include(ExternalProject)

ExternalProject_Add(VTK_external_data
    URL https://github.com/sekcheong/sapphire/releases/download/v0/data.zip
    CONFIGURE_COMMAND ""
    BUILD_COMMAND ""
    INSTALL_COMMAND ""
)

ExternalProject_Get_Property(VTK_external_data SOURCE_DIR)
ExternalProject_Get_Property(VTK_external_data BINARY_DIR)
ExternalProject_Get_Property(VTK_external_data DOWNLOAD_DIR)
ExternalProject_Get_Property(VTK_external_data INSTALL_DIR)
 

message("SOURCE_DIR=${SOURCE_DIR}")
message("BINARY_DIR=${BINARY_DIR}")
message("DOWNLOAD_DIR=${DOWNLOAD_DIR}")
message("INSTALL_DIR=${INSTALL_DIR}")
