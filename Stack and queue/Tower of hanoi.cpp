#include<bits/stdc++.h>
using namespace std;
void tower_of_hanoi(int n,char s,char a ,char d)
{
    if(n==1)
    {
         cout<<" Mode disk "<<n<<" from "<<s<<" to "<<d<<endl;
         return ;
    }
    tower_of_hanoi(n-1,s,d,a);
    cout<<" Mode disk "<<n<<" from "<<s<<" to "<<d<<endl;
    tower_of_hanoi(n-1,a,s,d);
}
int main()
{
    cout<<"enter the number of disk :"<<endl;
    int n;
    cin>>n;
    tower_of_hanoi(n,'A','B','C');
    return 0;
}
