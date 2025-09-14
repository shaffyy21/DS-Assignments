#include <iostream>
using namespace std;

struct Node {
    int val;
    Node* next;
};

class LinkedList {
    Node* head;

    Node* createNode(int v) {
        Node* n = new Node();
        n->val = v;
        n->next = nullptr;
        return n;
    }

public:
    LinkedList() {
        head = nullptr;
    }

    void insertBegin(int v) {
        Node* n = createNode(v);
        n->next = head;
        head = n;
    }

    void insertEnd(int v) {
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

    void insertBeforeAfter(int v, int ref, bool before) {
        if (head == nullptr) {
            cout << "Empty list\n";
            return;
        }
        if (before) {
            if (head->val == ref) {
                insertBegin(v);
                return;
            }
            Node* prev = nullptr;
            Node* curr = head;
            while (curr != nullptr && curr->val != ref) {
                prev = curr;
                curr = curr->next;
            }
            if (curr == nullptr) {
                cout << "Value not found\n";
                return;
            }
            Node* n = createNode(v);
            prev->next = n;
            n->next = curr;
        } else {
            Node* curr = head;
            while (curr != nullptr && curr->val != ref) {
                curr = curr->next;
            }
            if (curr == nullptr) {
                cout << "Value not found\n";
                return;
            }
            Node* n = createNode(v);
            n->next = curr->next;
            curr->next = n;
        }
    }

    void deleteBegin() {
        if (head == nullptr) {
            cout << "Empty list\n";
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    void deleteEnd() {
        if (head == nullptr) {
            cout << "Empty list\n";
            return;
        }
        if (head->next == nullptr) {
            delete head;
            head = nullptr;
            return;
        }
        Node* temp = head;
        while (temp->next->next != nullptr)
            temp = temp->next;
        delete temp->next;
        temp->next = nullptr;
    }

    void deleteValue(int v) {
        if (head == nullptr) {
            cout << "Empty list\n";
            return;
        }
        if (head->val == v) {
            deleteBegin();
            return;
        }
        Node* prev = nullptr;
        Node* curr = head;
        while (curr != nullptr && curr->val != v) {
            prev = curr;
            curr = curr->next;
        }
        if (curr == nullptr) {
            cout << "Value not found\n";
            return;
        }
        prev->next = curr->next;
        delete curr;
    }

    void searchValue(int v) {
        Node* curr = head;
        int pos = 1;
        while (curr != nullptr) {
            if (curr->val == v) {
                cout << "Value found at position " << pos << "\n";
                return;
            }
            curr = curr->next;
            pos++;
        }
        cout << "Value not found\n";
    }

    void display() {
        if (head == nullptr) {
            cout << "List empty\n";
            return;
        }
        Node* curr = head;
        cout << "List: ";
        while (curr != nullptr) {
            cout << curr->val << " ";
            curr = curr->next;
        }
        cout << "\n";
    }
};

int main() {
    LinkedList list;
    int ch, v, ref;
    bool before;

    do {
        cout << "\nMenu:\n";
        cout << "1. Insert at beginning\n";
        cout << "2. Insert at end\n";
        cout << "3. Insert before/after\n";
        cout << "4. Delete from beginning\n";
        cout << "5. Delete from end\n";
        cout << "6. Delete specific value\n";
        cout << "7. Search value\n";
        cout << "8. Display list\n";
        cout << "0. Exit\n";
        cout << "Choice: ";
        cin >> ch;

        switch (ch) {
            case 1:
                cout << "Enter value: ";
                cin >> v;
                list.insertBegin(v);
                break;

            case 2:
                cout << "Enter value: ";
                cin >> v;
                list.insertEnd(v);
                break;

            case 3:
                cout << "Enter value to insert: ";
                cin >> v;
                cout << "Reference value: ";
                cin >> ref;
                cout << "Insert before(1) or after(0)? ";
                cin >> before;
                list.insertBeforeAfter(v, ref, before);
                break;

            case 4:
                list.deleteBegin();
                break;

            case 5:
                list.deleteEnd();
                break;

            case 6:
                cout << "Enter value to delete: ";
                cin >> v;
                list.deleteValue(v);
                break;

            case 7:
                cout << "Enter value to search: ";
                cin >> v;
                list.searchValue(v);
                break;

            case 8:
                list.display();
                break;

            case 0:
                cout << "Bye!\n";
                break;

            default:
                cout << "Invalid choice\n";
        }
    } while (ch != 0);

    return 0;
}
