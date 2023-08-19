/**  Warshal Algorithm**/


#include<bits/stdc++.h>
using namespace std;
#define INF 999999
 ///  0  1 -2 INF 4 0 3 INF INF INF 0 2 5 INF INF 0

int main()
{
    int n;
    cout<<"Enter row and col number = ";
    cin>>n;
    int mat[n][n] = {{0 ,1, -2 ,INF},{ 4 ,0 ,3, INF}, {INF ,INF, 0 ,2 },{5, INF, INF, 0 }};
    cout<<"Enter node number = ";
    int m;
    cin>>m;

   

    for(int k=0;k<m;k++)
    {
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<m;j++)
            {
              if(mat[i][j]>(mat[i][k]+mat[k][j]))
              {
                  mat[i][j] = mat[i][k]+mat[k][j];
              }
            }
        }
    }
    
    
     for(int i=0;i<m;i++)
    {
        for(int j=0;j<m;j++)
        {
           if(mat[i][j]==INF)
           {
               cout<<"INF"<<" ";
           }
           else
            {
             cout<<mat[i][j]<<" ";
           }
        }
        cout<<endl;
    }
}
