cmake_minimum_required(VERSION 3.5)

project(viewer VERSION 2.0 LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS OpenGL)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS OpenGLWidgets)

set(MODEL_DIR ${CMAKE_SOURCE_DIR}/model)
set(VIEW_DIR ${CMAKE_SOURCE_DIR}/view)
set(CONTROLLER_DIR ${CMAKE_SOURCE_DIR}/controller)
set(INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)

set(MODEL

)

set(VIEW
  ${VIEW_DIR}/main_window.cc
  ${VIEW_DIR}/path_reader.cc
)

set(CONTROLLER

)

set(HEADERS
  ${INCLUDE_DIR}/view/main_window.h
  ${INCLUDE_DIR}/view/path_reader.h
)

set(MAIN
  ${CMAKE_SOURCE_DIR}/3DViewer.cc
)

set(RESOURCE
  ${CMAKE_SOURCE_DIR}/resource/resource.qrc
)

set(PROJECT_SOURCES
  ${MODEL}
  ${CONTROLLER}
  ${VIEW}
  ${HEADERS}
  ${MAIN}
  ${RESOURCE}
)

include_directories(${CMAKE_SOURCE_DIR})

add_executable(${PROJECT_NAME} ${PROJECT_SOURCES})

target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Werror -Wextra -g)

target_link_libraries(${PROJECT_NAME} PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
target_link_libraries(${PROJECT_NAME} PRIVATE Qt${QT_VERSION_MAJOR}::OpenGL)
target_link_libraries(${PROJECT_NAME} PRIVATE Qt${QT_VERSION_MAJOR}::OpenGLWidgets)

target_include_directories(${PROJECT_NAME} PRIVATE
  ${CMAKE_SOURCE_DIR}/modules/include
)

qt_finalize_executable(${PROJECT_NAME})

# enable_testing()
# add_subdirectory(tests)