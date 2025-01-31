cmake_minimum_required(VERSION 3.5)

project(viewer VERSION 2.0 LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 QUIET COMPONENTS Widgets OpenGL OpenGLWidgets)

if(Qt6_FOUND)
    set(QT_VERSION_MAJOR 6)
    set(QT_LIBRARIES Qt6::Widgets Qt6::OpenGL Qt6::OpenGLWidgets)
else()
    find_package(Qt5 REQUIRED COMPONENTS Widgets OpenGL OpenGLWidgets)
    set(QT_VERSION_MAJOR 5)
    set(QT_LIBRARIES Qt5::Widgets Qt5::OpenGL Qt5::OpenGLWidgets)
endif()

set(MODEL_DIR ${CMAKE_SOURCE_DIR}/model)
set(VIEW_DIR ${CMAKE_SOURCE_DIR}/view)
set(CONTROLLER_DIR ${CMAKE_SOURCE_DIR}/controller)
set(INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)

set(MODEL
  ${MODEL_DIR}/transform_matrix_builder.cc
  ${MODEL_DIR}/transform_matrix.cc
  ${MODEL_DIR}/scene_drawer.cc
  ${MODEL_DIR}/file_reader.cc
  ${MODEL_DIR}/point_3D.cc
  ${MODEL_DIR}/open_gl.cc
  ${MODEL_DIR}/vertex.cc
  ${MODEL_DIR}/scene.cc
)

set(MODEL_HEADERS
  ${INCLUDE_DIR}/model/transform_matrix_builder.h
  ${INCLUDE_DIR}/model/scene_drawer_base.h
  ${INCLUDE_DIR}/model/file_reader_base.h
  ${INCLUDE_DIR}/model/transform_matrix.h
  ${INCLUDE_DIR}/model/scene_drawer.h
  ${INCLUDE_DIR}/model/file_reader.h
  ${INCLUDE_DIR}/model/point_3D.h
  ${INCLUDE_DIR}/model/open_gl.h
  ${INCLUDE_DIR}/model/vertex.h
  ${INCLUDE_DIR}/model/scene.h
  ${INCLUDE_DIR}/model/gif.h
)

set(VIEW
  ${VIEW_DIR}/color_button.cc
  ${VIEW_DIR}/main_window.cc
  ${VIEW_DIR}/base_widget.cc
  ${VIEW_DIR}/afinne_data.cc
  ${VIEW_DIR}/object_data.cc
  ${VIEW_DIR}/path_reader.cc
  ${VIEW_DIR}/scene_data.cc
  ${VIEW_DIR}/scene_view.cc
  ${VIEW_DIR}/function.cc
  ${VIEW_DIR}/slider.cc
  ${VIEW_DIR}/style.cc
)

set(VIEW_HEADERS
  ${INCLUDE_DIR}/view/color_button.h
  ${INCLUDE_DIR}/view/main_window.h
  ${INCLUDE_DIR}/view/base_widget.h
  ${INCLUDE_DIR}/view/afinne_data.h
  ${INCLUDE_DIR}/view/object_data.h
  ${INCLUDE_DIR}/view/path_reader.h
  ${INCLUDE_DIR}/view/scene_data.h
  ${INCLUDE_DIR}/view/scene_view.h
  ${INCLUDE_DIR}/view/function.h
  ${INCLUDE_DIR}/view/slider.h
  ${INCLUDE_DIR}/view/style.h
)

set(CONTROLLER
  ${CONTROLLER_DIR}/facade.cc
)

set(CONTROLLER_HEADERS
  ${INCLUDE_DIR}/controller/facade.h
  ${INCLUDE_DIR}/controller/data.h
)

set(MAIN
  ${CMAKE_SOURCE_DIR}/3DViewer.cc
)

set(RESOURCE
  ${CMAKE_SOURCE_DIR}/resource/resource.qrc
)

set(PROJECT_SOURCES
  ${MODEL}
  ${MODEL_HEADERS}
  ${CONTROLLER}
  ${CONTROLLER_HEADERS}
  ${VIEW}
  ${VIEW_HEADERS}
  ${MAIN}
  ${RESOURCE}
)

include_directories(${CMAKE_SOURCE_DIR})

add_executable(${PROJECT_NAME} ${PROJECT_SOURCES})

target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Werror -Wextra -g)

target_link_libraries(${PROJECT_NAME} PRIVATE ${QT_LIBRARIES})

target_include_directories(${PROJECT_NAME} PRIVATE
  ${CMAKE_SOURCE_DIR}/modules/include
)

install(TARGETS ${PROJECT_NAME} DESTINATION bin)
