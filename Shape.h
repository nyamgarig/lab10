#ifndef SHAPE_H
#define SHAPE_H

#include <iostream>

using namespace std;

// Base Class

class Shape
{
public:
    virtual double area() = 0;
    virtual void print() = 0;
};

// Circle
class Circle : public Shape
{
private:
    double r;

public:
    Circle(double radius)
    {
        r = radius;
    }

    double area()
    {
        return 3.14159 * r * r;
    }

    void print()
    {
        cout << "Circle  Radius = " << r << "  Area = " << area() << endl;
    }
};

// Square
class Square : public Shape
{
private:
    double a;

public:
    Square(double side)
    {
        a = side;
    }

    double area()
    {
        return a * a;
    }

    void print()
    {
        cout << "Square  Side = " << a << "  Area = " << area() << endl;
    }
};


// Triangle
class Triangle : public Shape
{
private:
    double a;
    double h;

public:
    Triangle(double side, double height)
    {
        a = side;
        h = height;
    }

    double area()
    {
        return (a * h) / 2.0;
    }

    void print()
    {
        cout << "Triangle  Side = " << a << " Height = " << h << "  Area = " << area() << endl;
    }
};

#endif