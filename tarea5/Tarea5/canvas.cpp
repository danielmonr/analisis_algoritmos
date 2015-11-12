#include "canvas.h"

Canvas::Canvas(QWidget *parent) :
    QWidget(parent)
{
    forma = Cuadrado;

    setBackgroundRole(QPalette::Base);
    setAutoFillBackground(true);
}

Canvas::~Canvas()
{
}

QSize Canvas::sizeHint() const{
    return QSize(400,200);
}

QSize Canvas::minimumSizeHint() const {
    return QSize(100,100);
}

void Canvas::setFigura(Forma forma){
    this->forma = forma;
    update();
}

void Canvas::setTransformed(Transf transf){
    this->transf = transf;
    update();
}

void Canvas::paintEvent(QPaintEvent* /*event*/){

    /*static const QPoint points[4] = {
        QPoint(0,80),
        QPoint(20,10),
        QPoint(80,30),
        QPoint(90,70)
    };
    QRect rect(10, 20, 80, 60);
    QPainterPath path;
    path.moveTo(20, 80);
    path.lineTo(20, 30);
    path.cubicTo(80, 0, 50, 50, 80, 80);
    */

    QPoint points[5] = {
        QPoint(45,80), QPoint(20, 50), QPoint(30, 10), QPoint(60, 10), QPoint(70,50)
    };

    QRect rect(10,20,80,60);
    int startAngle = 20 * 16;
    int arcLength = 120 * 16;
    QPainter painter(this);


    switch (transf){
    case Translacion:
        painter.translate(50,50);
        break;
    case Rotacion:
        painter.rotate(10);
        break;
    case Escalar:
        painter.scale(1.2,1.9);
        break;
    default:
        break;
    }
    painter.save();

    switch (forma){
    case Cuadrado:
        painter.drawRect(rect);
        break;
    case Polygono:
        painter.drawPolygon(points, 5);
        break;
    case Arco:
        painter.drawArc(rect, startAngle, arcLength);
        break;
    case Cubo:
        break;
    case Piramide:
        break;
    case Cono:
        break;
    default:
        break;
    }

}

