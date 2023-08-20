#include<bits/stdc++.h>
using namespace std;
#define v 4
int mat[v][v][v],mat1[v][v][v],mat2[v][v][v];
/// 0 1 0 0 0 0 1 1  0 0 0 0 1 0 1 1
int main()
{
    for(int i=0;i<v;i++)
    {

        for(int j=0;j<v;j++)
        {
            cin>>mat[0][i][j];
        }
    }

    for(int m=1;m<v;m++)
    {
         for(int i=0;i<v;i++)
        {

            for(int j=0;j<v;j++)
            {
                for(int k=0;k<v;k++)
                {
                    mat1[m][i][j] += mat[m-1][i][k]*mat[0][k][j];
                }
                mat[m][i][j] = mat1[m][i][j];
            }
        }
    }
   for(int i=0;i<v;i++)
   {
       cout<<"mat^"<<i<<endl;
       for(int j=0;j<v;j++)
       {
           for(int k=0;k<v;k++)
           {
               cout<<mat[i][j][k]<<" ";
           }
           cout<<endl;
       }
       cout<<endl<<endl;
   }

   ///calculate sum of 4 matrix and print
   for(int i=0;i<v;i++)
   {
       for(int j=0;j<v;j++)
       {
           for(int m=0;m<v;m++)
           {
               mat2[0][i][j]+=mat[m][i][j];
           }

       }
   }
   cout<<"Final matrix : "<<endl;
   for(int i=0;i<v;i++)
   {
       for(int j=0;j<v;j++)
       {
           cout<<mat2[0][i][j]<<" ";
       }
       cout<<endl;
   }

   return 0;

}
