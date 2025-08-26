#include <iostream>
using namespace std;

int main() {
    string expr;
    int count = 0;

    cout << "Enter expression: ";
    getline(cin, expr);

    for (int i = 0; i < expr.length(); i++) {
        if (expr[i] == '(') count++;
        else if (expr[i] == ')') count--;

        if (count < 0) {
            cout << "Not Balanced\n";
            return 0;
        }
    }

    if (count == 0)
        cout << "Balanced\n";
    else
        cout << "Not Balanced\n";

    return 0;
}
