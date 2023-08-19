
#include<bits/stdc++.h>
using namespace std;
#define MX 11

class Node{
   public :
   string data;
   Node* next;
   Node(string data)
   {
       this->data=data;
       this->next = nullptr;
   }
};
Node* hashTable[MX];
int hash_function(string data)
{
    int sum = 0;
    for(int i=0;i<data.size();i++)
    {
        sum = sum + data[i] ;
    }
    return (sum%MX);
}
void search_data(string info)
{
    int index = hash_function(info);
    Node* tmp = hashTable[index];
    int i = 0;
    while(tmp!=nullptr)
    {
        if(tmp->data==info)
        {
            cout<<info<<" found at "<<index<<"->"<<i<<endl;
            return;
        }
        tmp = tmp->next;
        i++;
    }
    cout<<info <<" not found"<<endl;
}

int main()
{
    string str[] = {"Rajshahi","university","computer","Science","Engineering","of","Department"};
    Node *ptr,*tmp;
   for(int i=0;i<7;i++)
   {
        ptr = new Node(str[i]);
        int index = hash_function(str[i]);
        tmp = hashTable[index];
        if(tmp==nullptr)
        {
            hashTable[index] = ptr;
        }
        else
        {
            while(tmp->next!=nullptr)
            {
                tmp = tmp->next;
            }
            tmp->next = ptr;
        }
   }
   for(int i=0;i<7;i++)
   {
       search_data(str[i]);
   }

   return 0;

}
