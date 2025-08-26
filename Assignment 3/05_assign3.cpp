#include <iostream>
#include <stack>
using namespace std;

int main() {
    string expr;
    cout << "Enter postfix expression (single digits, no spaces): ";
    cin >> expr;

    stack<int> s;

    for (char ch : expr) {
        if (ch >= '0' && ch <= '9') {
            s.push(ch - '0');  // push operand
        } else {
            int b = s.top(); s.pop();
            int a = s.top(); s.pop();

            if (ch == '+') s.push(a + b);
            else if (ch == '-') s.push(a - b);
            else if (ch == '*') s.push(a * b);
            else if (ch == '/') s.push(a / b);
        }
    }

    cout << "Result: " << s.top() << endl;
    return 0;
}
