#include<bits/stdc++.h>
using namespace std;
int main()
{
    int mat[4][5] = {{0,0,3,0,4},{0,0,5,7,0},{0,0,0,0,0},{0,2,6,0,0}};
    int sz = 0;
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<5;j++)
        {
            if(mat[i][j]!=0)sz++;
        }
    }
    int mat1[3][sz];

    int k = 0;
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<5;j++)
        {
            if(mat[i][j]!=0)
            {
                mat1[0][k] = i;
                mat1[1][k] = j;
                mat1[2][k] = mat[i][j];
                k++;
            }

        }
    }
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<sz;j++)
        {
            cout<<mat1[i][j]<<" ";
        }
        cout<<endl;
    }

}
