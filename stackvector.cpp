#include<stdio.h>
#include<iostream>
#include<vector>
using namespace std;

class Stack{
    vector<int> v;
    public:

    void push(int val){
        v.push_back(val);
    }

    void pop(){
        v.pop_back();
    }

    int peek(){
        return v[v.size()-1];
    }

    bool empty(){
        if(v.size() == 0) return true;
        else return false;
    }

    void print(){
        for(int i = v.size()-1;i>=0;i--){
            cout<<v[i]<<" ";
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
    s.print();

    s.pop();
    s.print();

    cout<<"Top : "<<s.peek();

    return 0;
}
