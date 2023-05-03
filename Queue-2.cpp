#include "iostream"

using namespace std;
#define STACK_LENGTH 5

struct Stack {
    int numberArr[STACK_LENGTH];
    int timeArr[STACK_LENGTH];
    int _top;

    Stack() {
        _top = 0;
    }

    void pop();

    void push(int number, int time);

    bool isEmpty();

    int peekNumber();

    int peekTime();
};

void Stack::pop() {
    if (isEmpty()) {
        cout << "Stack is empty.";
        return;
    }
    --_top;
}

void Stack::push(int number, int time) {
    if (_top < STACK_LENGTH) {
        numberArr[_top] = number;
        timeArr[_top] = time;
        ++_top;
        return;
    }
    cout << "Stack is full.";

}

bool Stack::isEmpty() {
    return _top == 0;
}

int Stack::peekNumber() {
    return numberArr[_top];
}

int Stack::peekTime() {
    return timeArr[_top];
}

int main() {

    return 0;
}