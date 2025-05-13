#include <iostream>
#include <stack>
#include <algorithm>
#include <string>

using namespace std;

// Function to check if the character is an operator
bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

// Function to return precedence of operators
int precedence(char c) {
    if (c == '+' || c == '-') return 1;
    if (c == '*' || c == '/') return 2;
    if (c == '^') return 3;
    return 0;
}

// Function to convert infix to postfix
string infixToPostfix(string infix) {
    stack<char> s;
    string postfix = "";
    for (char c : infix) {
        if (isalnum(c)) {
            postfix += c;
        } else if (c == '(') {
            s.push(c);
        } else if (c == ')') {
            while (!s.empty() && s.top() != '(') {
                postfix += s.top();
                s.pop();
            }
            s.pop();
        } else if (isOperator(c)) {
            while (!s.empty() && precedence(s.top()) >= precedence(c)) {
                postfix += s.top();
                s.pop();
            }
            s.push(c);
        }
    }
    
    while (!s.empty()) {
        postfix += s.top();
        s.pop();
    }
    
    return postfix;
}

// Function to convert infix to prefix
string infixToPrefix(string infix) {
    // Step 1: Reverse the infix expression
    reverse(infix.begin(), infix.end());
    
    // Step 2: Change '(' to ')' and vice versa
    for (int i = 0; i < infix.length(); i++) {
        if (infix[i] == '(') {
            infix[i] = ')';
        } else if (infix[i] == ')') {
            infix[i] = '(';
        }
    }
    
    // Step 3: Get the postfix expression of the reversed string
    string postfix = infixToPostfix(infix);
    
    // Step 4: Reverse the postfix expression to get prefix
    reverse(postfix.begin(), postfix.end());
    
    return postfix;
}

int main() {
    string infix;
    
    // Input the infix expression
    cout << "Enter infix expression: ";
    cin >> infix;
    
    // Convert to prefix expression
    string prefix = infixToPrefix(infix);
    
    // Output the result
    cout << "Prefix expression: " << prefix << endl;

    return 0;
}
