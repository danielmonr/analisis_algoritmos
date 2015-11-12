#include "window.h"
#include "canvas.h"
#include "ui_window.h"
#include <QtGui>
#include <iostream>

const int IDRole = Qt::UserRole;

Window::Window(QWidget *parent) :
    QMainWindow(parent)
{

    canvas = new Canvas;
    shapeComboBox = new QComboBox;
    shapeComboBox->addItem(tr("Cuadrado"), Canvas::Cuadrado);
    shapeComboBox->addItem(tr("Polygono"), Canvas::Polygono);
    shapeComboBox->addItem(tr("Arco"), Canvas::Arco);
    shapeComboBox->addItem(tr("Cubo"), Canvas::Cubo);
    shapeComboBox->addItem(tr("Piramide"), Canvas::Piramide);
    shapeComboBox->addItem(tr("Cono"), Canvas::Cono);

    shapeLabel = new QLabel(tr("&Forma:"));
    shapeLabel->setBuddy(shapeComboBox);

    transformCB = new QComboBox;
    transformCB->addItem(tr("Transladar"), Canvas::Translacion);
    transformCB->addItem(tr("Rotar"), Canvas::Rotacion);
    transformCB->addItem(tr("Escalar"), Canvas::Escalar);

    transformLabel = new QLabel(tr("&Transformacion:"));
    transformLabel->setBuddy(transformCB);

    connect(shapeComboBox, SIGNAL(activated(int)), this, SLOT(shapeChanged()));
    connect(transformCB, SIGNAL(activated(int)), this, SLOT(shapeTransformed()));

    QGridLayout *mainLayout = new QGridLayout;

    mainLayout->setColumnStretch(0, 1);
    mainLayout->setColumnStretch(0, 3);
    mainLayout->addWidget(canvas, 0, 0, 1, 4);
    mainLayout->setRowMinimumHeight(1,6);
    mainLayout->addWidget(shapeLabel, 2, 1, Qt::AlignRight);
    mainLayout->addWidget(shapeComboBox, 2, 2);
    mainLayout->addWidget(transformCB, 3,2);

    //shapeChanged();

    setWindowTitle(tr("Tarea 5: Dibujos"));
}

Window::~Window()
{
    delete ui;
}

void Window::shapeChanged(){

    Canvas::Forma forma = Canvas::Forma(shapeComboBox->itemData(shapeComboBox->currentIndex(), IDRole).toInt());
    canvas->setFigura(forma);
}

void Window::shapeTransformed(){
}
