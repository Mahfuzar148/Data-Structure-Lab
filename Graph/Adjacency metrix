#include<bits/stdc++.h>
using namespace std;

int main()
{
    int mat[4][4][4], mat1[4][4][4], mat2[4][4][4];

    // Input for mat[0] matrix
    for(int i=0; i<4; i++)
    {
        for(int j=0; j<4; j++)
        {
            cin >> mat[0][i][j];
        }
    }

    // Calculate mat1[m] matrices
    for(int m=1; m<4; m++)
    {
        for(int i=0; i<4; i++)
        {
            for(int j=0; j<4; j++)
            {
                mat1[m][i][j] = 0;
                for(int k=0; k<4; k++)
                {
                    mat1[m][i][j] += mat[m-1][i][k] * mat[0][k][j];
                }
                mat[m][i][j] =  mat1[m][i][j];
            }
        }
    }

    // Output mat[m] matrices
    for(int m=0; m<4; m++)
    {
        for(int i=0; i<4; i++)
        {
            for(int j=0; j<4; j++)
            {
                cout << mat[m][i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    // Calculate mat2[0] matrix
    for(int i=0; i<4; i++)
    {
        for(int j=0; j<4; j++)
        {
            int sum = 0;
            for(int m=0; m<4; m++)
            {
                sum += mat[m][i][j];
            }
            cout << sum << " ";
        }
        cout << endl;
    }

    return 0;
}

