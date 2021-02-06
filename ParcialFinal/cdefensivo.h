#ifndef CDEFENSIVO_H
#define CDEFENSIVO_H
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



class cDefensivo: public QObject, public QGraphicsItem
{    Q_OBJECT

private:

     //parametros del cañon defensivo
     float Yd; // pos inicial en y
     float dd=0.025*d; // rango de destruccion
     float d;
     float Xd; //pos inicial en x del cañon def
     float pi=3.1416;
     float G=9.81;

     float normaE(float x1, float x2, float y1, float y2);
     void imprimir(float angle,float V0,float x,float y,float t);

     float T=0.05; //tiempo de sim
     float Xo, Yo;
     float ra,w;
     float g=10;
      float ang[2]={};
      float vel[2]={};

 public slots:
     void simulacion();

 public:
     cDefensivo(float xi,float r,float Ho,float D, float Hd,QGraphicsItem *parent= nullptr);
     QRectF boundingRect() const;
     void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
     void disparosDef();
     void disparoDef2(float Yo,float Xd,float Yd,int anglei, int V2ini);
     void disparodef3(float Yo, float Xd, float Yd, int anglei, int V2ini);

     float  posy,posx;
     float  vx,v=0;
     int direccion;

     float getXd() const;
     void setXd(float value);
     float getYd() const;
     void setYd(float value);
     float getDd() const;
     void setDd(float value);
     float getD() const;
     void setD(float value);

};

#endif // CDEFENSIVO_H
