#include<bits/stdc++.h>
using namespace std;
#define MX 100
int arr[MX] = {20,5,9,11,15,18,30,45,50,75};

void heapify(int arr[],int n,int i)
{
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;
    if(l<n&&arr[l]>arr[largest])
       {
            largest = l;
       }
    if(r<n&&arr[r]>arr[largest])
    {
       largest = r;
    }
    if(largest!=i)
    {
        swap(arr[i],arr[largest]);
        heapify(arr,n,largest);
    }
}
void buil_heap(int arr[],int n)
{
    int startidx = (n/2)-1;
    for(int i=startidx;i>=0;i--)
    {
        heapify(arr,n,i);
    }

}
int insert_value(int val,int n)
{
    n = n + 1;
    arr[n-1] = val;
    int par = ((n-1)-1)/2;
    if(arr[par]>0)
    {
        if(arr[par]<arr[n-1])
        {
            swap(arr[par],arr[n-1]);
            insert_value(val,par);
        }
    }


}
void delete_value(int arr[],int n,int i)
{
    arr[i] = arr[n-1];
    n = n-1;
    heapify(arr,n,i);
}
void print(int arr[],int n)
{
    cout<<"Heap : ";
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main()
{

    int n = MX-count(arr,arr+MX,0);
    buil_heap(arr,n);
    print(arr,n);
    insert_value(100,n);
    print(arr,n);
    delete_value(arr,n,2);
    cout<<"after deleting value of index "<<2 <<" :"<<endl;
    print(arr,n);
    return 0;

}
