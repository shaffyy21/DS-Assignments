#include <iostream>
using namespace std;

int a[100][100],b[100][100],result[100][100];
int r1,c1,r2,c2;

void matrix_multiply()
{
    cout<<"enter rows and columns of first matrix: "<<endl;
    cin >> r1 >> c1;
    cout << "Enter rows and columns of second matrix: "<<endl;
    cin >> r2 >> c2;

    cout << "Enter elements of Matrix A: "<<endl;
    for (int i = 0; i < r1; i++)
        for (int j = 0; j < c1; j++)
            cin >> a[i][j];

    cout << " Matrix A is: "<<endl;
    for (int i = 0; i < r1; i++){
        for (int j = 0; j < c1; j++)
            cout<< a[i][j]<<" ";
        cout << endl;}



        cout << "Enter elements of Matrix B: "<< endl;
        for (int i = 0; i < r2; i++)
            for (int j = 0; j < c2; j++)
                cin >> b[i][j];
        
        cout << "Matrix B is:"<< endl;
        for (int i = 0; i < r2; i++) {
            for (int j = 0; j < c2; j++) {
                cout << b[i][j] << " ";
            }
            cout << endl;
        }
        
             
 

    // Multiplication logic
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            for (int k = 0; k < c1; k++) {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    cout << "Resultant Matrix: "<<endl;
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    matrix_multiply();
}


