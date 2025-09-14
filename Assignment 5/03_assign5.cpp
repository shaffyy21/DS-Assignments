#include <iostream>
using namespace std;

struct Node {
    int val;
    Node* next;
};

Node* createNode(int v) {
    Node* n = new Node();
    n->val = v;
    n->next = nullptr;
    return n;
}

void insertEnd(Node*& head, int v) {
    Node* n = createNode(v);
    if (head == nullptr) {
        head = n;
        return;
    }
    Node* temp = head;
    while (temp->next != nullptr)
        temp = temp->next;
    temp->next = n;
}

int findMiddle(Node* head) {
    if (head == nullptr) return -1; // empty list
    Node* slow = head;
    Node* fast = head;
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow->val;
}

void display(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->val;
        if (temp->next != nullptr) cout << "->";
        temp = temp->next;
    }
    cout << "\n";
}

int main() {
    Node* head = nullptr;
    int n, v;

    cout << "Enter number of elements: ";
    cin >> n;
    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> v;
        insertEnd(head, v);
    }

    cout << "List: ";
    display(head);

    int mid = findMiddle(head);
    if (mid == -1)
        cout << "List is empty\n";
    else
        cout << "Middle element is: " << mid << "\n";

    return 0;
}
