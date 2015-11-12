#ifndef WINDOW_H
#define WINDOW_H

#include "canvas.h"
#include <QLabel>
#include <vector>

QT_BEGIN_NAMESPACE
class QComboBox;
QT_END_NAMESPACE

class Window : public QWidget
{
    Q_OBJECT

public:
    explicit Window(QWidget *parent = 0);
    ~Window();

private slots:
    void shapeChanged();
    void shapeTransformed();

private:
    Canvas *canvas;
    QLabel *shapeLabel;
    QComboBox *shapeComboBox;
    QLabel *transformLabel;
    QComboBox *transformCB;

};

#endif // WINDOW_H
