#include <iostream>
#include <ctime>
#include "Shapes.h"
#include "LinkedList.h"

using namespace std;

int main() {
    srand(time(0));
    LinkedList<Shape2D*> list_of_shapes;

    // 1. Санамсаргүй 20-30 дүрс үүсгэх
    int total = rand() % 11 + 20; 
    for (int i = 0; i < total; i++) {
        int choice = rand() % 3;
        double v1 = (rand() % 100 + 1) / 10.0;
        double v2 = (rand() % 100 + 1) / 10.0;

        if (choice == 0) list_of_shapes.add(new Circle(v1));
        else if (choice == 1) list_of_shapes.add(new Square(v1));
        else list_of_shapes.add(new Triangle(v1, v2));
    }

    // 2. Талбайгаар нь эрэмбэлэх (Bubble Sort)
    for (int i = 0; i < list_of_shapes.length() - 1; i++) {
        for (int j = 0; j < list_of_shapes.length() - i - 1; j++) {
            if (list_of_shapes.get(j)->getArea() > list_of_shapes.get(j + 1)->getArea()) {
                list_of_shapes.swap(j, j + 1);
            }
        }
    }

    // 3. Үр дүнг хэвлэх
    cout << "Sorted Shapes by Area (Total: " << list_of_shapes.length() << ")\n";
    for (int i = 0; i < list_of_shapes.length(); i++) {
        cout << i + 1 << ". ";
        list_of_shapes.get(i)->print();
        cout << endl;
    }

    // 4. Санах ойг цэвэрлэх
    for (int i = 0; i < list_of_shapes.length(); i++) {
        delete list_of_shapes.get(i);
    }

    return 0;
}