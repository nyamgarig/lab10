#ifndef SHAPES_H
#define SHAPES_H

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

// Суурь класс
class Shape2D {
public:
    virtual double getArea() = 0;   // Хийсвэр функц
    virtual string getName() = 0;   // Дүрсийн нэр авах
    virtual void print() = 0;       // Мэдээлэл хэвлэх
    virtual ~Shape2D() {}           // Виртуал деструктор
};

// Тойрог
class Circle : public Shape2D {
    double radius;
public:
    Circle(double r) : radius(r) {}
    double getArea() override { return M_PI * radius * radius; }
    string getName() override { return "Circle"; }
    void print() override { 
        cout << "Circle (r=" << radius << ") \tArea: " << getArea(); 
    }
};

// Дөрвөлжин
class Square : public Shape2D {
    double side;
public:
    Square(double s) : side(s) {}
    double getArea() override { return side * side; }
    string getName() override { return "Square"; }
    void print() override { 
        cout << "Square (a=" << side << ") \tArea: " << getArea(); 
    }
};

// Гурвалжин
class Triangle : public Shape2D {
    double base, height;
public:
    Triangle(double b, double h) : base(b), height(h) {}
    double getArea() override { return 0.5 * base * height; }
    string getName() override { return "Triangle"; }
    void print() override { 
        cout << "Triangle (b=" << base << ", h=" << height << ") \tArea: " << getArea(); 
    }
};

#endif