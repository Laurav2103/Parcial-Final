//Parcial Final. Informatica II. 
//Laura Isabel Vidal.

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene = new QGraphicsScene;
    scene->setSceneRect(0,0,ui->graphicsView->width()-10,ui->graphicsView->height()-10);
    ui->graphicsView->setScene(scene); //agrego la escena al graphicsview

    //Dibujo las bases para cada cañon
    base_of= new QGraphicsRectItem;
    base_of->setRect(600,escala_Y(0,431)-100,40,100);
    scene->addItem(base_of);
    base_def= new QGraphicsRectItem;
    base_def->setRect(0,escala_Y(0,431)-100,40,100);
    scene->addItem(base_def);
    //Dibujo Cañones
    Canion_of=new QGraphicsEllipseItem;
    Canion_of->setRect(600,escala_Y(0,431)-140,40,40);
    scene->addItem(Canion_of);
    Canion_def=new QGraphicsEllipseItem;
    Canion_def->setRect(0,escala_Y(0,431)-140,40,40);
    scene->addItem(Canion_def);



}
int MainWindow::escala_Y(int y, int max)
{
    return  max-y;
}

MainWindow::~MainWindow()
{
    delete ui;
}

