#include<stdio.h>
#include<iostream>
using namespace std;

class Node{
    public:
            int data;
            Node* next;
            Node(int val){
                data = val;
                next = NULL;
            }
};

class Queue{
    Node* head;
    Node* tail;
    public:
    Queue(){
        head = tail = NULL;
    }

    void push(int val){
        Node* newnode = new Node(val);
        if(empty()){
            head = tail = newnode;
        }
        else{
            tail->next = newnode;
            tail = newnode;
        }
    }

    void pop(){
        if(empty()){
            cout<<"Queue is Empty !!\n";
        }
        else if(head==tail){
            head=NULL;
            tail=NULL;
        }
        else{
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    int front(){
        if(empty()){
            cout<<"Queue is Empty !!\n";
        }
        else{
            return head->data;
        }
    }

    bool empty(){
        if(head==NULL && tail==NULL) return true;
        else return false;
    }

    void print(){
        Node* temp = head;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<"\n";
    }
};
int main(){
    Queue q;

    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);

    q.print();

    q.pop();

    q.print();

    cout<<q.front()<<"\n";

    q.pop();q.pop();q.pop();q.pop();

    if(q.empty()) cout<<"Queue is Empty !";
    else cout<<"Queue is Not Empty !";
}