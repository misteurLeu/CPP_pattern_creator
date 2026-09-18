cmake_minimum_required(VERSION 3.19)

project(ImageEditor LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core)

add_library(ImageEditor SHARED
  ImageEditor_global.h
  imageeditor.cpp
  imageeditor.h
  pixelcolor.h
  pixelcolor.cpp
)

target_link_libraries(ImageEditor PUBLIC Qt${QT_VERSION_MAJOR}::Core)

target_compile_definitions(ImageEditor PRIVATE IMAGEEDITOR_LIBRARY)

add_subdirectory(Testing)