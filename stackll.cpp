#include<stdio.h>
#include<iostream>
#include<list>
using namespace std;

class Stack{
    list<int> ll;
    public:
    void push(int val){
        ll.push_front(val);
    }
    void pop(){
        if(empty()){
            cout<<"Stack is Empty !\n";
            return;
        }
        ll.pop_front();
    }
    int peek(){
        if(empty()){
            cout<<"Stack is Empty !\n";
            return -1;
        }
        return ll.front();
    }
    bool empty(){
        if(ll.size() == 0) return true;
        else return false;
    }
    void print(){
        for(int val:ll){
            cout<<val<<" ";
        }
        cout<<"\n";
    }
};

int main(){
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);

    cout<<s.peek()<<"\n";

    s.print();

    s.pop();

    s.print();
}