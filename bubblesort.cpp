#include <iostream>
#include <vector>  
using namespace std;


void print(vector<int>& arr){
    for(int i = 0; i < arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout << "\n";
}

void bbsort(vector<int>& arr){
    for(int i = 0;i<arr.size()-1;i++){
        for(int j = 0;j<arr.size()-1-i;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }
}

int main() {
    vector<int> arr;
    arr.push_back(3);
    arr.push_back(7);
    arr.push_back(2);
    arr.push_back(5);
    arr.push_back(8);
    arr.push_back(1);
    int n = arr.size();  // .size() gives number of elements
    // cout << n;
    // cout<<"\n";
    cout<<"Before sorting : ";
    print(arr);

    bbsort(arr);

    cout<<"After sorting : ";
    print(arr);
}
