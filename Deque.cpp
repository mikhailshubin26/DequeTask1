#include "Deque.h"

// Инициализируем переменные: передний индекс в 0, задний в -1, текущий размер в 0
Deque::Deque(int capacity) : capacity(capacity), front(0), rear(-1), size(0) {
    data = new char [capacity]; // Выделяем динамическую память под массив элементов
}

Deque::~Deque() {
    delete[] data;
}

bool Deque::isEmpty() const {
    return size == 0;
}

bool Deque::isFull() const {
    return size == capacity;
}

void Deque::pushFront(char value) {
    if (isFull()) {
        std::cerr << "Дек заполнен." << std::endl;
        return;
    }
    front =(front - 1 + capacity) % capacity; // Сдвигаем front циклически влево
    data[front] = value; // Записываем значение в передний элемент
    size++;
}

void Deque::pushBack(char value) {
    if (isFull()) {
        std::cerr << "Дек заполнен." << std::endl;
        return;
    }
    rear = (rear + 1) % capacity; // Сдивгаем rear циклически вправо
    data[rear] = value;
    size++;
}

char Deque::popFront() {
    if (isEmpty()) {
        std::cerr << "Дек заполнен." << std::endl;
        return NULL;
    }
    char value = data[front]; // Запоминаем удаляемый элемент
    front = (front + 1) % capacity;
    size--;
    return value;
}

char Deque::popBack() {
    if (isEmpty()) {
        std::cerr << "Дек заполнен." << std::endl;
        return NULL;
    }
    char value = data[rear];
    rear = (rear - 1 + capacity) % capacity;
    size--;
    return value;
}

char Deque::peekFront() const {
    if (isEmpty()) {
        std::cerr << "Дек заполнен." << std::endl;
        return NULL;
    }
    return data[front];
}

char Deque::peekBack() const {
    if (isEmpty()) {
        std::cerr << "Дек заполнен." << std::endl;
        return NULL;
    }
    return data[rear];
}

void Deque::display() const {
    if (isEmpty()) {
        std::cerr << "Дек заполнен." << std::endl;
        return;
    }
    int i = front;
    std::cout << "Элементы дека: ";
    for (int count = 0; count < size; count++) {
        std::cout << data[count] << " ";
        i = (i + 1) % capacity;
    }
    std::cout << std::endl;
}

