/**
 * @file qt_scene_drawer.cc
 * @author kossadda (https://github.com/kossadda)
 * @brief
 * @version 1.0
 * @date 2024-10-07
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "include/model/qt_scene_drawer.h"

namespace s21 {

QtSceneDrawer::QtSceneDrawer() : QOpenGLWidget{}, data_{Data::data()} {
  setlocale(LC_NUMERIC, "C");
}

QtSceneDrawer::~QtSceneDrawer() {
  destroyBuffers();
  delete program_;
}

void QtSceneDrawer::destroyBuffers() {
  makeCurrent();
  if (vao_.isCreated()) {
    vao_.destroy();
  }
  if (vbo_.isCreated()) {
    vbo_.destroy();
  }
  if (ebo_.isCreated()) {
    ebo_.destroy();
  }
}

void QtSceneDrawer::initializeGL() {
  initializeOpenGLFunctions();

  glEnable(GL_DEPTH_TEST);

  program_ = new QOpenGLShaderProgram;
  program_->addShaderFromSourceCode(QOpenGLShader::Vertex, kVertexShader);
  program_->addShaderFromSourceCode(QOpenGLShader::Fragment, kFragmentShader);
  program_->bindAttributeLocation("vertex", 0);
  program_->link();
  program_->bind();

  coeff_matrix_ = program_->uniformLocation("coeff_matrix");
  color_ = program_->uniformLocation("color");

  rotate_.setToIdentity();
  move_.setToIdentity();
  scale_.setToIdentity();
}

void QtSceneDrawer::initBuffers() {
  makeCurrent();

  auto vert{scene_->vertices()};
  auto edge{scene_->edges()};

  if (vao_.isCreated() == false) {
    vao_.create();
    vao_.bind();

    if (vbo_.isCreated() == false) {
      vbo_ = QOpenGLBuffer(QOpenGLBuffer::VertexBuffer);
      vbo_.create();
      vbo_.bind();
      vbo_.setUsagePattern(QOpenGLBuffer::DynamicDraw);
      if (vert.size()) {
        vbo_.allocate(vert.begin()->base(), vert.size() * 3 * sizeof(GLfloat));
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat),
                              nullptr);
        glEnableVertexAttribArray(0);
      }
    }

    if (ebo_.isCreated() == false) {
      ebo_ = QOpenGLBuffer(QOpenGLBuffer::IndexBuffer);
      ebo_.create();
      ebo_.bind();
      ebo_.setUsagePattern(QOpenGLBuffer::StaticDraw);
      if (edge.size()) {
        ebo_.allocate(edge.begin()->base(), edge.size() * 2 * sizeof(GLuint));
      }
    }

    vao_.release();
  }
}

void QtSceneDrawer::resizeGL(int w, int h) { 
  setupProjection(w, h);
}

void QtSceneDrawer::setupProjection(int w, int h) {
  if (w < 1 || h < 1) {
    w = width();
    h = height();
  }

  setAllMatrixToIdentity();
  camera_.setToIdentity();
  projection_.setToIdentity();

  if (data_.projection_type == ProjectionType::Centrall) {
    camera_.translate(0.0f, 0.0f, -3.0f);
    projection_.perspective(45.0f, GLfloat(w) / h, 0.01f, 100.0f);
  } else {
    float top, bottom, right, left;
    float aspect = (GLfloat)w / h;
    float coeff = 1.3f;

    if (w > h) {
      top = coeff;
      bottom = -coeff;
      right = coeff * aspect;
      left = -right;
    } else {
      right = coeff;
      left = -coeff;
      top = coeff / aspect;
      bottom = -top;
    }

    camera_.ortho(left, right, bottom, top, -100.0f, 100.0f);
  }
}

void QtSceneDrawer::afinneCPU() {
  setAllMatrixToIdentity();

  // 
}

void QtSceneDrawer::afinneGPU() {
  setAllMatrixToIdentity();

  rotate_.rotate(data_.rotate_x, 1, 0, 0);
  rotate_.rotate(data_.rotate_y, 0, 1, 0);
  rotate_.rotate(data_.rotate_z, 0, 0, 1);
  move_.translate(data_.move_x, data_.move_y, data_.move_z);
  scale_.scale(data_.scale, data_.scale, data_.scale);
}

void QtSceneDrawer::setAllMatrixToIdentity() {
  rotate_.setToIdentity();
  move_.setToIdentity();
  scale_.setToIdentity();
}

void QtSceneDrawer::paintGL() {
  glClearColor(data_.background_color.redF(), data_.background_color.greenF(), data_.background_color.blueF(), 1.0f);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  if (data_.calculate_type == CalculateType::CPU) {
    afinneCPU();
  } else {
    afinneGPU();
  }

  program_->setUniformValue(coeff_matrix_, projection_ * camera_ * scale_ * move_ * rotate_);

  if (vao_.isCreated() && vbo_.isCreated() && ebo_.isCreated()) {
    vao_.bind();

    if (data_.facet_type != FacetType::None) {
      program_->setUniformValue("color", QVector4D(data_.facet_color.redF(), data_.facet_color.greenF(), data_.facet_color.blueF(), data_.facet_color.alphaF()));
      glLineWidth(data_.facet_size);

      if (data_.facet_type == FacetType::Dotted) {
        glEnable(GL_LINE_STIPPLE);
        glLineStipple(1, 0x00FF);
      } else {
        glDisable(GL_LINE_STIPPLE);
      }

      glDrawElements(GL_LINES, scene_->edges().size() * 2, GL_UNSIGNED_INT, nullptr);
    }

    if (data_.vertex_type != VertexType::None) {
      program_->setUniformValue("color", QVector4D(data_.vertex_color.redF(), data_.vertex_color.greenF(), data_.vertex_color.blueF(), data_.vertex_color.alphaF()));
      glPointSize(data_.vertex_size);

      if (data_.vertex_type == VertexType::Circle) {
        glEnable(GL_POINT_SMOOTH);
      } else {
        glDisable(GL_POINT_SMOOTH);
      }

      glDrawArrays(GL_POINTS, 0, scene_->vertices().size() * 3);
    }

    vao_.release();
  }
}

void QtSceneDrawer::mousePressEvent(QMouseEvent *event) { emit mousePress(event); }

void QtSceneDrawer::mouseMoveEvent(QMouseEvent *event) { emit mouseMove(event); }

void QtSceneDrawer::wheelEvent(QWheelEvent *event) { emit mouseWheel(event); }

void QtSceneDrawer::initModel(Scene *scene) {
  (void)scene;
  scene_ = testModel();
  destroyBuffers();
  initBuffers();
  update();
}

const char *QtSceneDrawer::kVertexShader =
      "attribute vec4 vertex;\n"
      "uniform mat4 coeff_matrix;\n"
      "void main() {\n"
      "  gl_Position = coeff_matrix * vertex;\n"
      "}\n";

const char *QtSceneDrawer::kFragmentShader =
    "uniform vec4 color;\n"
    "void main() {\n"
    "  gl_FragColor = color;\n"
    "}\n";

Scene *QtSceneDrawer::testModel() {
  std::vector<Point3D> vertices;
  std::vector<Edge> edges = {
    {0, 1}, {1, 2}, {2, 0},
    {2, 1}, {1, 3}, {3, 2},
    {2, 3}, {3, 4}, {4, 2},
    {4, 3}, {3, 5}, {5, 4},
    {4, 5}, {5, 6}, {6, 4},
    {6, 5}, {5, 7}, {7, 6},
    {6, 7}, {7, 0}, {0, 6},
    {0, 7}, {7, 1}, {1, 0},
    {1, 7}, {7, 3}, {3, 1},
    {3, 7}, {7, 5}, {5, 3},
    {6, 0}, {0, 4}, {4, 6},
    {4, 0}, {0, 2}, {2, 4}
  };

  vertices.push_back({-1.f, -1.f, 2.f});
  vertices.push_back({1.f, -1.f, 2.f});
  vertices.push_back({-1.f, 1.f, 2.f});
  vertices.push_back({1.f, 1.f, 2.f});
  vertices.push_back({-1.f, 1.f, 0.f});
  vertices.push_back({1.f, 1.f, 0.f});
  vertices.push_back({-1.f, -1.f, 0.f});
  vertices.push_back({1.f, -1.f, 0.f});

  return new Scene{vertices, edges};
}


}  // namespace s21
