#include <iostream>
using namespace std;

int main() {
    int n, count = 0;
    cout << "Enter size of array: ";
    cin >> n;
    int arr[n];
    cout << "Enter elements:\n";
    for(int i = 0; i < n; i++) 
    cin >> arr[i];

    for(int i = 0; i < n-1; i++) {
        for(int j = i+1; j < n; j++) {
            if(arr[i] > arr[j]) {
                count++;
            }
        }
    }

    cout << "Number of inversions: " << count << endl;
    return 0;
}
