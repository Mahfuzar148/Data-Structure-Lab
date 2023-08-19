#include<bits/stdc++.h>
using namespace std;
int main(){             
    int m,i,j,k;
    //m is Number of Vertices or Point
    //i,j,k is normal integer to forward loop
    cout<<"Number of Vertics will be: ";
    cin>>m;
    long A[m][m],P[m][m];
    //A is name of Adjacency Matrix
    //P is the name of Path Matrix
    //For loop to take input the Adjacency Matrix
    cout<<"Enter the Adjacency Matrix Below in "<<m<<"x"<<m<<" size:"<<endl;
    for(i=0;i<m;i++){
        for(j=0;j<m;j++){
            cin>>A[i][j];
            if(A[i][j]!=0)P[i][j]=1;       ///Finding path matrix
            else P[i][j]=0;
        }
    }
    cout<<endl;
    
    ///Finding Warshall's Path Matrix
    for (k = 0; k < m; k++) {
    for (i = 0; i < m; i++) {
        for (j = 0; j < m; j++) {
            P[i][j] = P[i][j] || (P[i][k] && P[k][j]);
        }
      }
    }
    //Printing Path Matrix
    cout<<"Path Matrix :"<<endl;
    for(i=0;i<m;i++){
        for(j=0;j<m;j++){
            cout<<P[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    return 0;
}

