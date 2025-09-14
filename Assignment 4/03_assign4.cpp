#include <iostream>
#include <queue>
using namespace std;

void interleaveQueue(queue<int>& q) {
    int n = q.size();

    if (n % 2 != 0) {
        cout << "Queue has an odd number of elements. Cannot interleave.\n";
        return;
    }

    int halfSize = n / 2;
    queue<int> firstHalf;

    // Step 1: Move first half into a separate queue
    for (int i = 0; i < halfSize; i++) {
        firstHalf.push(q.front());
        q.pop();
    }

    // Step 2: Interleave the two halves
    while (!firstHalf.empty()) {
        q.push(firstHalf.front()); // from first half
        firstHalf.pop();

        q.push(q.front());         // from second half
        q.pop();
    }
}

int main() {
    queue<int> q;
    int n, element;

    cout << "Enter even number of elements in the queue: ";
    cin >> n;

    if (n % 2 != 0) {
        cout << "Error: Number of elements must be even.\n";
        return 1;
    }

    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> element;
        q.push(element);
    }

    interleaveQueue(q);

    cout << "Interleaved queue: ";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;

    return 0;
}
