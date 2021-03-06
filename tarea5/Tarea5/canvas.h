#ifndef CANVAS_H
#define CANVAS_H

#include <QWidget>
#include <QPainter>
#include <vector>

class Canvas : public QWidget
{

    Q_OBJECT

public:
    explicit Canvas(QWidget *parent = 0);
    ~Canvas();
    enum Forma {Cuadrado, Polygono, Arco, Cubo, Piramide, Cono, Prisma};
    enum Transf {Translacion, Rotacion, Escalar, Achicar};

    QSize minimumSizeHint() const;
    QSize sizeHint() const;

    static std::vector<QPoint> puntos;

public slots:
    void setFigura(Forma forma);
    void setTransformed(Transf transf);

protected:
    void paintEvent(QPaintEvent *event);

private:
    Forma forma;
    Transf transf;
    std::vector<int> transformaciones;
};

#endif // CANVAS_H
