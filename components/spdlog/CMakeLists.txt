idf_component_register()

set(CMAKE_THREAD_LIBS_INIT idf::pthread)

include(FetchContent)

FetchContent_Declare(
        spdlog
        GIT_REPOSITORY https://github.com/gabime/spdlog.git
        GIT_TAG        6df64c6c34997e298a81150b9ce55c440c6f503f
        GIT_PROGRESS   TRUE
        GIT_SHALLOW    TRUE
)

FetchContent_GetProperties(spdlog)
if (NOT spdlog_POPULATED)
    FetchContent_Populate(spdlog)
    add_subdirectory(${spdlog_SOURCE_DIR} ${spdlog_BINARY_DIR})
endif()

target_link_libraries(${COMPONENT_LIB} INTERFACE spdlog::spdlog_header_only)
