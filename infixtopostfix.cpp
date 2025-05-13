#include<stdio.h>
#include<iostream>
#include<string>
#include<stack>
using namespace std;

int precedence(char c){
    if(c=='^') return 3;
    else if(c=='*' || c=='/') return 2;
    else if(c=='+' || c=='-') return 1;
    else return -1;
 }

int main(){
    stack<char> st;
    cout<<"Enteer Expression : ";
    string exp;
    getline(cin,exp);
    string ans;
    for(char c:exp){
        if(isalnum(c)) ans+=c;
        else if(c=='(') st.push(c);
        else if(c==')'){
            while(!st.empty() && st.top()!='('){
                ans+=st.top();
                st.pop();
            }
            st.pop();
        }
        else{
            while (!st.empty() && precedence(c) <= precedence(st.top())) {
            ans += st.top();
            st.pop();
  }
        st.push(c);
        }
    }
    while (!st.empty()) {
    ans += st.top();
    st.pop();
  }

  cout << "Postfix expression: " << ans;

}