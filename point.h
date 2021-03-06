#ifndef POINT_H
#define POINT_H

#include "spring.h"
#include "vector.h"
#include "vector"
#include <QObject>
using namespace std;

class Point: public QObject {
    Q_OBJECT
public:
    Point();
    Point(double p, double v, double u, double V1, double V2);//масса, начальные координаты и скорость
    double Weight();//верноуть вес пружины
    void hook(Spring *spring);//подцепить к точке пружину
    void del_hook();//отцепить пружину от груза
    double loc_x();//вернуть координату x
    double loc_y();//вернуть координату y
    void Move(const Vector& dr);//Передвинуть точку
    Vector Movement(double dt);//вектор ускрения точки
private:
    vector<Spring*> s;//пружины, подцепленные к данному грузу
    Vector r;//радиус-вектор точки
    double m;//масса
    Vector V;//скорость
    Vector Force(double g);//равнодействующая сил для данной точки

public slots:
    void move();
};
#endif // POINT_H
