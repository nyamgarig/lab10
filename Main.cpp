#include <iostream>
#include <ctime>
#include <cstdlib>

#include "LinkedList.h"
#include "Shape.h"

using namespace std;

int main()
{
    srand(time(0));

    LinkedList<Shape*> shapes;

    // Санамсаргүй 25 дүрс үүсгэх
    for (int i = 0; i < 25; i++)
    {
        int type = rand() % 3;

        if (type == 0)
        {
            double r = rand() % 20 + 1;
            shapes.add(new Circle(r));
        }
        else if (type == 1)
        {
            double a = rand() % 20 + 1;
            shapes.add(new Square(a));
        }
        else
        {
            double a = rand() % 20 + 1;
            double h = rand() % 20 + 1;

            shapes.add(new Triangle(a, h));
        }
    }

    // Талбайгаар эрэмбэлэх
    for (int i = 0; i < shapes.length() - 1; i++)
    {
        for (int j = 0; j < shapes.length() - i - 1; j++)
        {
            Shape* s1 = shapes.get(j);
            Shape* s2 = shapes.get(j + 1);

            if (s1->area() > s2->area())
            {
                Shape* temp = s1;

                shapes.remove(j);
                shapes.insert(s2, j);

                shapes.remove(j + 1);
                shapes.insert(temp, j + 1);
            }
        }
    }

    // Хэвлэх
    cout << "===== SORTED SHAPES =====" << endl;

    for (int i = 0; i < shapes.length(); i++)
    {
        shapes.get(i)->print();
    }

    return 0;
}