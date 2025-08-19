#include <iostream>
using namespace std;

// (a) Diagonal Matrix
void diagonalMatrix() {
    int n;
    cout << "\n(a) Diagonal Matrix\nEnter size of matrix: ";
    cin >> n;
    int A[n];

    cout << "Enter diagonal elements:\n";
    for (int i = 0; i < n; i++) {
        cout << "A[" << i + 1 << "," << i + 1 << "]: ";
        cin >> A[i];
    }

    cout << "Matrix:\n";
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j)
                cout << A[i - 1] << " ";
            else
                cout << "0 ";
        }
        cout << endl;
    }
}

// (b) Tri-diagonal Matrix
void triDiagonalMatrix() {
    int n;
    cout << "\n(b) Tri-diagonal Matrix\nEnter size of matrix: ";
    cin >> n;
    int size = 3 * n - 2;
    int A[size];

    cout << "Enter non-zero elements (lower, diagonal, upper):\n";
    for (int i = 0; i < size; i++) {
        cout << "A[" << i << "]: ";
        cin >> A[i];
    }

    cout << "Matrix:\n";
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i - j == 1)
                cout << A[i - 2] << " ";
            else if (i == j)
                cout << A[n - 1 + i - 1] << " ";
            else if (i - j == -1)
                cout << A[2 * n - 1 + i - 1] << " ";
            else
                cout << "0 ";
        }
        cout << endl;
    }
}

// (c) Lower Triangular Matrix
void lowerTriangularMatrix() {
    int n;
    cout << "\n(c) Lower Triangular Matrix\nEnter size of matrix: ";
    cin >> n;
    int size = n * (n + 1) / 2;
    int A[size];

    cout << "Enter lower triangular elements row-wise:\n";
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            int index = i * (i - 1) / 2 + (j - 1);
            cout << "A[" << i << "," << j << "]: ";
            cin >> A[index];
        }
    }

    cout << "Matrix:\n";
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i >= j)
                cout << A[i * (i - 1) / 2 + (j - 1)] << " ";
            else
                cout << "0 ";
        }
        cout << endl;
    }
}

// (d) Upper Triangular Matrix
void upperTriangularMatrix() {
    int n;
    cout << "\n(d) Upper Triangular Matrix\nEnter size of matrix: ";
    cin >> n;
    int size = n * (n + 1) / 2;
    int A[size];

    cout << "Enter upper triangular elements column-wise:\n";
    for (int j = 1; j <= n; j++) {
        for (int i = 1; i <= j; i++) {
            int index = j * (j - 1) / 2 + (i - 1);
            cout << "A[" << i << "," << j << "]: ";
            cin >> A[index];
        }
    }

    cout << "Matrix:\n";
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i <= j)
                cout << A[j * (j - 1) / 2 + (i - 1)] << " ";
            else
                cout << "0 ";
        }
        cout << endl;
    }
}

// (e) Symmetric Matrix
void symmetricMatrix() {
    int n;
    cout << "\n(e) Symmetric Matrix\nEnter size of matrix: ";
    cin >> n;
    int size = n * (n + 1) / 2;
    int A[size];

    cout << "Enter lower triangular elements (including diagonal):\n";
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            int index = i * (i - 1) / 2 + (j - 1);
            cout << "A[" << i << "," << j << "]: ";
            cin >> A[index];
        }
    }

    cout << "Matrix:\n";
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i >= j)
                cout << A[i * (i - 1) / 2 + (j - 1)] << " ";
            else
                cout << A[j * (j - 1) / 2 + (i - 1)] << " ";
        }
        cout << endl;
    }
}

int main() {
    diagonalMatrix();
    triDiagonalMatrix();
    lowerTriangularMatrix();
    upperTriangularMatrix();
    symmetricMatrix();

    return 0;
}
