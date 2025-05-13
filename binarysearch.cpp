#include <iostream>
#include <vector>
using namespace std;

int binarySearch(const vector<int>& arr, int target) {
    int left = 0, right = arr.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) return mid;
        else if (arr[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    return -1;  // Not found
}

int main() {
    vector<int> arr;
    arr.push_back(2);
    arr.push_back(3);
    arr.push_back(4);
    arr.push_back(10);
    arr.push_back(40);
    cout<<"Enter Element : ";
    int ele;
    cin>>ele;
    int result = binarySearch(arr, ele);
    cout << (result != -1 ? "Element found at index " + to_string(result) : "Element not found") << endl;
    return 0;
}
