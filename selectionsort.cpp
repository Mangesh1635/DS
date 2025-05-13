#include<stdio.h>
#include<iostream>
#include<vector>
using namespace std;

void print(vector<int> arr){
    int n = arr.size();
    for(int i = 0 ; i < n ; i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
}

void ssort(vector<int> &arr){
    int n = arr.size();
    for(int i = 0 ; i < n-1 ; i++){
        int minidx = i;
        for(int j = i+1; j<n;j++){
            if(arr[j]<arr[minidx]) {
                minidx = j;
            }
        } 
        if(minidx!=i) swap(arr[i],arr[minidx]);
    }
}


int main(){
    // 372581

    vector<int> arr;
    arr.push_back(3);
    arr.push_back(7);
    arr.push_back(2);
    arr.push_back(5);
    arr.push_back(8);
    arr.push_back(1);

    cout<<"Before Sorting : ";
    print(arr);
    int n = arr.size();
    
        ssort(arr);

    cout<<"After Sorting : ";
    print(arr);
}