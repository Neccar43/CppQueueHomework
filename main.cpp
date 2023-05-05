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

    int peakNumber();

    int peakTime();

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

int Stack::peakNumber() {
    if (isEmpty()) {
        std::cout << "Stack is empty!";
        return -1;
    }
    return top->number;
}

int Stack::peakTime() {
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

    void enqueue(int time);

    void dequeue();

    bool isEmpty();

    double averageProcessingTime();

    void getListOfQueue();

};

void Queue::enqueue(int time) {
    s1.push(++size, time);
}

void Queue::dequeue() {
    if (isEmpty()) {
        cout << "Queue is empty.";
        return;
    }
    if (s2.isEmpty()) {
        while (!s1.isEmpty()) {
            s2.push(s1.peakNumber(), s1.peakTime());
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
        totalTime += s1.peakTime();
        s2.push(s1.peakNumber(), s1.peakTime());
        s1.pop();
    }

    return totalTime / size;
}

void Queue::getListOfQueue() {
    if (isEmpty()) {
        cout << "Queue is empty.";
        return;
    }
    double averageTime = averageProcessingTime();
    int standbyTime = 0;
    while (!isEmpty()) {
        standbyTime += s2.peakTime();
        cout << s2.peakNumber() << ". Kisi| " << "Islem suresi: " << s2.peakTime() << " |Bekleme suresi: "
             << standbyTime << "\n";
        dequeue();
    }
    cout << "Ortalama islem suresi: " << averageTime;
}


#define STACK_LENGTH 13

struct Stack2 {
    int numberArr[STACK_LENGTH];
    int timeArr[STACK_LENGTH];
    int top;

    Stack2() {
        top = 0;
    }

    void pop();

    void push(int number, int time);

    bool isEmpty();

    int peakNumber();

    int peakTime();
};

void Stack2::pop() {
    if (isEmpty()) {
        cout << "Stack is empty.";
        return;
    }
    --top;
}

void Stack2::push(int number, int time) {
    if (top < STACK_LENGTH) {
        numberArr[top] = number;
        timeArr[top] = time;
        ++top;
        return;
    }
    cout << "Stack is full.";

}

bool Stack2::isEmpty() {
    return top == 0;
}

int Stack2::peakNumber() {
    return numberArr[top - 1];
}

int Stack2::peakTime() {
    return timeArr[top - 1];
}

struct PriorityQueue {
    Stack2 s1, s2;

    void enqueue(int time);

    void dequeue();

    bool isEmpty();

    double averageProcessingTime();

    void getListOfQueue();

    void getListOfWaitingMore();


};

bool PriorityQueue::isEmpty() {
    return s1.isEmpty() && s2.isEmpty();
}

void PriorityQueue::enqueue(int time) {
    if (isEmpty()) {
        s1.push(s1.top + 1, time);
        return;
    }
    if (s1.top == STACK_LENGTH) {
        cout << "Queue is full\n";
        return;
    }
    while (!s1.isEmpty()) {
        if (s1.peakTime() > time) {
            s2.push(s1.peakNumber(), s1.peakTime());
            s1.pop();
            if (s1.isEmpty()) {
                s2.push(s2.top + 1, time);
            }
        } else {
            s2.push(s1.top + s2.top + 1, time);
            break;
        }
    }
    while (!s2.isEmpty()) {
        s1.push(s2.peakNumber(), s2.peakTime());
        s2.pop();
    }
}

void PriorityQueue::dequeue() {
    if (isEmpty()) {
        cout << "Queue is empty.";
        return;
    }
    if (s2.isEmpty()) {
        while (!s1.isEmpty()) {
            s2.push(s1.peakNumber(), s1.peakTime());
            s1.pop();
        }
    }
    s2.pop();
}

double PriorityQueue::averageProcessingTime() {

    double totalTime = 0;
    while (!s1.isEmpty()) {
        totalTime += s1.peakTime();
        s2.push(s1.peakNumber(), s1.peakTime());
        s1.pop();
    }

    return totalTime / s2.top;
}


void PriorityQueue::getListOfWaitingMore() {
    s2.top = STACK_LENGTH;
    cout << "\n<======FIFO Kuyruguna Gore Fazla Bekleyenler======>\n";
    bool isWork = false;
    for (int i = 1; !s2.isEmpty(); ++i) {
        if (s2.peakNumber() < i) {
            cout << s2.peakNumber() << ". Kisi| " << "Islem suresi: " << s2.peakTime() << "\n";
            isWork = true;
        }
        dequeue();
    }
    if (!isWork) {
        cout << "Fazla bekleyen kimse yok.\n";
    }
}

void PriorityQueue::getListOfQueue() {
    if (isEmpty()) {
        cout << "Queue is empty.";
        return;
    }
    double averageTime = averageProcessingTime();
    int standbyTime = 0;
    while (!s2.isEmpty()) {
        standbyTime += s2.peakTime();
        cout << s2.peakNumber() << ". Kisi| " << "Islem suresi: " << s2.peakTime() << " |Bekleme suresi: "
             << standbyTime << "\n";
        dequeue();
    }
    cout << "Ortalama islem suresi: " << averageTime << endl;
    getListOfWaitingMore();
}

void startProgram() {
    int processTime[] = {248, 122, 274, 49, 74, 201, 236, 226, 85, 143, 299, 66, 211};
    Queue *queue = new Queue();
    PriorityQueue priorityQueue;
    for (int randomTime: processTime) {
        queue->enqueue(randomTime);
        priorityQueue.enqueue(randomTime);
    }
    cout << "<==================FIFO Kuyrugu==================>\n";
    queue->getListOfQueue();
    cout << "\n\n<=================Oncelik Kuyrugu=================>\n";
    priorityQueue.getListOfQueue();

}

int main() {
    startProgram();

    return 0;
}






