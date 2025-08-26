#include <iostream>
#define SIZE 5

using namespace std;

int stack[SIZE];
int top = -1;

bool isEmpty() {
    return top == -1;
}

bool isFull() {
    return top == SIZE - 1;
}

void push(int value) {
    if (isFull()) {
        cout << endl << "Stack Overflow! Cannot push " << value << endl;
    } else {
        stack[++top] = value;
        cout << endl << value << " pushed into stack" << endl;
    }
}

void pop() {
    if (isEmpty()) {
        cout << endl << "Stack Underflow! Nothing to pop" << endl;
    } else {
        cout << endl << stack[top--] << " popped from stack" << endl;
    }
}

void peek() {
    if (isEmpty()) {
        cout << endl << "Stack is empty, nothing to peek" << endl;
    } else {
        cout << endl << "Top element is: " << stack[top] << endl;
    }
}

void display() {
    if (isEmpty()) {
        cout << endl << "Stack is empty" << endl;
    } else {
        cout << endl << "Stack elements: ";
        for (int i = 0; i <= top; i++) {
            cout << stack[i] << " ";
        }
        cout << endl;
    }
}

int main() {
    int choice, value;

    do {
        cout << endl << "---- Stack Menu ----" << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. isEmpty" << endl;
        cout << "4. isFull" << endl;
        cout << "5. Display" << endl;
        cout << "6. Peek" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> value;
                push(value);
                break;
            case 2:
                pop();
                break;
            case 3:
                cout << (isEmpty());
                break;
            case 4:
                cout << (isFull() );
                break;
            case 5:
                display();
                break;
            case 6:
                peek();
                break;
            case 7:
                cout << endl << "Exiting..." << endl;
                break;
            default:
                cout << endl << "Invalid choice! Try again." << endl;
        }
    } while (choice != 7);

    return 0;
}
