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

int countOccurrences(Node* head, int key) {
    int count = 0;
    Node* curr = head;
    while (curr != nullptr) {
        if (curr->val == key)
            count++;
        curr = curr->next;
    }
    return count;
}

void deleteOccurrences(Node*& head, int key) {
    while (head != nullptr && head->val == key) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    Node* curr = head;
    while (curr != nullptr && curr->next != nullptr) {
        if (curr->next->val == key) {
            Node* temp = curr->next;
            curr->next = temp->next;
            delete temp;
        } else {
            curr = curr->next;
        }
    }
}

void display(Node* head) {
    if (head == nullptr) {
        cout << "List empty\n";
        return;
    }
    Node* curr = head;
    while (curr != nullptr) {
        cout << curr->val;
        if (curr->next != nullptr) cout << "->";
        curr = curr->next;
    }
    cout << "\n";
}

int main() {
    Node* head = nullptr;
    int n, v, key;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> v;
        insertEnd(head, v);
    }

    cout << "Original list: ";
    display(head);

    cout << "Enter key to count and delete: ";
    cin >> key;

    int c = countOccurrences(head, key);
    cout << "Occurrences of " << key << ": " << c << "\n";

    deleteOccurrences(head, key);

    cout << "List after deletion: ";
    display(head);

    return 0;
}
