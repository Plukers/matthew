#include "RenderWidget.h"

RenderWidget::RenderWidget(QWidget *parent) : QOpenGLWidget(parent)
{
    QSurfaceFormat format;
    format.setDepthBufferSize(24);
    format.setStencilBufferSize(8);
    format.setVersion(3, 2);
    format.setProfile(QSurfaceFormat::CoreProfile);
    setFormat(format); // must be called before the widget or its parent window gets shown


}


void RenderWidget::initializeGL(){
    initializeOpenGLFunctions();
    glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
}

void RenderWidget::resizeGL(int w, int h){

}

void RenderWidget::paintGL(){

    glClear(GL_COLOR_BUFFER_BIT);
}
