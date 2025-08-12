#include <iostream>
using namespace std;

void transposeMatrix() {
    int a[100][100], trans[100][100];
    int r, c;

    cout << "Enter rows and columns of the matrix: ";
    cin >> r>> c;

    cout << "Enter elements of the matrix:\n";
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            cin >> a[i][j];

    cout<< "matrix a is: "<<endl;
    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++)
            cout<< a[i][j]<< " ";
        cout<<endl;}

    // Transpose 
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            trans[j][i] = a[i][j];

    cout << "Transpose of the matrix:\n";
    for (int i = 0; i < c; i++) {
        for (int j = 0; j < r; j++) {
            cout << trans[i][j] << " ";
        }
        cout << endl;
    }
}
int main()
{
    transposeMatrix();
}
