#include <iostream>
using namespace std;

int arr[100];
int n;

void create() {
    cout << "Enter size of array: ";
    cin >> n;
    cout << "Enter values of aaray: "<<endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
}

void display() {
    cout << "Array values are: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] <<endl;
    }
}

void removeDuplicates() {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n;j++) {
            if (arr[i] == arr[j]) {
                // Shift elements left to remove duplicate
                for (int k = j; k < n - 1; k++) {
                    arr[k] = arr[k + 1];
                }
                n--; // reduce size
                }
            }
        }
    }


void after_removing() {
    cout << "Array after removing duplicates: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << endl;
    cout << endl;
}

int main() {
    create();
    display();
    removeDuplicates();
    after_removing();
   

    return 0;
}
