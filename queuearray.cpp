#include<stdio.h>
#include<iostream>
using namespace std;

class Queue{
    int arr[10];
    int front;
    int rare;
    int size;
    public:
    Queue(){
        front = rare = -1;
        size=0;
    }

    void push(int val){
        if(empty()){
            front++;
            rare++;
            arr[0] = val;
            size++;
        }
        else if(full()){
            cout<<"Queue is Full ! \n";
        }
        else{
            rare++;
            arr[rare] = val;
            size++;
        }
    }

    void pop(){
        if(empty()){
            cout<<"Queue is Empty ! \n";
        }
        else if(front==rare){
            front=-1;
            rare=-1;
            size--;
        }
        else{
            front++;
            size--;
        }
    }

    int Front(){
        if(empty()) return -1;
        else return arr[front];
    }

    bool empty(){
        if(size==0) return true;
        else return false;
    }

    bool full(){
        if(size==10) return true;
        else return false;
    }

    void print(){
        if(front<rare){
            for(int i=front;i<=rare;i++){
            cout<<arr[i]<<" ";
        }
        }
        else if(front>rare){
            for(int i=front;i<=9;i++){
            cout<<arr[i]<<" ";
        }
        for(int i=0;i<=rare;i++){
            cout<<arr[i]<<" ";
        }
        }
        cout<<"\n";
    }
};

int main(){
    Queue q;

    if(q.empty()) cout<<"Queue is empty ! \n";
    else cout<<"Queue is Not empty ! \n";
    
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);

    cout<<q.Front()<<"\n";

    q.print();

    q.pop();

    q.print();

    q.push(60);
    q.push(70);
    q.push(80);
    q.push(90);
    q.push(100);
    q.push(110);

    q.print();

    if(q.full()) cout<<"Queue is full !";
    else cout<<"Queue is Not full !";


    return 0;
}