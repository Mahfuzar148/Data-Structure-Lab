#include<bits/stdc++.h>
using namespace std;
#define MX 1000
char infix[MX];
char postfix[MX];
int Stack[MX];
int top = -1;
void push(int c)
{
    if(top>=MX-1)
    {
         cout<<"Stack overflow"<<endl;
         return ;
    }
    top++;
    Stack[top] = c;
}
char pop()
{
    if(top<0)
    {
        cout<<"Stack underflow"<<endl;
        exit(1);
    }
    int c = Stack[top] ;
    top--;
    return c;
}
bool isEmpty()
{
    return (top<0);
}
int precedence(char c)
{
    if(c=='^')
    {
        return 3;
    }
    else if(c=='/'||c=='*')
    {
        return 2;
    }
    else if(c=='+'||c=='-')
    {
        return 1;
    }
    else
    {
        return -1;
    }
}
bool isSpace(char c)
{
    return (c==' '||c=='\t');
}

void infix_to_postfix()
{
    int j = 0;
    for(int i=0;i<strlen(infix);i++)
    {
        char symbol,next;
        symbol = infix[i];
       if(!isSpace(symbol)){
        if(symbol =='(')
        {
            push(symbol);
        }
        else if(symbol==')')
        {
            while((next = pop())!='(')
            {
                postfix[j++] = next;

            }
        }
        else if(symbol=='+'||symbol=='-'||symbol =='/'||symbol =='*'||symbol =='^')
        {
            while(!isEmpty()&&precedence(Stack[top])>=precedence(symbol))
            {
                postfix[j++] = pop();
            }
            push(symbol);
        }
        else
        {
            while(i<strlen(infix)&&isalnum(infix[i]))
            {
                postfix[j++] = infix[i++];
            }
            i--;
            postfix[j++] = ' ';
        }
    }
    }
    while(!isEmpty())
    {
        postfix[j++] = pop();
    }
}
int post_evaluation()
{
    int num ;
    for(int i=0;i<strlen(postfix);i++)
    {
       char symbol = postfix[i];
       if(isdigit(postfix[i]))
       {
           num = 0;
           while(isdigit(postfix[i]))
           {
               num = num*10 + (postfix[i]-'0');
               i++;
           }
           push(num);
           i--;
       }
       else
       {
          if(postfix[i]!=' ')
          {
               int a = pop();
               int b = pop();
               if(symbol=='+')
               {
                   push(b+a);
               }
               else if(symbol=='-')
               {
                   push(b-a);
               }
               else if(symbol=='/')
               {
                   push(b/a);
               }
               else if(symbol=='*')
               {
                   push(b*a);
               }
               else if(symbol=='^')
               {
                   push(pow(b,a));
               }

          }

       }

    }
    return pop();
}
void print()
{
    for(int i=0;i<strlen(postfix);i++)
    {
        cout<<postfix[i];
    }
    cout<<endl;
}

int main()
{
    cout<<"Enter infix expression : "<<endl;
    cin.getline(infix,MX);

    infix_to_postfix();
    cout<<"Postfix expression : ";
    print();
    cout<< post_evaluation()<<endl;
    return 0;
}


