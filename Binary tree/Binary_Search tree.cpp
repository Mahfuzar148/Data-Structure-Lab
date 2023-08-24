#include<bits/stdc++.h>
using namespace std;
#define maxSize 10000
int bstArray[maxSize];
bool isFound(int item)
{
    int index = 1;
    while(bstArray[index]!=-maxSize)
    {
        if(bstArray[index]==item)
        {
            return true;
        }
        else if(item>bstArray[index])
        {
            index = 2*index + 1;
        }
        else
        {
            index = 2 * index;
        }
    }
     return false;
}
int getPosition(int item)
{
    int index = 1;
   while(bstArray[index] != -maxSize)
   {
        if(bstArray[index] == item)
        {
            return index;
        }
        else if(item>bstArray[index])
        {
            index = 2*index + 1;
        }
        else
        {
            index = 2*index;
        }
   }
   return -1;
}
void insert(int item)
{
    int index = 1;
    while(bstArray[index]!= -maxSize)
    {
        if(item>bstArray[index])
        {
            index = 2*index + 1;
        }
        else
        {
            index = 2*index;
        }
    }
    bstArray[index] = item;
}
int main()
{

    for(int i=0;i<maxSize;i++) {
        bstArray[i] = -maxSize;
    }
    cout<<"Number of element = ";
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int item;
        cin>>item;
        if(isFound(item))
        {
            cout<<"Item is already inserted and its position = "<<getPosition(item)<<endl;
        }
        else
        {
            insert(item);
        }
    }

    for(int i=0;i<maxSize;i++)
    {
        if(bstArray[i]!=-maxSize)
        {
            cout<<bstArray[i]<<" ";
        }
    }
    cout<<endl;

}
