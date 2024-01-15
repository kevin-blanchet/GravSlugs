cmake_minimum_required(VERSION 3.14)

set(LIB_NAME GravEngine)

project(${LIB_NAME})

set(SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)

file(GLOB_RECURSE HEADERS
    "${INCLUDE_DIR}/*.h"
    "${INCLUDE_DIR}/*.hxx"
)

file(GLOB_RECURSE SOURCES
    "${SRC_DIR}/*.cpp"
)

# Add library Dynamic 
add_library(${LIB_NAME} STATIC
    ${HEADERS}
    ${SOURCES}
)

# Headers
foreach(_header IN ITEMS ${HEADERS})
    get_filename_component(_header_path "${_header}" PATH)
    string(REPLACE "${CMAKE_SOURCE_DIR}/${LIB_NAME}" "" _header_path "${_header_path}")
    string(REPLACE "/" "\\" _header_path "${_header_path}")
    source_group("${_header_path}" FILES "${_header}")
endforeach()

# Sources
foreach(_source IN ITEMS ${SOURCES})
    get_filename_component(_source_path "${_source}" PATH)
    string(REPLACE "${CMAKE_SOURCE_DIR}/${LIB_NAME}" "" _group_path "${_source_path}")
    string(REPLACE "/" "\\" _group_path "${_group_path}")
    source_group("${_group_path}" FILES "${_source}")
endforeach()

target_include_directories(${LIB_NAME}
    PUBLIC
        $<INSTALL_INTERFACE:include>
        $<BUILD_INTERFACE:${INCLUDE_DIR}>
    PRIVATE
        ${SRC_DIR}
)

target_link_libraries(${LIB_NAME} 
    PUBLIC
        sfml-system sfml-graphics sfml-window sfml-audio
        imgui::imgui
        ImGui-SFML::ImGui-SFML
)