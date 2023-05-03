#include "iostream"

using namespace std;
#define STACK_LENGTH 5

struct Stack {
    int numberArr[STACK_LENGTH];
    int timeArr[STACK_LENGTH];
    int top;

    Stack() {
        top = 0;
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
    --top;
}

void Stack::push(int number, int time) {
    if (top < STACK_LENGTH) {
        numberArr[top] = number;
        timeArr[top] = time;
        ++top;
        return;
    }
    cout << "Stack is full.";

}

bool Stack::isEmpty() {
    return top == 0;
}

int Stack::peekNumber() {
    return numberArr[top];
}

int Stack::peekTime() {
    return timeArr[top];
}

struct Queue {
    Stack s1,s2;

    void enqueue();

    void dequeue();

    bool isEmpty();

    double averageProcessingTime();

    void getListOfQueue();


};

bool Queue::isEmpty() {
    return s1.isEmpty()&&s2.isEmpty();
}

void Queue::enqueue() {
    int time=rand()%271+30;
    if (isEmpty()){
        s1.push(s1.top + 1, time);
        return;
    }
    if (s1.top==STACK_LENGTH){
        cout<<"Queue is full";
        return;
    }
    for (int i = s1.top; i>-1; --i) {
        if (s1.timeArr[i]>time){
            int temp=s1.timeArr[i];
            s1.timeArr[i+1]=temp;
            temp=s1.numberArr[i];
            s1.numberArr[i+1]=temp;
        } else {
            ++s1.top;
            s1.timeArr[i]=time;
            s1.numberArr[i]=s1.top;
            break;
        }

    }



}

void Queue::dequeue() {
    s1.pop();
}

int main() {

    return 0;
}