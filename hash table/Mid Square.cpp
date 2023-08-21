#include<bits/stdc++.h>
using namespace std;
#define mx 11
int hash_table[mx];
int hash_function(int data)
{
    data = data*data;
    int l = log10(data)+1;
    int index;
    if(l%2)
    {
        index = data/pow(10,(l/2));
        index = index%10;
    }
    else
    {
        index = data/pow(10,(l-1)/2);
        index = index %100;
    }
    return (index%mx);
}

int main()
{
    int ar[] = {25,30,3567,345,456,678,459};

    int n = sizeof(ar)/sizeof(ar[0]);
    for(int i=0;i<n;i++)
    {
       int index=hash_function(ar[i]);
       int origin = index ;
       if(hash_table[index]==0)
       {
           hash_table[index] = ar[i];
       }
       else
       {
           while(1)
           {
               index = (index + 1)%mx;
               if(index==origin)
               {
                   cout<<"Hash_table is full."<<ar[i]<<" can not be inserted.";
                   break;
               }
               if(hash_table[index]==0)
               {
                   hash_table[index] = ar[i];
                   break;
               }
           }
       }


    }

     for(int i=0;i<n;i++)
    {
       int index=hash_function(ar[i]);
       int origin = index ;
       if(hash_table[index]==ar[i])
       {
           cout<<ar[i]<<" is found at index "<<index<<endl;
       }
       else
       {
           while(hash_table[index]!=ar[i])
           {
               index = (index + 1)%mx;
               if(index==origin)
               {
                   cout<<ar[i]<<"is not found in the Hashtable"<<endl;
                   break;
               }

           }
           cout<<ar[i]<<" is found at index "<<index<<endl;

       }


    }
    return 0;



}
