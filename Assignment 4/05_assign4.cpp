#include <iostream>
#include <queue>
using namespace std;

class StackTwoQueues {
    queue<int> q1, q2;
public:
    void push(int x) {
        q2.push(x);
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1, q2);
    }
    void pop() {
        if (!q1.empty()) q1.pop();
    }
    int top() {
        if (!q1.empty()) return q1.front();
        return -1;
    }
    bool isEmpty() {
        return q1.empty();
    }
};

class StackOneQueue {
    queue<int> q;
public:
    void push(int x) {
        q.push(x);
        int n = q.size();
        for (int i = 1; i < n; i++) {
            q.push(q.front());
            q.pop();
        }
    }
    void pop() {
        if (!q.empty()) q.pop();
    }
    int top() {
        if (!q.empty()) return q.front();
        return -1;
    }
    bool isEmpty() {
        return q.empty();
    }
};

int main() {
    StackTwoQueues s2q;
    StackOneQueue s1q;
    int choice, method, value;

    do {
        cout << "\n1. Push\n2. Pop\n3. Top\n4. isEmpty\n0. Exit\nEnter choice: ";
        cin >> choice;

        if (choice == 0) break;

        cout << "Select method (1 = One Queue, 2 = Two Queues): ";
        cin >> method;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                if (method == 1) s1q.push(value);
                else s2q.push(value);
                break;
            case 2:
                if (method == 1) s1q.pop();
                else s2q.pop();
                break;
            case 3:
                if (method == 1) cout << "Top: " << s1q.top() << endl;
                else cout << "Top: " << s2q.top() << endl;
                break;
            case 4:
                if (method == 1) cout << (s1q.isEmpty() ? "Empty\n" : "Not empty\n");
                else cout << (s2q.isEmpty() ? "Empty\n" : "Not empty\n");
                break;
        }
    } while (choice != 0);

    return 0;
}
