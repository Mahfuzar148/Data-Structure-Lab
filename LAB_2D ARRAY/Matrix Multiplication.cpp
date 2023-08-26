#include<bits/stdc++.h>
using namespace std;

int main()
{
    int r1, c1, r2, c2;
    cout << "First Array: " << endl;
    cout << "Enter row number: ";
    cin >> r1;
    cout << "Enter column number: ";
    cin >> c1;

    cout << "Second Array: " << endl;
    cout << "Enter row number: ";
    cin >> r2;
    cout << "Enter column number: ";
    cin >> c2;

    while(c1!=r2)
    {
        if (c1 != r2) {
        cout << "Error! column of first matrix not equal to row of second." << endl;
        cout << "Enter row number: ";
        cin >> r1;
        cout << "Enter column number: ";
        cin >> c1;

        cout << "Second Array: " << endl;
        cout << "Enter row number: ";
        cin >> r2;
        cout << "Enter column number: ";
        cin >> c2;
        
    }
    }

    int A[r1][c1];
    int B[r2][c2];
    int C[r1][c2];
     for(int i = 0; i < r1; ++i)
        for(int j = 0; j < c2; ++j)
        {
            C[i][j]=0;
        }

    cout << "Enter elements of first array: " << endl;
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c1; j++) {
            cout<<"A["<<i<<"]"<<"["<<j<<"]"<<" = ";
            cin >> A[i][j];
        }
    }

    cout << "Enter elements of second array: " << endl;
    for (int i = 0; i < r2; i++) {
        for (int j = 0; j < c2; j++) {
             cout<<"B["<<i<<"]"<<"["<<j<<"]"<<" = ";
            cin >> B[i][j];
        }
    }

    // Matrix multiplication
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            for (int k = 0; k < c1; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    // Output the resulting matrix
    cout << "Resulting matrix: " << endl;
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            cout << C[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
