#include <iostream>
#include <queue>
using namespace std;

int main() {
    string input;
    cout << "Enter characters (like: a a b c): ";
    getline(cin, input);

    int freq[26] = {0};  // To count frequency of 'a' to 'z'
    queue<char> q;

    cout << "First non-repeating characters: ";

    for (int i = 0; i < input.length(); i++) {
        char ch = input[i];

        if (ch == ' ') {
            continue; // Skip spaces
        }

        freq[ch - 'a']++;   // Increase count
        q.push(ch);         // Add to queue

        // Remove characters from front that are repeating
        while (!q.empty() && freq[q.front() - 'a'] > 1) {
            q.pop();
        }

        // Print result
        if (q.empty()) {
            cout << "-1 ";
        } else {
            cout << q.front() << " ";
        }
    }

    cout << endl;
    return 0;
}
