#include <iostream>
using namespace std;

int binarySearch(int arr[], int n, int num) {
    int beg = 0, end = n - 1;
    
    while (beg <= end) {
        int mid = (beg + end) / 2;
        
        if (arr[mid] == num)
            return mid;
        else if (arr[mid] < num)
            beg = mid + 1;
        else
            end = mid - 1;
    }
    return -1;
}

int main() {
    int n;
    cout << "Enter number of elements (sorted): ";
    cin >> n;
    
    int arr[n];
    cout << "Enter " << n << " sorted numbers: "<<endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    int num;
    cout << "Enter number to search for: ";
    cin >> num;
    
    int result = binarySearch(arr, n, num);
    
    if (result != -1)
        cout << "Element found at index: " << result << endl;
    else
        cout << "Element not found" << endl;
    
    return 0;
}


