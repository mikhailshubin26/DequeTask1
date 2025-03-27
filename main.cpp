#include <iostream>
#include "Deque.h"

bool isPalindrome(const std::string& expression) {
    Deque deque(expression.length());

    for (char ch : expression) {
        deque.pushBack(ch);
    }

    while (!deque.isEmpty()) {
        if (deque.peekFront() == deque.peekBack()) {
            deque.popFront();
            if (!deque.isEmpty()) {
                deque.popBack();
            }
        } else {
            return false;
        }
    }
    return true;
}

int main() {
    std::string expression;

    std::cout << "Введите строку: ";
    std::getline(std::cin, expression);

    if (isPalindrome(expression)) {
        std::cout << "yes" << std::endl;
    } else {
        std::cout << "no" << std::endl;
    }

    return 0;
}