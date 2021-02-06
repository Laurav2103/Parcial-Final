#ifndef COFENSIVO_H
#define COFENSIVO_H
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QPixmap>
#include <QPainter>
#include <QTimer>
#include <QObject>
#include <math.h>
#include <iostream>
#include <QTimer>
using namespace std;


class cOfensivo: public QObject, public QGraphicsItem
{
    Q_OBJECT
private:
    //parametros del cañon ofensivo

    float Xo=0; //pos inicial en x
    float Yo=0; //pos inicial en y
    float d=0;
    float d0=0.05*d; //rango de destruccion
    float pi=3.1416;
    float G=9.81;
    //
    float T=0.05; //tiempo de sim
    float Xd, Yd;

    // vectores donde se guardaran los angulos y velocidades cuando se generan disparos of
    float ang[2]={};
    float vel[2]={};
    float a,b,c,w;

    float ecu_estudiante(float A,float B,float C);
    void imprimir(float angle, float V0, float x, float y, float t);
  //  QGraphicsScene *scene;
    QGraphicsEllipseItem *bulletOf;
    int direccion;
    float g=10;
    float ra;

public slots:
    void simulacion();

public:
    cOfensivo(float xi,float r,float Ho,float D,float Hd,QGraphicsItem *parent= nullptr);
    QRectF boundingRect() const;
    QPixmap sprite,sprite1,sprite2;
    int posSprite;
    float  posy,posx;
    float  vx,v=0;
    int cont;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void destructor(float Xd, float Yd, float angleD, float Vd);
    void disparosOf();

    float getD() const;
    void setD(float value);

    float getXo() const;
    void setXo(float value);

    float getYo() const;
    void setYo(float value);

    float getD0() const;
    void setD0(float value);


};

#endif // COFENSIVO_H
