################################################################################
# Configure Porygon
################################################################################

cmake_minimum_required(VERSION 3.14)

project(
    porygon
    LANGUAGES C
    DESCRIPTION "minimal game development framework"
    HOMEPAGE_URL "https://github.com/klaleus/porygon"
    VERSION 0.0.1
)

set(CMAKE_MODULE_PATH "${CMAKE_MODULE_PATH}" "${CMAKE_CURRENT_LIST_DIR}/cmake")
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

if(CMAKE_CURRENT_SOURCE_DIR STREQUAL CMAKE_SOURCE_DIR)
    set(PORYGON_STANDALONE ON)
else()
    set(PORYGON_STANDALONE OFF)
endif()

include(CMakeOptions)
include(GNUInstallDirs)
include(CMakePackageConfigHelpers)

################################################################################
# Build Dependencies
################################################################################

set(CHATOT_LIBRARY_TYPE OBJECT CACHE STRING "" FORCE)
add_subdirectory("${CMAKE_CURRENT_LIST_DIR}/deps/chatot")

add_subdirectory("${CMAKE_CURRENT_LIST_DIR}/deps/glad")

set(GLFW_LIBRARY_TYPE OBJECT CACHE STRING "" FORCE)
set(GLFW_BUILD_DOCS OFF CACHE BOOL "")
set(GLFW_INSTALL OFF CACHE BOOL "")
add_subdirectory("${CMAKE_CURRENT_LIST_DIR}/deps/glfw")

################################################################################
# Build Porygon
################################################################################

add_library(
    porygon
    ${PORYGON_LIBRARY_TYPE}
    "${CMAKE_CURRENT_LIST_DIR}/src/buffer.c"
    "${CMAKE_CURRENT_LIST_DIR}/src/format.c"
    "${CMAKE_CURRENT_LIST_DIR}/src/framework.c"
    "${CMAKE_CURRENT_LIST_DIR}/src/shader.c"
    "${CMAKE_CURRENT_LIST_DIR}/src/vector.c"
    "${CMAKE_CURRENT_LIST_DIR}/src/window.c"
    $<TARGET_OBJECTS:chatot>
    $<TARGET_OBJECTS:glfw>
)

target_include_directories(
    porygon
    PUBLIC
    "$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include>"
    "$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}/porygon>"
)

target_link_libraries(
    porygon
    PRIVATE
    $<BUILD_INTERFACE:chatot>
    $<BUILD_INTERFACE:glad>
    glfw
)

target_compile_definitions(
    porygon
    INTERFACE
    $<BUILD_INTERFACE:PORYGON_ASSETS=\"${CMAKE_CURRENT_LIST_DIR}/assets\">
    $<INSTALL_INTERFACE:PORYGON_ASSETS=\"${CMAKE_INSTALL_DATADIR}/porygon/assets\">
)

################################################################################
# Install Porygon
################################################################################

configure_package_config_file(
    "${CMAKE_CURRENT_LIST_DIR}/cmake/PorygonConfig.cmake.in"
    "${CMAKE_CURRENT_BINARY_DIR}/PorygonConfig.cmake"
    INSTALL_DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake/porygon"
)

write_basic_package_version_file(
    "${CMAKE_CURRENT_BINARY_DIR}/PorygonConfigVersion.cmake"
    COMPATIBILITY SameMajorVersion
)

if(PORYGON_INSTALL)

    install(
        TARGETS porygon glfw
        EXPORT PorygonTargets
        LIBRARY DESTINATION "${CMAKE_INSTALL_LIBDIR}"
        ARCHIVE DESTINATION "${CMAKE_INSTALL_LIBDIR}"
    )

    install(
        DIRECTORY "${CMAKE_CURRENT_LIST_DIR}/include/porygon"
        DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}"
    )

    install(
        DIRECTORY "${CMAKE_CURRENT_LIST_DIR}/assets"
        DESTINATION "${CMAKE_INSTALL_DATADIR}/porygon"
    )

    install(
        EXPORT PorygonTargets
        NAMESPACE klaleus::
        DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake/porygon"
    )

    install(
        FILES
        "${CMAKE_CURRENT_BINARY_DIR}/PorygonConfig.cmake"
        "${CMAKE_CURRENT_BINARY_DIR}/PorygonConfigVersion.cmake"
        DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake/porygon"
    )

endif()
