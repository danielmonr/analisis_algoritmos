#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //boton = new QPushButton("Dibujar", this);
    //boton->setGeometry(QRect(QPoint(150,200), QSize(50, 50)));

    //connect(boton, SIGNAL(clicked()), this, SLOT (handleButton()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    this->hide();
}
