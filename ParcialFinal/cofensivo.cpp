#include "cofensivo.h"

cOfensivo::cOfensivo(float xi,float r,float Ho,float D, float Hd,QGraphicsItem *parent): QGraphicsItem(parent)
{

    //Agrego la imagen
    setFlag(ItemClipsToShape);
    ra=r; //radio de destruccion
    sprite=QPixmap(":/dibujo.png");
    sprite1=sprite.scaledToHeight(2*ra);
    sprite2=sprite.scaledToWidth(2*ra);
    //recibo los datos ingresados
    posy=Ho;
    posx=xi;
    direccion=1;
    Yo=Ho;
    d=D;
    Xd=D;
    Yd=Hd;
    //llamo la funcion para generar disparos ofensivos
    disparosOf();
    //Realizo operaciones para ingresar valores al slot simulacion
    vx=vel[0]; //velocidad inicial en x
    w=ang[0]*(pi/180); //grados a rad
    w=-w;
    v=vx*tan(w); //vy
    a=xi;
    b=vel[0];
    c=v; //vel y
    QTimer *timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(simulacion()));
    timer->start(int(1000*T));

}
float cOfensivo::ecu_estudiante(float A, float B, float C)
{
    return (-B-sqrt(B*B-4*A*C))/(2*A);
}

void cOfensivo::disparosOf()
{
    int col=0,Vin=5;
    float x=0, y=0,Vxin,Vyin;

    for (int V0=Vin;V0<=400 && col!=3;V0+=4){
        for (int angle=0;angle<90 && col!=3;angle++){
            for (int t=0;;t++){
                //Ecuaciones cinematicas
                Vxin=V0*cos(angle*pi/180);
                Vyin=V0*sin(angle*pi/180);
                x=Vxin*t;
                y=Yo+Vyin*t-(0.5*G*t*t);
                //condición de impacto con el defensivo
                if(sqrt(pow((Xd-x),2)+pow((Yd-y),2))<=ra){
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
    if (col!=3)cout<<"No se lograron disparos ofensivos efectivos ";


}

void cOfensivo::imprimir(float angle, float V0, float x, float y, float t)
{

    cout<<"El angulo de disparo con el que debe salir la bala es de: "<<angle<<" grados"<<endl;
    cout<<"El impacto se produce con una velocidad incial: "<<V0<<" m/s"<<endl;
    cout<<"Posicion del impacto (X,Y)= ("<<x <<','<<y<<")."<<endl;
    cout<<"Tiempo de impacto: "<<t<<" s"<<endl<<endl;
}

void cOfensivo::simulacion()
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


float cOfensivo::getD0() const
{
    return d0;
}


void  cOfensivo::setD(float value)
{
    d = value;
}



void  cOfensivo::setXo(float value)
{
    Xo = value;
}



void  cOfensivo::setYo(float value)
{
    Yo = value;
}


void  cOfensivo::setD0(float value)
{
    d0 = value;
}
QRectF cOfensivo::boundingRect() const {

    return QRectF(-2,-2,2*ra,2*ra);
}

//Se dibuja el objeto en la escena a partir del sprite
void cOfensivo::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

    painter->drawPixmap(0,0, sprite2, posSprite, 0,2*ra, 2*ra);
    setTransformOriginPoint(boundingRect().center());
    Q_UNUSED(widget)
    Q_UNUSED(option)
}


