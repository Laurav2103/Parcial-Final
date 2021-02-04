#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QPixmap>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    
    ~MainWindow();

private:
    
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    QGraphicsRectItem *base_of;
    QGraphicsRectItem *base_def;
    QGraphicsEllipseItem *Canion_of;
    QGraphicsEllipseItem *Canion_def;


    //Funcion para el sistema de referencia
    int escala_Y(int y, int max);


};
#endif // MAINWINDOW_H
