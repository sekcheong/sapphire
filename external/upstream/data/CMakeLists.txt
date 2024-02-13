
cmake_minimum_required(VERSION 3.20)
include(ExternalProject)

ExternalProject_Add(VTK_external_data
    PREFIX "demo"
    URL https://github.com/sekcheong/nebula/releases/download/v0.0.0/data.zip
    CONFIGURE_COMMAND ""
    BUILD_COMMAND ""
    INSTALL_COMMAND ""
)