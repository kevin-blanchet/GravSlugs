cmake_minimum_required(VERSION 3.14)

# Setup name
set(PROJECT_NAME grav_project)
set(APP_NAME GravSlugs)
set(ENGINE_NAME GravEngine)
set(EDITOR_NAME GravEditor)

# Setup vcpkg script with CMake (note: should be placed before project() call)
set(VCPKG_DIR ${CMAKE_CURRENT_SOURCE_DIR}/Dependencies/vcpkg)
set(CMAKE_TOOLCHAIN_FILE ${VCPKG_DIR}/scripts/buildsystems/vcpkg.cmake CACHE STRING "Vcpkg toolchain file")

project(${PROJECT_NAME})

set(CMAKE_CXX_STANDARD 20)

# vcpkg dependencies
find_package(SFML COMPONENTS system window graphics audio CONFIG REQUIRED)
find_package(imgui CONFIG REQUIRED)
find_package(ImGui-SFML CONFIG REQUIRED)

add_subdirectory(${ENGINE_NAME})
add_subdirectory(${APP_NAME})
add_subdirectory(${EDITOR_NAME})

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ${APP_NAME})