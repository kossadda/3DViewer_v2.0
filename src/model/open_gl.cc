/**
 * @file open_gl.cc
 * @author kossadda (https://github.com/kossadda)
 * @brief
 * @version 1.0
 * @date 2024-10-07
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "include/model/open_gl.h"

namespace s21 {

OpenGL::OpenGL() : QOpenGLWidget{} {
  allocateMemory();
  setlocale(LC_NUMERIC, "C");
}

OpenGL::~OpenGL() {
  destroyBuffers();
  delete program_;
  delete vbo_;
  delete ebo_;
  delete vao_;
}

void OpenGL::allocateMemory() {
  vbo_ = new QOpenGLBuffer{QOpenGLBuffer::VertexBuffer};
  ebo_ = new QOpenGLBuffer{QOpenGLBuffer::IndexBuffer};
  vao_ = new QOpenGLVertexArrayObject;
}

bool OpenGL::isBufferAllocate() {
  return (!vbo_->isCreated() || !ebo_->isCreated() || !vao_->isCreated())
             ? false
             : true;
}

void OpenGL::initializeGL() {
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
}

void OpenGL::paintGL() {
  setupProjection(width(), height());

  if (data_.calculate_type == CalculateType::CPU) {
    program_->setUniformValue(coeff_matrix_, projection_ * camera_);
  } else {
    program_->setUniformValue(coeff_matrix_, afinneGPU());
  }

  if (vao_->isCreated() && vbo_->isCreated() && ebo_->isCreated()) {
    vao_->bind();

    if (data_.vertex_type != VertexType::None) {
      program_->setUniformValue(
          "color",
          QVector4D(data_.vertex_color.redF(), data_.vertex_color.greenF(),
                    data_.vertex_color.blueF(), data_.vertex_color.alphaF()));
      glPointSize(data_.vertex_size);

      if (data_.vertex_type == VertexType::Circle) {
        glEnable(GL_POINT_SMOOTH);
      } else {
        glDisable(GL_POINT_SMOOTH);
      }

      glDrawArrays(GL_POINTS, 0, vbo_size_);
    }

    if (data_.facet_type != FacetType::None) {
      program_->setUniformValue(
          "color",
          QVector4D(data_.facet_color.redF(), data_.facet_color.greenF(),
                    data_.facet_color.blueF(), data_.facet_color.alphaF()));
      glLineWidth(data_.facet_size);

      if (data_.facet_type == FacetType::Dotted) {
        glEnable(GL_LINE_STIPPLE);
        glLineStipple(1, 0x00FF);
      } else {
        glDisable(GL_LINE_STIPPLE);
      }

      glDrawElements(GL_LINES, ebo_size_, GL_UNSIGNED_INT, nullptr);
    }

    vao_->release();
  }
}

void OpenGL::resizeGL(int w, int h) { setupProjection(w, h); }

void OpenGL::setupProjection(int w, int h) {
  if (w < 1 || h < 1) {
    w = width();
    h = height();
  }

  projection_.setToIdentity();
  camera_.setToIdentity();

  if (data_.projection_type == ProjectionType::Centrall) {
    projection_.perspective(45.0f, GLfloat(w) / h, 0.01f, 100.0f);
    camera_.translate(0.0f, 0.0f, -3.0f);
  } else {
    float top, bottom, right, left;
    float aspect = static_cast<GLfloat>(w) / h;
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

  glClearColor(data_.background_color.redF(), data_.background_color.greenF(),
               data_.background_color.blueF(), 1.0f);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void OpenGL::initBuffers(Scene *scene) {
  makeCurrent();

  const std::vector<Vertex> &vertices{scene->vertices()};
  const std::vector<int> &indices{scene->indices()};
  const float *vptr{vertices.begin()->position().base()};
  const int *eptr{indices.begin().base()};
  vbo_size_ = vertices.size();
  ebo_size_ = indices.size();

  vao_->create();
  vbo_->create();
  ebo_->create();
  vao_->bind();
  vbo_->bind();
  ebo_->bind();

  if (vbo_size_) {
    vbo_->setUsagePattern(QOpenGLBuffer::DynamicDraw);
    vbo_->allocate(vptr, vbo_size_ * sizeof(Vertex));
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), nullptr);
    glEnableVertexAttribArray(0);
  }

  if (ebo_size_) {
    ebo_->setUsagePattern(QOpenGLBuffer::StaticDraw);
    ebo_->allocate(eptr, ebo_size_ * sizeof(GLuint));
  }

  vao_->release();
}

void OpenGL::updateBuffer(Scene *scene) {
  scene->Transform(afinneCPU());
  const float *vbo_ptr{scene->vertices().begin()->position().base()};

  vbo_->bind();
  vbo_->write(0, vbo_ptr, vbo_size_ * sizeof(Vertex));
  vbo_->release();
}

void OpenGL::destroyBuffers() {
  makeCurrent();

  if (vao_->isCreated()) {
    vao_->destroy();
  }
  if (vbo_->isCreated()) {
    vbo_->destroy();
  }
  if (ebo_->isCreated()) {
    ebo_->destroy();
  }
}

TransformMatrix OpenGL::afinneCPU() {
  TransformMatrix rotate{TransformMatrixBuilder::CreateRotationMatrix(
      data_.rotate_x, data_.rotate_y, data_.rotate_z)};
  TransformMatrix scale{TransformMatrixBuilder::CreateScaleMatrix(
      data_.scale, data_.scale, data_.scale)};
  TransformMatrix move{TransformMatrixBuilder::CreateMoveMatrix(
      data_.move_x, data_.move_y, data_.move_z)};

  return rotate * scale * move;
}

QMatrix4x4 OpenGL::afinneGPU() {
  QMatrix4x4 rotate;
  QMatrix4x4 scale;
  QMatrix4x4 move;

  rotate.rotate(data_.rotate_x, 1, 0, 0);
  rotate.rotate(data_.rotate_y, 0, 1, 0);
  rotate.rotate(data_.rotate_z, 0, 0, 1);
  move.translate(data_.move_x, data_.move_y, data_.move_z);
  scale.scale(data_.scale, data_.scale, data_.scale);

  return projection_ * camera_ * rotate * scale * move;
}

void OpenGL::mousePressEvent(QMouseEvent *event) { emit mousePress(event); }

void OpenGL::mouseMoveEvent(QMouseEvent *event) { emit mouseMove(event); }

void OpenGL::wheelEvent(QWheelEvent *event) { emit mouseWheel(event); }

const char *OpenGL::kVertexShader =
    "attribute vec4 vertex;\n"
    "uniform mat4 coeff_matrix;\n"
    "void main() {\n"
    "  gl_Position = coeff_matrix * vertex;\n"
    "}\n";

const char *OpenGL::kFragmentShader =
    "uniform vec4 color;\n"
    "void main() {\n"
    "  gl_FragColor = color;\n"
    "}\n";

}  // namespace s21
