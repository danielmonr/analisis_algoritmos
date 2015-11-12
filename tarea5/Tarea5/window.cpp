#include "window.h"
#include <QWidget>
#include <QComboBox>
#include <QLabel>
#include <QGridLayout>

const int IDRole = Qt::UserRole;

Window::Window(QWidget *parent)
    : QWidget(parent)
{

    shapeComboBox = new QComboBox;
    shapeComboBox->addItem(tr("Cuadrado"), Canvas::Cuadrado);
    shapeComboBox->addItem(tr("Polygono"), Canvas::Polygono);
    shapeComboBox->addItem(tr("Arco"), Canvas::Arco);
    shapeComboBox->addItem(tr("Cubo"), Canvas::Cubo);
    shapeComboBox->addItem(tr("Piramide"), Canvas::Piramide);
    shapeComboBox->addItem(tr("Cono"), Canvas::Cono);
    canvas = new Canvas;


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
    mainLayout->addWidget(shapeComboBox, 1, 2);
    mainLayout->addWidget(transformCB, 3,2);

    setLayout(mainLayout);

    shapeChanged();

    setWindowTitle(tr("Tarea 5: Dibujos"));

}

Window::~Window()
{

}

void Window::shapeChanged(){
    canvas->setAttribute(Qt::WA_OpaquePaintEvent, false);
    Canvas::Forma forma = Canvas::Forma(shapeComboBox->itemData(shapeComboBox->currentIndex(), IDRole).toInt());
    canvas->setFigura(forma);
}

void Window::shapeTransformed(){
    canvas->setAttribute(Qt::WA_OpaquePaintEvent, true);
    Canvas::Transf transf = Canvas::Transf(transformCB->itemData(transformCB->currentIndex(), IDRole).toInt());
    canvas->setTransformed(transf);
}
