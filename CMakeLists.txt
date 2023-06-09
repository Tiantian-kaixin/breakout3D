cmake_minimum_required(VERSION 3.24)
project(breakout3D LANGUAGES CXX)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_library(OpenGL_LIBRARY OpenGL)
add_definitions(${OPENGL_DEFINITIONS})
if (APPLE AND NOT XCODE)
    set(PLATFORM_ABI x86_64)
    set(CMAKE_CXX_FLAGS "-ObjC++ -stdlib=libc++ ${cppFlags}")
endif ()
if (APPLE)
    find_library(MAC_ACCE Accelerate)
    list(APPEND EXTRA_LIBS ${MAC_ACCE})

    if (IOS)
        find_library(UI_KIT UIKit)
        list(APPEND EXTRA_LIBS ${UI_KIT})
    else ()
        find_library(COCOA_LIBRARY Cocoa)
        list(APPEND EXTRA_LIBS ${COCOA_LIBRARY})
    endif ()

    find_library(CODE_VIDEO CoreVideo)
    list(APPEND EXTRA_LIBS ${CODE_VIDEO})

    find_library(CORE_GRAPHICS CoreGraphics)
    list(APPEND EXTRA_LIBS ${CORE_GRAPHICS})

    find_library(METAL_LIBRARY Metal)
    list(APPEND EXTRA_LIBS ${METAL_LIBRARY})

    find_library( CORE_ML_LIBRARY CoreML)
    list(APPEND EXTRA_LIBS ${CORE_ML_LIBRARY})

    find_library( METAL_PERFORMANCE_SHADERS_LIBRARY MetalPerformanceShaders)
    list(APPEND EXTRA_LIBS ${METAL_PERFORMANCE_SHADERS_LIBRARY})

    find_library(AVFOUNDATION AVFoundation)
    list(APPEND EXTRA_LIBS ${AVFOUNDATION})

    find_library(IOKit IOKit)
    list(APPEND EXTRA_LIBS ${IOKit})

    message( STATUS "METAL_PERFORMANCE_SHADERS_LIBRARY is ${METAL_PERFORMANCE_SHADERS_LIBRARY}")
endif ()
set(GLAD_GL "${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/glfw/deps/glad/gl.h"
        "${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/glfw/deps/glad_gl.c")

file(GLOB_RECURSE CORE_SOURCE_FILES
        "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/src/camera/*.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/src/shader/*.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/src/texture/*.cpp")

include_directories(${PROJECT_NAME} ${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/glfw/include
        ${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/glfw/deps
        ${CMAKE_CURRENT_SOURCE_DIR}/src/shader
        ${CMAKE_CURRENT_SOURCE_DIR}/src/camera
        ${CMAKE_CURRENT_SOURCE_DIR}/src/texture
        ${CMAKE_CURRENT_SOURCE_DIR}/src
        thirdparty/image
        thirdparty/glm
        )
add_library(glfw_lib STATIC IMPORTED GLOBAL)
set_target_properties(glfw_lib PROPERTIES IMPORTED_LOCATION
        ${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/glfw/lib-x86_64/libglfw3.a)

add_executable(${PROJECT_NAME} program.cpp ${GLAD_GL} ${CORE_SOURCE_FILES})
target_link_libraries(${PROJECT_NAME} glfw_lib ${OpenGL_LIBRARY} ${EXTRA_LIBS})

add_custom_target(CopyResources ALL
        COMMAND rm -rf ${CMAKE_CURRENT_BINARY_DIR}/Resources
        COMMAND mkdir ${CMAKE_CURRENT_BINARY_DIR}/Resources
        COMMAND echo compile finish
        COMMAND cp -r asset ${CMAKE_CURRENT_BINARY_DIR}/Resources/
        WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/
)
add_dependencies(${PROJECT_NAME} CopyResources)
