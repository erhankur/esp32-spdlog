idf_component_register()

set(CMAKE_THREAD_LIBS_INIT idf::pthread)

include(FetchContent)

set(patch_file "0001-patches-for-idf.patch")

set(patch_command
    ${CMAKE_COMMAND} -E copy_if_different ${CMAKE_CURRENT_LIST_DIR}/${patch_file} <SOURCE_DIR>
        && git stash
        && git apply <SOURCE_DIR>/${patch_file}
)

FetchContent_Declare(
        spdlog
        GIT_REPOSITORY https://github.com/gabime/spdlog.git
        GIT_TAG        287a00d364990edbb621fe5e392aeb550135fb96
        GIT_PROGRESS   TRUE
        GIT_SHALLOW    TRUE
        PATCH_COMMAND ${patch_command}
)

FetchContent_GetProperties(spdlog)
if (NOT spdlog_POPULATED)
    FetchContent_Populate(spdlog)
    add_subdirectory(${spdlog_SOURCE_DIR} ${spdlog_BINARY_DIR})
endif()

target_link_libraries(${COMPONENT_LIB} INTERFACE spdlog::spdlog_header_only)
