#include <iostream>
using namespace std;

#define SIZE 100

char stack[SIZE];
int top = -1;

void push(char ch) {
    if (top < SIZE - 1) {
        stack[++top] = ch;
    }
}

char pop() {
    if (top >= 0) {
        return stack[top--];
    }
    return '\0';
}

int main() {
    char str[SIZE];
    cout << "Enter a string: ";
    cin.getline(str, SIZE);

    for (int i = 0; str[i] != '\0'; i++) {
        push(str[i]);
    }

    cout << "Reversed string: ";
    while (top != -1) {
        cout << pop();
    }
    cout << endl;

    return 0;
}
