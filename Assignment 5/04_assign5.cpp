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

void display(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->val;
        if (temp->next != nullptr) cout << "->";
        temp = temp->next;
    }
    cout << "->NULL\n";
}

Node* reverseList(Node* head) {
    Node* prev = nullptr;
    Node* curr = head;
    Node* next = nullptr;

    while (curr != nullptr) {
        next = curr->next;  // save next node
        curr->next = prev;  // reverse current node's pointer
        prev = curr;        // move prev up
        curr = next;        // move curr up
    }
    return prev; // new head
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

    cout << "Original list: ";
    display(head);

    head = reverseList(head);

    cout << "Reversed list: ";
    display(head);

    return 0;
}
