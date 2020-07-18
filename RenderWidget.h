#ifndef RENDERWIDGET_H
#define RENDERWIDGET_H

#include <QOpenGLWidget>
#include <QWidget>
#include <QOpenGLFunctions>
#include <QOpenGLShader>
#include <QOpenGLShaderProgram>
#include <QOpenGLVertexArrayObject>
#include <QOpenGLBuffer>

#include "Programhandler.h"

class RenderWidget : public QOpenGLWidget, protected QOpenGLFunctions
{
    Q_OBJECT
public:
    RenderWidget(QWidget *parent = nullptr);

protected:
    void initializeGL() override;
    void resizeGL(int w, int h) override;
    void paintGL() override;

private:
	QOpenGLShader simpleVertex;
	QOpenGLShader simpleFragment;
	QOpenGLShaderProgram simpleProgram;

	GLfloat vertices[9] = {
		-0.8f, -0.8f, 0.0f,
		 0.8f, -0.8f, 0.0f,
		 0.0f,  0.8f, 0.0f
	};

	QOpenGLVertexArrayObject triangleVAO;
	QOpenGLBuffer triangleVBO;


};

#endif // RENDERWIDGET_H
