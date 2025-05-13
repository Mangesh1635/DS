#include <iostream>
#include <stack>
#include <queue>
using namespace std;

void reverseStack(stack<int> &st) {
    queue<int> q;

    while (!st.empty()) {
        q.push(st.top());
        st.pop();
    }

    
    while (!q.empty()) {
        st.push(q.front());
        q.pop();
    }
}

void printStack(stack<int> st) {
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
}

int main() {
    stack<int> st;

    
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);

    cout << "Original Stack (top to bottom): ";
    printStack(st);

    
    reverseStack(st);

    cout << "Reversed Stack (top to bottom): ";
    printStack(st);

    return 0;
}
