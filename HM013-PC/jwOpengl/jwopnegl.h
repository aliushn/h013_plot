#ifndef JWOPNEGL_H
#define JWOPNEGL_H


#include <QMainWindow>
#include "QtGui/QOpenGLBuffer"
#include "QtWidgets/QOpenGLWidget"
#include "QtGui/QOpenGLVertexArrayObject"
#include "QtGui/QOpenGLFunctions_4_5_Core"
#include <QWidget>
#include <QOpenGLWidget>
#include <QOpenGLWindow>
#include <QGlWidget>
#include <QGLFunctions>
#include <QOpenGLFunctions>
#include <QtOpenGL>
#include <QOpenGLBuffer>
#include <QOpenGLShaderProgram>
#include <QMatrix4x4>
#include <GL/glu.h>
#include <qgl.h>
#include "QtCore/QTimer"
#include "QtGui/QWheelEvent"
#include "QtGui/QMouseEvent"
#include "QOpenGLShaderProgram"
#include <QWidget>
#include <QOpenGLWidget>
#include <QOpenGLWindow>
#include <QGLWidget>
#include <QGLFunctions>
#include <QOpenGLFunctions>
#include <QtOpenGL>
#include <QOpenGLBuffer>
#include <QOpenGLShaderProgram>
#include <QMatrix4x4>
#include <GL/glu.h>
#include <QDebug>
#include <qgl.h>
#include <QOpenGLFunctions_3_3_Core>
#include <QDebug>
#include <QGraphicsOpacityEffect>
#include <QObject>
#include <QOpenGLWidget>
#include <GL/gl.h>
#include <GL/glu.h>
#include <QOpenGLFunctions>
#include <QOpenGLShaderProgram>
#include <QOpenGLTexture>
#include <QGLWidget>
#include <QImage>



class jwOpnegl : public QOpenGLWidget, QOpenGLFunctions
{
    Q_OBJECT
    public:
    explicit jwOpnegl(QWidget *parent );
    ~jwOpnegl();

protected:

    void initializeGL() override;
    void resizeGL(int w, int h) override;
    void paintGL() Q_DECL_OVERRIDE;
    void setBackground(QImage image);
    void initTextures();
    void initShaders();

private:
     bool fullscreen;                                //是否全屏显示

     GLfloat m_xRot;                                 //绕x轴旋转的角度
     GLfloat m_yRot;                                 //绕y轴旋转的角度
     GLfloat m_zRot;                                 //绕z轴旋转的角度

     QString m_FileName;                             //图片的路径及文件名
     GLuint m_Texture;                               //储存一个纹理

};

#endif // JWOPNEGL_H
