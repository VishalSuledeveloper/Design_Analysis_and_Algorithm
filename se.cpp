#include <bits/stdc++.h>
#include <chrono>

using namespace std;
using namespace std::chrono;

int linearSearch(int arr[], int n, int find) {
    for (int i = 0 ; i < n ; i++) {
        if (arr[i] == find) {
            return i;
        }
    }
    return -1;
}

int binarySearch(int arr[],int left, int right,int find) {
    if (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == find) {
            return mid;
        }
        if (arr[mid] > find) {
            return binarySearch(arr, left, mid - 1, find);
        }
        return binarySearch(arr, mid + 1, right, find);
    }
    return -1;
}

int main() {
    int  n;
    cout << "Enter total number of Elements: ";
    cin >> n;
    int arr[n];
    int i = 0;
    while(i<n) {
        arr[i] = rand() % 100000000 + 10000;
        i++;
    }
    sort(arr,arr+n);
    cout << arr[0] << endl << arr[n-1] << endl;
    int find, flag;
    cout << "Enter the number to find: ";
    cin >> find;
    
    int ch;
    cout << "1:Linear Search\n2:Binary Search\nEnter your choice: ";
    cin >> ch;


    auto start = high_resolution_clock::now();
    switch(ch) {
        case 1:
            flag = linearSearch(arr,n,find);break;
        case 2:
            flag = binarySearch(arr,0,n-1,find);
            break;
        default:
            cout << "Invalid choice" << endl;
    }
    auto stop = high_resolution_clock::now();
    if (flag == -1) {
        cout << "number not found" << endl;
    }
    else {
        cout << "number found at index: " << flag << endl;
    }
    auto duration = duration_cast<nanoseconds>(stop -start);
    cout << "time taken: " << duration.count() << " nanoseconds" << endl;

    return 0;
}