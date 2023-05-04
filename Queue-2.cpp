#include "iostream"

using namespace std;
#define STACK_LENGTH 10

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
    return numberArr[top-1];
}

int Stack2::peakTime() {
    return timeArr[top-1];
}

struct Queue2 {
    Stack2 s1,s2;

    void enqueue();

    void dequeue();

    bool isEmpty();

    double averageProcessingTime();

    void getListOfQueue();

    void getListOfWaiter();


};

bool Queue2::isEmpty() {
    return s1.isEmpty()&&s2.isEmpty();
}

void Queue2::enqueue() {
    int time=rand()%271+30;
    if (isEmpty()){
        s1.push(s1.top + 1, time);
        return;
    }
    if (s1.top==STACK_LENGTH){
        cout<<"Queue is full\n";
        return;
    }
    while (!s1.isEmpty()){
        if (s1.peakTime() > time){
            s2.push(s1.peakNumber(), s1.peakTime());
            s1.pop();
            if (s1.isEmpty()){
                s2.push(s2.top+1,time);
            }
        } else{
            s2.push(s1.top+s2.top+1,time);
            break;
        }
    }
    while (!s2.isEmpty()){
        s1.push(s2.peakNumber(), s2.peakTime());
        s2.pop();
    }
}

void Queue2::dequeue() {
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

double Queue2::averageProcessingTime() {

    double totalTime = 0;
    while (!s1.isEmpty()) {
        totalTime += s1.peakTime();
        s2.push(s1.peakNumber(), s1.peakTime());
        s1.pop();
    }

    return totalTime / s2.top;
}
//ismini değiştir
void Queue2::getListOfWaiter() {
    s2.top=STACK_LENGTH;
    cout << "\n<<<==========FIFO Kuyruguna Gore Fazla Bekleyenler==========>>>\n";
    bool isWork= false;
    for (int i = 1; !s2.isEmpty(); ++i) {
        if (s2.peakNumber()<i){
            cout << s2.peakNumber() << ". Kisi| " << "Islem suresi: " << s2.peakTime()<<"\n";
            isWork= true;
        }
        dequeue();
    }
    if (!isWork){
        cout<<"Fazla bekleyen kimse yok.\n";
    }
}

void Queue2::getListOfQueue() {
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
    cout << "<<<==========Ortalama islem suresi: " << averageTime<<"==========>>>";
    getListOfWaiter();
}

void menu2() {
    cout << "<<<==========Kuyruk Uygulamasi-2==========>>>\n";
    cout << "Lutfen kuyrukdaki kisi sayisini belirleyiniz.\n";


}

int main() {
    Queue2 q ;
    int n;
    menu2();
    cin >> n;
    while (n!=0) {

        q.enqueue();
        n--;
    }
    q.getListOfQueue();



    return 0;
}
