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
        delete R_canion_def;
        delete R_canion_of;
    }
    //Obtengo los valores a partir del spinbox de la interfaz
    D= ui->distancia->value();
    Ho=ui->altura_of->value();
    Hd=ui->altura_def->value();

    //Dibujo las bases para cada cañon
    base_of= new QGraphicsRectItem;
    base_of->setRect(0,escala_Y(Ho-40,maxy),40,Ho-40);
    base_of->setBrush(Qt::blue);
    scene->addItem(base_of);
    base_def= new QGraphicsRectItem;
    base_def->setRect(D,escala_Y(Hd-40,maxy),40,Hd-40);
    base_def->setBrush(Qt::blue);
    scene->addItem(base_def);
    //Dibujo Cañones
    Canion_of=new QGraphicsEllipseItem;
    Canion_of->setRect(0,escala_Y(Ho,maxy),40,40);
    Canion_of->setBrush(Qt::black);
    scene->addItem(Canion_of);
    Canion_def=new QGraphicsEllipseItem;
    Canion_def->setRect(D,escala_Y(Hd,maxy),40,40);
    Canion_def->setBrush(Qt::black);
    scene->addItem(Canion_def);
    //Dibujo las zonas vulnerables para cada cañon
    R_canion_of=new QGraphicsEllipseItem;
    R_canion_of->setRect(-(0.025*D),escala_Y(Ho+(0.025*D),maxy),2*(0.025*D+20),2*(0.025*D+20));
    QPen pen(Qt::red, 3, Qt::DashDotLine, Qt::RoundCap, Qt::RoundJoin);
    R_canion_of->setPen(pen);
    scene->addItem(R_canion_of);

    R_canion_def=new QGraphicsEllipseItem;
    R_canion_def->setRect(D-(0.05*D),escala_Y(Hd+(0.05*D),maxy),2*(0.05*D+20),2*(0.05*D+20));
    QPen pen1(Qt::red, 3, Qt::DashDotLine, Qt::RoundCap, Qt::RoundJoin);
    R_canion_def->setPen(pen1);
    scene->addItem(R_canion_def);



    flag=true;

}
void MainWindow::on_pushButton_2_clicked()
{
    //Obtengo los valores a partir del spinbox de la interfaz
    D= ui->distancia->value();
    Ho=ui->altura_of->value();
    Hd=ui->altura_def->value();

    bOf=new cOfensivo(0.05*D,Ho,D,Hd);
    bOf->setPos(10,50);
    scene->update();
    scene->addItem(bOf);

}


MainWindow::~MainWindow()
{
    delete ui;
}




