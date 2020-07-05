#ifndef RENDERWIDGET_H
#define RENDERWIDGET_H

#include <QOpenGLWidget>
#include <QWidget>
#include <QOpenGLFunctions>

class RenderWidget : public QOpenGLWidget, protected QOpenGLFunctions
{
    Q_OBJECT
public:
    RenderWidget(QWidget *parent = nullptr);

protected:
    void initializeGL() override;
    void resizeGL(int w, int h) override;
    void paintGL() override;
};

#endif // RENDERWIDGET_H
