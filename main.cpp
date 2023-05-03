#include "iostream"

using namespace std;
struct Node {
    int number;
    int time;
    Node *next;
};


struct Stack {
    Node *top;

    Stack() {
        top = nullptr;
    }

    bool isEmpty();

    void pop();

    void push(int num, int time);

    int peekNumber();

    int peekTime();

};

bool Stack::isEmpty() {
    return top == nullptr;
}

void Stack::pop() {
    if (isEmpty()) {
        std::cout << "Stack is empty!";
        return;
    }
    Node *temp = top;
    top = top->next;
    delete temp;
}

void Stack::push(int num, int time) {
    Node *newNode = new Node();
    newNode->number = num;
    newNode->time = time;
    newNode->next = top;
    top = newNode;
}

int Stack::peekNumber() {
    if (isEmpty()) {
        std::cout << "Stack is empty!";
        return -1;
    }
    return top->number;
}

int Stack::peekTime() {
    if (isEmpty()) {
        std::cout << "Stack is empty!";
        return -1;
    }
    return top->time;
}


struct Queue {
    int size;

    Queue() {
        size = 0;
    }

    Stack s1, s2;

    void enqueue();

    void dequeue();

    bool isEmpty();

    double averageProcessingTime();

    void getListOfQueue();

};

void Queue::enqueue() {
    int time = rand() % 270 + 30;
    s1.push(++size, time);
}

void Queue::dequeue() {
    if (isEmpty()) {
        cout << "Queue is empty.";
        return;
    }
    if (s2.isEmpty()) {
        while (!s1.isEmpty()) {
            s2.push(s1.peekNumber(), s1.peekTime());
            s1.pop();
        }
    }
    s2.pop();
    --size;
}

bool Queue::isEmpty() {
    return s1.isEmpty() && s2.isEmpty();
}

double Queue::averageProcessingTime() {
    if (isEmpty()) {
        cout << "Queue is empty.";
        return -1;
    }
    double totalTime = 0;
    while (s1.top != nullptr) {
        totalTime += s1.peekTime();
        s2.push(s1.peekNumber(),s1.peekTime());
        s1.pop();
    }

    return totalTime / size;
}

void Queue::getListOfQueue() {
    if (isEmpty()){
        cout<<"Queue is empty.";
        return;
    }
    double averageTime=averageProcessingTime();
    while (!isEmpty()) {
        cout<<s2.peekNumber()<<". Kisi  "<<"Bekleme suresi: "<<s2.peekTime()<<"\n";
        dequeue();
    }
    cout<<"Ortalama bekleme suresi: "<<averageTime;
}


void menu() {
    cout << "<<<==========Kuyruk Uygulamasi-1==========>>>\n";
    cout << "Lutfen kuyrukdaki kisi sayisini belirleyiniz.\n" << endl;


}

int main() {
    Queue *q = new Queue();
    int n;
    menu();
    cin >> n;
    while (q->size != n) {
        q->enqueue();
    }
    q->getListOfQueue();

    return 0;
}




