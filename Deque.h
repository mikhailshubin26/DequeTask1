#ifndef DEQUE_H
#define DEQUE_H

#include <iostream>

class Deque {
    public:
    Deque(int capacity=100);
    ~Deque();

    void pushFront(char ch);
    void pushBack(char ch);

    char popFront();
    char popBack();

    char peekFront() const;
    char peekBack() const;

    bool isEmpty() const;
    bool isFull() const;
    void display() const;

private:
    char* data; // Указатель на массив данных
    int front; // Индекс передннего элемента
    int rear; // Индекс заднего элемента
    int capacity; // Максимальная вместимость очереди
    int size; // Текущий размер очереди
};

#endif