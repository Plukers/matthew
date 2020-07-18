#include "RenderWidget.h"
#include "Programhandler.h"

#include <QSurfaceFormat>
#include <iostream>
// *****************************************************************************
RenderWidget::RenderWidget(QWidget *parent) : QOpenGLWidget(parent),
	simpleVertex{QOpenGLShader::Vertex}, simpleFragment{QOpenGLShader::Fragment},
	simpleProgram{}, triangleVAO{}, triangleVBO{}
// *****************************************************************************
{
    QSurfaceFormat format;
    format.setDepthBufferSize(24);
    format.setStencilBufferSize(8);
    format.setVersion(3, 2);
    format.setProfile(QSurfaceFormat::CoreProfile);
    setFormat(format); // must be called before the widget or its parent window gets shown


}

// *****************************************************************************
void RenderWidget::initializeGL()
// *****************************************************************************
{
    initializeOpenGLFunctions();


	ProgramHandler::initializePrograms();
	auto colorProgram = ProgramHandler::getProgram("colorProgram");

	colorProgram->bind();

	triangleVAO.create();
	triangleVBO.create();
	triangleVAO.bind();
	triangleVBO.bind();
	triangleVBO.allocate(&vertices, sizeof(vertices));
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
}

// *****************************************************************************
void RenderWidget::resizeGL(int w, int h)
// *****************************************************************************
{
    glClear(GL_COLOR_BUFFER_BIT);
}

// *****************************************************************************
void RenderWidget::paintGL()
// *****************************************************************************
{
    glClear(GL_COLOR_BUFFER_BIT);
	simpleProgram.bind();
	triangleVAO.bind();
	glDrawArrays(GL_TRIANGLES, 0, 3);
}
