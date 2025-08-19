#include <iostream>
using namespace std;

int arr[100];
int n;

void reverseArray() {
    cout << "Enter size of array: ";
    cin >> n;
    cout << "Enter values of aaray: "<<endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << "Original Array: ";
    for (int i = 0; i < n; i++) 
    cout << arr[i] << endl;
    // Reverse logic
    for (int i = 0; i < n / 2; i++) {
        int temp = arr[i];
        arr[i] = arr[n -i-1];
        arr[n -i- 1] = temp;
    }

    cout << "Reversed Array: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;

}
int main()
{
    reverseArray();
}