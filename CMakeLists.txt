cmake_minimum_required(VERSION 3.5)

project(matthew LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 COMPONENTS Widgets OpenGL LinguistTools REQUIRED)

set(TS_FILES matthew_en_001.ts)

add_executable(matthew
  Main.cc
  RenderWidget.cc
  RenderWidget.h
  ${TS_FILES}
)
target_link_libraries(matthew Qt5::Widgets)

qt5_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})
