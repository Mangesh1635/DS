 #include <iostream>
 #include <stack>
 #include <string>
 using namespace std;
 

 bool isOperand(char c) {
  return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
 }

 int main() {
  string postfix;
  cout << "Enter expression: ";
  getline(cin, postfix);

stack<string> st;
 

  for (char c : postfix) {
  if (isOperand(c)) {
  st.push(string(1, c)); 
  } else {
  string op1 = st.top();
  st.pop();
  string op2 = st.top();
  st.pop();
  st.push(  op2 + c + op1 );
  }
  }


  cout << "Infix expression: " << st.top();
 

  return 0;
 }
