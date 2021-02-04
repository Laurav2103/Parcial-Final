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

    base_of= new QGraphicsRectItem;
    base_of->setRect(0,0,10,20);
    scene->addItem(base_of);
    base_def= new QGraphicsRectItem;
    base_def->setRect(0,50,20,20);
    scene->addItem(base_def);



}

MainWindow::~MainWindow()
{
    delete ui;
}

