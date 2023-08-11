#include<bits/stdc++.h>
using namespace std;
#define MAX 1000
class Stack{

   int top;

   public :
       Stack(){top = -1;}
       char stk[MAX];
       void push(char chr);
       char peek();
       char pop();
       bool isEmpty();
       void display();

};
void Stack::push(char chr){
    if(top>=MAX-1)
    {
        cout<<"Stack overflow"<<endl;
    }
    else
    {
        top = top+1;
        stk[top] = chr;
    }
}
bool Stack::isEmpty()
{
    return(top<0);
}

char Stack::peek()
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
char Stack::pop()
{
    if(top<0)
    {
        cout<<"Stack underflow "<<endl;
    }
    else
    {
        char x = stk[top];
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
    cout<<" Insert character number of stack = "<<endl;
    int n;
    cin>>n;
    cout<<"Enter character = "<<n<<endl;
    for(int i=0;i<n;i++)
    {
        char a;
        cin>>a;
        s.push(a);
    }
    cout<<"Peek value of the stack is "<<s.peek()<<endl;
    char x = s.pop();
    cout<<x<<" has been popped from stack"<<endl;
    s.display();

    return 0;

}
