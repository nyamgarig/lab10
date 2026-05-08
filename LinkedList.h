#ifndef LINKEDLIST_H
#define LINKEDLIST_H

template <typename T>
struct Node {
    T data;
    Node* next;
    Node(T t) : data(t), next(nullptr) {}
};

template <typename T>
class LinkedList {
private:
    Node<T>* head;
    int count;

public:
    LinkedList() : head(nullptr), count(0) {}

    // Сүүлд нэмэх
    void add(T t) {
        Node<T>* newNode = new Node<T>(t);
        if (!head) {
            head = newNode;
        } else {
            Node<T>* temp = head;
            while (temp->next) temp = temp->next;
            temp->next = newNode;
        }
        count++;
    }

    // Индексээр оруулах
    void insert(T t, int index) {
        if (index < 0 || index > count) return;
        Node<T>* newNode = new Node<T>(t);
        if (index == 0) {
            newNode->next = head;
            head = newNode;
        } else {
            Node<T>* temp = head;
            for (int i = 0; i < index - 1; i++) temp = temp->next;
            newNode->next = temp->next;
            temp->next = newNode;
        }
        count++;
    }

    // Утга авах
    T get(int index) {
        Node<T>* temp = head;
        for (int i = 0; i < index; i++) temp = temp->next;
        return temp->data;
    }

    // Устгах
    void remove(int index) {
        if (index < 0 || index >= count) return;
        Node<T>* temp = head;
        if (index == 0) {
            head = head->next;
            delete temp;
        } else {
            for (int i = 0; i < index - 1; i++) temp = temp->next;
            Node<T>* toDelete = temp->next;
            temp->next = toDelete->next;
            delete toDelete;
        }
        count--;
    }

    int length() { return count; }

    // Жагсаалтын өгөгдлийг солих (Эрэмбэлэлтэд ашиглана)
    void swap(int i, int j) {
        if (i == j) return;
        Node<T>* nodeI = head;
        for (int k = 0; k < i; k++) nodeI = nodeI->next;
        Node<T>* nodeJ = head;
        for (int k = 0; k < j; k++) nodeJ = nodeJ->next;
        
        T temp = nodeI->data;
        nodeI->data = nodeJ->data;
        nodeJ->data = temp;
    }

    ~LinkedList() {
        while (head) {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

#endif