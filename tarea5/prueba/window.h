#ifndef WINDOW_H
#define WINDOW_H

#include <QMainWindow>
#include <QtGui>
#include <QComboBox>
#include <QLabel>
#include "canvas.h"
#include <QGridLayout>

namespace Ui {
class Window;
}

class Window : public QMainWindow
{
    Q_OBJECT

public:
    explicit Window(QWidget *parent = 0);
    ~Window();

private slots:
    void shapeChanged();
    void shapeTransformed();

private:
    Ui::Window *ui;
    Canvas *canvas;
    QLabel *shapeLabel;
    QComboBox *shapeComboBox;
    QLabel *transformLabel;
    QComboBox *transformCB;
};

#endif // WINDOW_H
