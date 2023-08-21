#include<bits/stdc++.h>
using namespace std;
void insert_heap(int ar[],int i,int key)
{
    int par = (i-1)/2;
    if(ar[i]==-1)
    {
       ar[i] = key;
    }
    if(ar[par]>0)
    {
         ar[i] = key;
        if(ar[par]<ar[i])
        {
            swap(ar[par],ar[i]);
            insert_heap(ar,par,key);
        }
    }
}
int main()
{
    int ar[100];
    fill(ar,ar+100,-1);
    for(int i=0;i<5;i++)
    {
        int a;
        cin>>a;
        insert_heap(ar,i,a);
    }
    for(int i=0;i<5;i++)
    {
       cout<<ar[i]<<" ";
    }
}
