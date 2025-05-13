#include<stdio.h>
#include<iostream>
#include<vector>
using namespace std;

void print(vector<int> arr){
    for(int i = 0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
}

void isort(vector<int> &arr){
    int n = arr.size();
    for(int i=1;i<n;i++){
        for(int  j = i ; j>=1;j--){
            if(arr[j]<arr[j-1]) swap(arr[j],arr[j-1]);
        }
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

    cout<<"Befor sorting : ";
    print(arr);

    isort(arr)
;
    cout<<"After sorting : ";
    print(arr);


}