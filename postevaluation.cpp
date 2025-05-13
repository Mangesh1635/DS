 #include <iostream>
 #include <stack>
 #include <string>
 using namespace std;
 
 bool isOperand(const string& token) {
  return (token.length() == 1 && isalnum(token[0]));
 }

 int evaluatePostfix(const string& postfix) {
  stack<int> s;
  string token;
 

  for (size_t i = 0; i < postfix.length(); ++i) {
  if (postfix[i] == ' ') continue;
 

  if (isalnum(postfix[i])) {
  token = postfix[i];
  s.push(stoi(token));
  }
  else {
  int operand2 = s.top();
  s.pop();
  int operand1 = s.top();
  s.pop();
 

  switch (postfix[i]) {
  case '+': s.push(operand1 + operand2); break;
  case '-': s.push(operand1 - operand2); break;
  case '*': s.push(operand1 * operand2); break;
  case '/': s.push(operand1 / operand2); break;
  default:
  cerr << "Unsupported operator: " << postfix[i] << endl;
  return 0;
  }
  }
  }
 

  return s.top();
 }
 

 int main() {
  string postfix_expression;
  cout << "Enter postfix expression: ";
  getline(cin, postfix_expression);
 

  int result = evaluatePostfix(postfix_expression);
  cout << "Result: " << result << endl;
 

  return 0;
 }
