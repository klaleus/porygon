add_library(
    glad
    INTERFACE
)

target_include_directories(
    glad
    BEFORE
    INTERFACE
    "${CMAKE_CURRENT_LIST_DIR}/include"
)