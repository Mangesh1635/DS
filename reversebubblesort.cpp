#include<stdio.h>
#include<iostream>
#include<vector>
using namespace std;

void print(vector<int> &arr){
    int n = arr.size();
    for(int i = 0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
}

void rbbsort(vector<int> &arr){
    int n = arr.size();
    for(int i = 0;i<n-1;i++){
        for(int j = 0; j<n-1-i;j++){
            if(arr[j]<arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }
}

int main(){
// 372581
    vector<int> arr ;
    arr.push_back(3);
    arr.push_back(7);
    arr.push_back(2);
    arr.push_back(5);
    arr.push_back(8);
    arr.push_back(1);

    cout<<"Before sorting : ";
    print(arr);

    rbbsort(arr);

    cout<<"After sorting : ";
    print(arr);

    return 0;
}