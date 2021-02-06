#include "cdefensivo.h"

cDefensivo::cDefensivo(float xo,float r,float Ho,float D, float Hd,int p,float an,float v1,QGraphicsItem *parent): QGraphicsItem(parent)
{

    ra=r;
    sprite=QPixmap(":/dibujo.png");
    sprite1=sprite.scaledToHeight(2*ra);
    sprite2=sprite.scaledToWidth(2*ra);
    //recibo los datos ingresados y los guardo
    direccion=-1;
    posy=Hd;
    posx=D;
    Xo=xo;
    Yo=Ho;
    Xd=D;
    Yd=Hd;
    punto=p;
    angle=an;
    V2in=v1;
   //if para generar disparos defensivos dependiendo del boton pulsado
    if(punto==2){
        disparosDef();
        vx=vel[1]; //velocidad inicial en x
        w=ang[1]*(pi/180); //grados a rad
        w=-w;
        v=vx*tan(w); //vy
    }
    else if(punto==3){
        disparoDef2();
        vx=veld[2]; //velocidad inicial en x
        w=angd[2];
        w=-w;
        v=vx*tan(w); //vy

    }



    QTimer *timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(simulacion()));
    timer->start(int(1000*T));



}
void cDefensivo::disparosDef()
{
    int col=0,V0=0,t=0,Vin=5;
    float x=0,y=0,Vxin,Vyin;
    int angle=0;
    for (V0=Vin;V0<=400 && col!=3;V0+=4){
        for (angle=0;angle<90 && col!=3;angle++){
            //Ecuaciones cinematicas
           Vxin=V0*cos((angle)*pi/180);
           Vyin=V0*sin((angle)*pi/180);

           for (t=0;;t++){

                x=Xd-Vxin*t;
                y=Yd+ Vyin*t-(0.5*G*t*t);
                //Condicion de impacto sobre el ofensivo
                if(sqrt(pow((Xo-x),2)+pow((Yo-y),2))<=ra){
                    if(y<0) y=0;
                    ang[col]=angle;
                    vel[col]=V0;
                    imprimir(angle,V0,x,y,t);
                    col+=1;
                    V0+=30;
                    break;
                }
                if(y<0)break;
            }

        }

    }
    if (col!=3) cout<<"No se lograron disparos defensivos efectivos"<<endl;

}

void cDefensivo::disparoDef2()
{

    float x=0, y=0,t2,t=0,thetaD,Vd,vely,velx;
    float t1=(2*V2in*cos((angle)*pi/180))/(Xd-0.05*Xd);
    vely=V2in*sin((angle)*pi/180);
    velx=V2in*cos((angle)*pi/180);
    x=V2in*cos((angle)*pi/180)*2;
    y=Yo +vely*2-(0.5*G*2*2);
    if(normaE(Xd,x,Yd,y)>Xd*0.05){
        for(int col=1;col<4;col++){
            t2=t1+((1-t1)/4.0)*col;
            t=(Xd-0.05*Xd)*t2/velx;
            thetaD=atan((Yo-Yd+vely*t-2*G*t+2*G)/(Xd-velx*t));
            Vd=((Xd-velx*t))/((t-2)*cos(thetaD));
            x=velx*t;
            y=Yo +vely*t-(0.5*G*t*t);
            angd[col]=thetaD;
            veld[col]=Vd;
            imprimir(thetaD*180/pi,Vd,x,y,t);
            }
    }
    else cout<<"No es posible defender el ca"<<char(164)<<"on defensivo"<<endl;

}

void cDefensivo::disparodef3(float Yo, float Xd, float Yd, int angle, int V2in)
{

    float x=0, y=0,t2,t=0,thetaD,Vd,tfinal,velx,vely;

    float t1=(2*V2in*cos((angle)*pi/180))/(Xd-0.05*Xd);    //tamaño del intervalo donde se puede disparar
    vely=V2in*sin((angle)*pi/180);
    velx=V2in*cos((angle)*pi/180);
    x=velx*2;
    y=Yo +vely*2-(0.5*G*2*2);

    if(normaE(Xd,x,Yd,y)>Xd*0.05){
        for(int col=1;col<4;col++){

            t2=t1+((1-t1)/4.0)*col;// se realiza una particion del tiempo
            t=0.95*Xd*t2/velx; // tiempo de colision
            //despeje a partir de igualacion de ecuaciones cinematicas para cada cañon"
            thetaD=atan((Yo-Yd+vely*t-2*G*t+2*G)/(Xd-velx*t));
            Vd=((Xd-velx*t))/((t-2)*cos(thetaD));
            x=velx*t;
            y=Yo +vely*t-(0.5*G*t*t);

            tfinal=2+(Vd*sin(thetaD)+sqrt(Vd*sin(thetaD)*Vd*sin(thetaD)+2*G*Yd))/G;// tiempo en el cual y=0;
            if(tfinal>=(2+(Xd*0.975)/(Vd*cos(thetaD)))){ //verificacion
                t1=t1*1.5;
                col--;
            }
            else {
                t1=(2*velx)/(0.95*Xd);
                imprimir(thetaD*180/pi,Vd,x,y,t);
            }
        }
    }
    else cout<<"No es posible defender el ca"<<char(164)<<"on defensivo"<<endl;

}


void cDefensivo::imprimir(float angle, float V0, float x, float y, float t)
{
    cout<<endl;
    cout<<"El angulo de disparo con el que debe salir la bala es de: "<<angle<<" grados"<<endl;
    cout<<"El impacto se produce con una velocidad incial: "<<V0<<" m/s"<<endl;
    cout<<"Posicion del impacto (X,Y)= ("<<x <<','<<y<<")."<<endl;
    cout<<"Tiempo de impacto: "<<t<<" s"<<endl<<endl;
}

float cDefensivo::normaE(float x1, float x2, float y1, float y2)
{
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
void cDefensivo::simulacion()
{
    float t=4*T;
 //posx=x();

         //ECUACIONES DE MOVIMIENTO:Parábolico
         //Y(t)=y(t-1)+v(t-1)*T-g/2*T*T
         //V(t)=V(t-1)-g*T

       posy=posy+v*t+(0.5*g*t*t); //tener en cuenta Vy y Vx para el angulo de disp
       v=v+g*t;
       posx=posx+vx*t*direccion;
       setPos(posx,posy);
       cont++;
          if(cont%3==0){
              scene()->addEllipse(posx,posy,2*ra,2*ra);
          }
}



void cDefensivo::setXd(float value)
{
    Xd = value;
}

void cDefensivo::setYd(float value)
{
    Yd = value;
}

float cDefensivo::getDd() const
{
    return dd;
}

void cDefensivo::setDd(float value)
{
     dd = value;
}


void cDefensivo::setD(float value)
{
     d = value;
}
QRectF cDefensivo::boundingRect() const {

    return QRectF(-2,-2,2*ra,2*ra);
}

//Se dibuja el objeto en la escena a partir del sprite
void cDefensivo::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(0,0, sprite2, posSprite, 0,2*ra, 2*ra);
    setTransformOriginPoint(boundingRect().center());
    Q_UNUSED(widget)
    Q_UNUSED(option)
}
