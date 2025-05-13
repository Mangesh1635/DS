#include <iostream>
using namespace std;

class Stack {
    int arr[10];
    int topidx;

public:
    Stack() {
        topidx = -1;
    }

    void push(int val) {
        if (full()) {
            cout << "Stack is Full!\n";
            return;
        }
        topidx++;
        arr[topidx] = val;
    }

    int pop() {
        if (empty()) {
            cout << "Stack is Empty!\n";
            return -1;
        }
        int top = arr[topidx];
        topidx--;
        return top;
    }

    int peek() {
        if (empty()) {
            cout << "Stack is Empty!\n";
            return -1;
        }
        return arr[topidx];
    }

    bool empty() {
        return topidx == -1;
    }

    bool full() {
        return topidx == 9;
    }

    void print() {
        for (int i = topidx; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
};

int main() {
    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);

    s.print(); // Expected: 40 30 20 10

    s.pop();

    s.print(); // Expected: 30 20 10

    cout << "Top : " << s.peek() << "\n";

    if (s.empty()) cout << "Stack is Empty!\n";
    else cout << "Stack is Not Empty!\n";

    if (s.full()) cout << "Stack is Full!\n";
    else cout << "Stack is Not full!\n";

    return 0;
}
