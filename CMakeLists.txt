cmake_minimum_required(VERSION 3.8)

set(CMAKE_CXX_STANDARD 20)

set(application_name "esp32-spdlog")
set(application_version "0.0.1")

set(PROJECT_VER ${application_version})
include($ENV{IDF_PATH}/tools/cmake/project.cmake)
project(${application_name})
