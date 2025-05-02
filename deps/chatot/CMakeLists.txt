cmake_minimum_required(VERSION 3.14)

project(
    chatot
    LANGUAGES C
    DESCRIPTION "minimal logging library"
    HOMEPAGE_URL "https://github.com/klaleus/chatot"
    VERSION 1.0.0
)

set(CMAKE_MODULE_PATH "${CMAKE_MODULE_PATH}" "${CMAKE_CURRENT_LIST_DIR}/cmake")
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

if(CMAKE_CURRENT_SOURCE_DIR STREQUAL CMAKE_SOURCE_DIR)
    set(CHATOT_STANDALONE ON)
else()
    set(CHATOT_STANDALONE OFF)
endif()

set(CHATOT_LIBRARY_TYPE STATIC CACHE STRING "cmake library type")
set(CHATOT_INSTALL ${CHATOT_STANDALONE} CACHE BOOL "enable `make install`")

add_library(
    chatot
    ${CHATOT_LIBRARY_TYPE}
    "${CMAKE_CURRENT_LIST_DIR}/src/chatot.c"
)

include(GNUInstallDirs)

target_include_directories(
    chatot
    PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include>
    $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}/chatot>
)

include(CMakePackageConfigHelpers)

configure_package_config_file(
    "${CMAKE_CURRENT_LIST_DIR}/cmake/ChatotConfig.cmake.in"
    "${CMAKE_CURRENT_BINARY_DIR}/ChatotConfig.cmake"
    INSTALL_DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake/chatot"
)

write_basic_package_version_file(
    "${CMAKE_CURRENT_BINARY_DIR}/ChatotConfigVersion.cmake"
    COMPATIBILITY SameMajorVersion
)

if(CHATOT_INSTALL)

    install(
        TARGETS chatot
        EXPORT ChatotTargets
        LIBRARY DESTINATION "${CMAKE_INSTALL_LIBDIR}"
        ARCHIVE DESTINATION "${CMAKE_INSTALL_LIBDIR}"
    )

    install(
        DIRECTORY "${CMAKE_CURRENT_LIST_DIR}/include/chatot"
        DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}"
    )

    install(
        EXPORT ChatotTargets
        FILE ChatotTargets.cmake
        NAMESPACE klaleus::
        DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake/chatot"
    )

    install(
        FILES
        "${CMAKE_CURRENT_BINARY_DIR}/ChatotConfig.cmake"
        "${CMAKE_CURRENT_BINARY_DIR}/ChatotConfigVersion.cmake"
        DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake/chatot"
    )

endif()