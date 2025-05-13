#include <iostream>
#include <vector>
using namespace std;

int fibonacciSearch(const vector<int>& arr, int target) {
    int n = arr.size();
    int fibMMm2 = 0, fibMMm1 = 1, fibM = fibMMm1 + fibMMm2;
    while (fibM < n) {
        fibMMm2 = fibMMm1;
        fibMMm1 = fibM;
        fibM = fibMMm1 + fibMMm2;
    }

    int offset = -1;
    while (fibM > 1) {
        int i = min(offset + fibMMm2, n - 1);
        if (arr[i] == target) return i;
        if (arr[i] < target) {
            fibM = fibMMm1;
            fibMMm1 = fibMMm2;
            fibMMm2 = fibM - fibMMm1;
            offset = i;
        } else {
            fibM = fibMMm2;
            fibMMm2 = fibMMm1 - fibMMm2;
            fibMMm1 = fibM - fibMMm2;
        }
    }
    if (fibMMm1 && arr[offset + 1] == target) return offset + 1;
    return -1;
}

int main() {
    vector<int> arr ;

    arr.push_back(10);
    arr.push_back(22);
    arr.push_back(35);
    arr.push_back(40);
    arr.push_back(45);
    arr.push_back(50);
    arr.push_back(80);

    cout<<"Enter Element : ";
    int ele;
    cin>>ele;

    int result = fibonacciSearch(arr, ele);
    cout << (result != -1 ? "Element found at index " + to_string(result) : "Element not found") << endl;
    return 0;
}
