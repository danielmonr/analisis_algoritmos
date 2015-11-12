#ifndef CANVAS_H
#define CANVAS_H

#include <QWidget>
#include <QPainter>

namespace Ui {
class Canvas;
}

class Canvas : public QWidget
{
    Q_OBJECT

public:
    explicit Canvas(QWidget *parent = 0);
    ~Canvas();
    enum Forma {Cuadrado, Polygono, Arco, Cubo, Piramide, Cono};
    enum Transf {Translacion, Rotacion, Escalar};

    QSize minimumSizeHint() const;
    QSize sizeHint() const;

public slots:
    void setFigura(Forma forma);
    void setTransformed(Transf transf);

protected:
    void paintEvent(QPaintEvent *event);

private:
    Ui::Canvas *ui;
    Forma forma;
    Transf transf;

};

#endif // CANVAS_H
