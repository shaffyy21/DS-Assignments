#include <iostream>
using namespace std;

int arr[100];
int n ;

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

void insert() {
    int pos, val;
    cout << "Enter position to insert: ";
    cin >> pos;
    cout << "Enter value to insert: ";
    cin >> val;
    for (int i = n; i >= pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos - 1] = val;
    n++;
    cout << "Element inserted"<<endl;
}

void delete_element(){
    int pos;
    cout << "Enter position to delete: ";
    cin >> pos;
    
    for (int i = pos - 1; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    n--;
    cout << "Element deleted: ";
}

void linear_search() {
    int key;
    cout << "Enter element to search: ";
    cin >> key;
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            cout << "Element found at position " << i + 1 << endl;
            return;
        }
     }
    cout << "Element not found in array"<<endl;
}

int main() {
    int choice;
        cout << "\n—— MENU ——\n";
        cout << "1. CREATE" <<endl;
        cout << "2. DISPLAY" <<endl;
        cout << "3. INSERT" <<endl;
        cout << "4. DELETE" <<endl;
        cout << "5. LINEAR SEARCH" <<endl;
        cout << "6. EXIT" <<endl;
        cout << "Enter your choice: "<<endl;
        cin >> choice;

        switch (choice) {
            case 1: 
            create(); break;
            case 2:
            create();
             display(); break;
            case 3: 
            create();
            display();
            insert();
            display(); break;
            case 4:
            create();
            display(); 
            delete_element();
            display(); break;
            case 5: 
            create();
            display();
            linear_search(); break;
            case 6: cout << "Exiting program"; break;
            default: 
            cout << "Invalid choice! Try again";
        }
    

    return 0;
}

