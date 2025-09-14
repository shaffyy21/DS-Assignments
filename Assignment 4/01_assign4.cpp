#include <iostream>
using namespace std;

#define SIZE 5  // Max size of the queue

class Queue {
private:
    int items[SIZE];
    int front, rear;

public:
    Queue() {
        front = -1;
        rear = -1;
    }

    bool isFull() {
        return rear == SIZE - 1;
    }

    bool isEmpty() {
        return front == -1 || front > rear;
    }

    void enqueue(int element) {
        if (isFull()) {
            cout << "Queue is full. Cannot enqueue.\n";
            return;
        }
        if (isEmpty()) {
            front = 0;
        }
        rear++;
        items[rear] = element;
        cout << "Enqueued: " << element << endl;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot dequeue.\n";
            return;
        }
        cout << "Dequeued: " << items[front] << endl;
        front++;
    }

    void peek() {
        if (isEmpty()) {
            cout << "Queue is empty.\n";
            return;
        }
        cout << "Front element: " << items[front] << endl;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty.\n";
            return;
        }
        cout << "Queue elements: ";
        for (int i = front; i <= rear; i++) {
            cout << items[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Queue q;
    int choice, value;

    do {
        cout << "\n----- Queue Menu -----\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Peek\n";
        cout << "4. Display\n";
        cout << "5. isEmpty\n";
        cout << "6. isFull\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to enqueue: ";
            cin >> value;
            q.enqueue(value);
            break;
        case 2:
            q.dequeue();
            break;
        case 3:
            q.peek();
            break;
        case 4:
            q.display();
            break;
        case 5:
            if (q.isEmpty())
                cout << "Queue is empty.\n";
            else
                cout << "Queue is not empty.\n";
            break;
        case 6:
            if (q.isFull())
                cout << "Queue is full.\n";
            else
                cout << "Queue is not full.\n";
            break;
        case 0:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 0);

    return 0;
}
