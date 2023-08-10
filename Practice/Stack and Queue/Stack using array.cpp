#include<bits/stdc++.h>
using namespace std;
#define MAX 1000
class Stack{

   int top;

   public :
       Stack(){top = -1;}
       int stk[MAX];
       void push(int data);
       int peek();
       int pop();
       bool isEmpty();
       void display();

};
void Stack::push(int data){
    if(top>=MAX-1)
    {
        cout<<"Stack overflow"<<endl;
    }
    else
    {
        top = top+1;
        stk[top] = data;
    }
}
bool Stack::isEmpty()
{
    return(top<0);
}

int Stack::peek()
{
    if(isEmpty())
    {
        cout<<"Stack is Empty."<<endl;
    }
    else
    {
        return stk[top];
    }
}
int Stack::pop()
{
    if(top<0)
    {
        cout<<"Stack underflow "<<endl;
    }
    else
    {
        int x = stk[top];
        top--;
        return x;
    }

}
void Stack::display()
{
    while(top>=0)
    {
        cout<<peek()<<" ";
        top--;
    }
    cout<<endl;
}

int main()
{
    class Stack s;
    cout<<" Insert element number of stack = "<<endl;
    int n;
    cin>>n;
    cout<<"Enter element = "<<n<<endl;
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        s.push(a);
    }
    cout<<"Peek value of the stack is "<<s.peek()<<endl;
    int x = s.pop();
    cout<<x<<" has been popped from stack"<<endl;
    s.display();
    
    return 0;

}
