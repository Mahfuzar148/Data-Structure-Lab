#include<bits/stdc++.h>
using namespace std;
#define MX 11
int hashTable[MX];
int hashFunction(int data)
{
    int sum = 0;
    while(data>0)
    {
        sum = sum + (data%100);
        data /= 100;
    }
    return (sum%MX);
}
void search_data(int data)
{
     int index = hashFunction(data);
        int origin = index;
        bool f = true;

        while(hashTable[index]!=data)
        {
            index = (index + 1)%MX;
            if(index == origin)
            {
                f = false;
                cout<<data<<" is not found."<<endl;
                return;

            }
        }
        if(f) cout<<data<<" is found at "<<index<<endl;

}
int main()
{
    int data[] = {53464, 2236, 93, 124647, 772, 31, 55, 550, 2103};
    fill(hashTable,hashTable+MX,-1);

    for(int i=0;i<9;i++)
    {
        int index = hashFunction(data[i]);

        int origin = index;
        while(hashTable[index]!=-1)
        {
            index = (index + 1)% MX;

            if(index == origin)
            {
                cout<<"HashTable is full"<<data[i]<<" can not be inserted."<<endl;
                break;
            }
        }
        hashTable[index] = data[i];

    }

    ///search
    for(int i=0;i<9;i++)
    {
       search_data(data[i]);
    }
    search_data(34);
    return 0;

}
