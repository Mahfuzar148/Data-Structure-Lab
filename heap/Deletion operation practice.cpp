#include<bits/stdc++.h>
using namespace std;
void heapify(int ar[],int n,int i)
{
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;
    if(l<n&&ar[l]>ar[largest])
    {
        largest = l;
    }

    if(r<n&&ar[r]>ar[largest])
    {
        largest = r;
    }
    if(largest!=i)
    {
        swap(ar[largest],ar[i]);
        heapify(ar,n,largest);
    }

}
void build_heap(int ar[],int n)
{
    int startIdx = (n/2)-1;
    for(int i=startIdx;i>=0;i--)
    {
        heapify(ar,n,i);
    }
}
void delete_element(int ar[],int n,int index)
{
    ar[index] = ar[n-1];
    n = n-1;
    heapify(ar,n,index);

}
void print(int ar[],int n)
{
    cout<<"Heap representation : ";
    for(int i=0;i<n;i++)
    {
        cout<<ar[i]<<" ";
    }
    cout<<endl;

}

int main()
{
    int ar[] = {5,10,4,3,12,15,8,9,1,20};

    int sz = sizeof(ar)/sizeof(ar[0]);
    cout<<sz<<endl;
    build_heap(ar,sz);
    print(ar,sz);
    cout<<"Enter element index for deletion : "<<endl;
    int index ;
    cin>>index;
    delete_element(ar,sz,index);
    print(ar,sz);
}
