#ifndef LINKEDLIST_H
#define LINKEDLIST_H

template <class T>
class LinkedList
{
private:
    struct Node
    {
        T data;
        Node* next;
        Node(T d)
        {
            data = d;
            next = NULL;
        }
    };

    Node* head;
    int len;

public:
    LinkedList()
    {
        head = NULL;
        len = 0;
    }

    // Сүүлд нэмэх
    void add(T t)
    {
        Node* newNode = new Node(t);

        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            Node* temp = head;

            while (temp->next != NULL)
            {
                temp = temp->next;
            }

            temp->next = newNode;
        }

        len++;
    }

    // index дээр оруулах
    void insert(T t, int index)
    {
        if (index < 0 || index > len)
            return;

        Node* newNode = new Node(t);

        if (index == 0)
        {
            newNode->next = head;
            head = newNode;
        }
        else
        {
            Node* temp = head;

            for (int i = 0; i < index - 1; i++)
            {
                temp = temp->next;
            }

            newNode->next = temp->next;
            temp->next = newNode;
        }

        len++;
    }

    // Элемент авах
    T get(int index)
    {
        Node* temp = head;

        for (int i = 0; i < index; i++)
        {
            temp = temp->next;
        }

        return temp->data;
    }

    // Устгах
    void remove(int index)
    {
        if (index < 0 || index >= len)
            return;

        Node* del;

        if (index == 0)
        {
            del = head;
            head = head->next;
        }
        else
        {
            Node* temp = head;

            for (int i = 0; i < index - 1; i++)
            {
                temp = temp->next;
            }

            del = temp->next;
            temp->next = del->next;
        }

        delete del;
        len--;
    }

    // Урт
    int length()
    {
        return len;
    }
};

#endif