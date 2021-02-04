//Parcial Final. Informatica II. 
//Laura Isabel Vidal.

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

   // timer=new QTimer;
    //se inicialza el timer de la simulación
//    connect(timer,SIGNAL(timeout()),this,SLOT(on_pushButton_clicked()));
//    timer->start(100);

    scene = new QGraphicsScene;
    scene->setSceneRect(0,0,ui->graphicsView->width()-10,ui->graphicsView->height()-10);
    ui->graphicsView->setScene(scene); //agrego la escena al graphicsview





}
int MainWindow::escala_Y(int y, int max)
{
    return  max-y;
}
void MainWindow::on_pushButton_clicked()
{
    if(flag){
        delete base_of;
        delete base_def;
        delete Canion_def;
        delete Canion_of;
    }
    D= ui->distancia->value();
    Ho=ui->altura_of->value();
    Hd=ui->altura_def->value();

    //Dibujo las bases para cada cañon
    base_of= new QGraphicsRectItem;
    base_of->setRect(0,escala_Y(Ho-40,maxy),40,Ho-40);
    scene->addItem(base_of);
    base_def= new QGraphicsRectItem;
    base_def->setRect(D,escala_Y(Hd-40,maxy),40,Hd-40);
    scene->addItem(base_def);
    //Dibujo Cañones
    Canion_of=new QGraphicsEllipseItem;
    Canion_of->setRect(0,escala_Y(Ho,maxy),40,40);
    scene->addItem(Canion_of);
    Canion_def=new QGraphicsEllipseItem;
    Canion_def->setRect(D,escala_Y(Hd,maxy),40,40);
    scene->addItem(Canion_def);
    flag=true;

}

MainWindow::~MainWindow()
{
    delete ui;
}



