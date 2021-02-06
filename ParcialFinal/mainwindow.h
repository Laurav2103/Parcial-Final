#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QPixmap>
#include <QPainter>
#include <QTimer>
#include <QObject>
#include <QLabel>
#include <math.h>
#include <QString>
#include "cofensivo.h"
#include "cdefensivo.h"
using namespace std;


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    
    ~MainWindow();

public slots:
   // void simulacion();
private slots:
    void on_pushButton_clicked();


    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    
    Ui::MainWindow *ui;
    QTimer *timer;
    QGraphicsScene *scene;
    QGraphicsRectItem *base_of;
    QGraphicsRectItem *base_def;
    QGraphicsEllipseItem *Canion_of;
    QGraphicsEllipseItem *Canion_def;
    QGraphicsEllipseItem *R_canion_of;
    QGraphicsEllipseItem *R_canion_def;


    qreal Ho,Hd,D,tetha,Vin;//Variables que el usuario va a ingresar
    int maxy=481; //Límite max en y
    bool flag;
    //Definición de objeto de las clases cOfensivo y cDefensivo:
    cOfensivo *bOf;
    cDefensivo *bDef;




    //Funcion para el sistema de referencia
    int escala_Y(int y, int max);


};
#endif // MAINWINDOW_H
