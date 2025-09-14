#include <iostream>
using namespace std;

#define SIZE 5  // Size of the circular queue

class CircularQueue {
private:
    int items[SIZE];
    int front, rear;

public:
    CircularQueue() {
        front = -1;
        rear = -1;
    }

    bool isFull() {
        return (front == (rear + 1) % SIZE);
    }

    bool isEmpty() {
        return (front == -1);
    }

    void enqueue(int element) {
        if (isFull()) {
            cout << "Queue is full. Cannot enqueue.\n";
            return;
        }
        if (isEmpty()) {
            front = 0;
        }
        rear = (rear + 1) % SIZE;
        items[rear] = element;
        cout << "Enqueued: " << element << endl;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot dequeue.\n";
            return;
        }

        cout << "Dequeued: " << items[front] << endl;

        if (front == rear) {
            // Only one element was present
            front = rear = -1;
        } else {
            front = (front + 1) % SIZE;
        }
    }

    void peek() {
        if (isEmpty()) {
            cout << "Queue is empty.\n";
        } else {
            cout << "Front element: " << items[front] << endl;
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty.\n";
            return;
        }

        cout << "Queue elements: ";
        int i = front;
        while (true) {
            cout << items[i] << " ";
            if (i == rear)
                break;
            i = (i + 1) % SIZE;
        }
        cout << endl;
    }
};

int main() {
    CircularQueue cq;
    int choice, value;

    do {
        cout << "\n----- Circular Queue Menu -----\n";
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
            cq.enqueue(value);
            break;
        case 2:
            cq.dequeue();
            break;
        case 3:
            cq.peek();
            break;
        case 4:
            cq.display();
            break;
        case 5:
            cout << (cq.isEmpty() ? "Queue is empty.\n" : "Queue is not empty.\n");
            break;
        case 6:
            cout << (cq.isFull() ? "Queue is full.\n" : "Queue is not full.\n");
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
