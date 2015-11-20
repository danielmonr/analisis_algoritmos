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
    transformaciones.clear();
    this->forma = forma;
    update();
}

void Canvas::setTransformed(Transf transf){
    switch (transf){
    case Translacion:
        transformaciones.push_back(1);
        break;
    case Rotacion:
        transformaciones.push_back(2);
        break;
    case Escalar:
        transformaciones.push_back(3);
        break;
    default:
        transformaciones.push_back(4);
        break;
    }
    this->transf = transf;
    update();
}

void Canvas::paintEvent(QPaintEvent* /*event*/){

    QPoint points[5] = {
        QPoint(45,80), QPoint(20, 50), QPoint(30, 10), QPoint(60, 10), QPoint(70,50)
    };
    QPoint points2[5]= {
        QPoint(95,80), QPoint(70, 50), QPoint(80, 10), QPoint(110, 10), QPoint(120,50)
    };

    QRect rect(10,20,80,60);
    QRect rect2(16, 26, 86, 66);
    QRect rect3(30, 40, 80, 60);
    QRect rectCono(40, 90, 80, 30);
    QPoint cono1(40,105);
    QPoint cono2(120, 105);
    QPoint cono3(80, 50);
    int startAngle = 20 * 16;
    int arcLength = 120 * 16;
    QPainter painter(this);

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
        painter.drawRect(rect);
        painter.drawRect(rect2);
        painter.drawLine(rect.topLeft(), rect2.topLeft());
        painter.drawLine(rect.topRight(), rect2.topRight());
        painter.drawLine(rect.bottomLeft(), rect2.bottomLeft());
        painter.drawLine(rect.bottomRight(), rect2.bottomRight());
        break;
    case Piramide:
        painter.drawPolygon(points, 3);
        painter.drawPolygon(points2,3);
        painter.drawLine(points[0], points2[0]);
        painter.drawLine(points[1], points2[1]);
        painter.drawLine(points[2], points2[2]);
        break;
    case Cono:
        painter.drawEllipse(rectCono);
        painter.drawLine(cono1, cono3);
        painter.drawLine(cono2, cono3);
        break;
    default:
        painter.drawRect(rect);
        painter.drawRect(rect3);
        painter.drawLine(rect.topLeft(), rect3.topLeft());
        painter.drawLine(rect.topRight(), rect3.topRight());
        painter.drawLine(rect.bottomLeft(), rect3.bottomLeft());
        painter.drawLine(rect.bottomRight(), rect3.bottomRight());

        break;
    }

    for (std::vector<int>::iterator it = transformaciones.begin(); it != transformaciones.end(); ++it){
        switch (*it){
        case 1:
            painter.translate(50,50);
            break;
        case 2:
            painter.rotate(10);
            break;
        case 3:
            painter.scale(1.2, 1.2);
            break;
        default:
            painter.scale(0.8, 0.8);
            break;
        }
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
            painter.drawRect(rect);
            painter.drawRect(rect2);
            painter.drawLine(rect.topLeft(), rect2.topLeft());
            painter.drawLine(rect.topRight(), rect2.topRight());
            painter.drawLine(rect.bottomLeft(), rect2.bottomLeft());
            painter.drawLine(rect.bottomRight(), rect2.bottomRight());
            break;
        case Piramide:
            painter.drawPolygon(points, 3);
            painter.drawPolygon(points2,3);
            painter.drawLine(points[0], points2[0]);
            painter.drawLine(points[1], points2[1]);
            painter.drawLine(points[2], points2[2]);
            break;
        case Cono:
            painter.drawEllipse(rectCono);
            painter.drawLine(cono1, cono3);
            painter.drawLine(cono2, cono3);
            break;
        default:
            painter.drawRect(rect);
            painter.drawRect(rect3);
            painter.drawLine(rect.topLeft(), rect3.topLeft());
            painter.drawLine(rect.topRight(), rect3.topRight());
            painter.drawLine(rect.bottomLeft(), rect3.bottomLeft());
            painter.drawLine(rect.bottomRight(), rect3.bottomRight());

            break;
        }

    }
/*

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
*/
}

