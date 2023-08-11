
#include<bits/stdc++.h>
using namespace std;
#define MAX 10000
int top = -1;
int Stack[MAX];///operator stack
//int Stack1[MAX];///operand stack
char infix[MAX];
char postfix[MAX];
void push(int c)
{
    if(top>=MAX-1)
    {
        cout<<"Stack overflow"<<endl;
        //indicates the end of the Stack
        return;
    }
    top = top + 1;
    Stack[top] = c;
}
int pop()
{
    if(top<0)
    {
        cout<<"Stack underflow"<<endl;
        exit(1);
    }
    int c = Stack[top];
    top = top -1;
    return c;
}
bool isEmpty()
{
    return (top<0);
}
bool space(char c)
{
    return (c==' '||c=='\t');
}
int precedence(char c)
{
    switch(c)
    {
        case '^' :
            return 3;
            break;
        case '*':
        case'/' :
            return 2;
            break;
        case '+':
        case'-' :
            return 1;
            break;
        default :
            return 0;
    }
}
void infixToPostfix()
{
    char symbol,next;
    int j = 0;
    for(int i=0;i<strlen(infix);i++)
    {
        symbol = infix[i];
        if(!space(symbol))
        {
            switch(symbol)
            {
            case '(' :
                push(symbol);
                break;
            case ')' :
                while((next=pop())!='(')
                {
                    postfix[j++] = next;
                }
                break;
            case '^' :
            case '/' :
            case '*' :
            case '+' :
            case '-' :
                while(!isEmpty()&&precedence(Stack[top])>=precedence(symbol))
                {
                    postfix[j++] = pop();
                }
                push(symbol);
                break;
            default :
                postfix[j++] = symbol;
            }
        }
    }
    while(!isEmpty())
    {
        postfix[j++] = pop();
    }
    postfix[j] = '\0';

}
int power(int a,int b)
{
    int i,mult = 1;
    for(i = 0;i<b;i++)
    {
        mult*=a;
    }
    return mult;
}
int post_eval()
{
   int i;

   for(i = 0;i<strlen(postfix);i++)
   {
       if(postfix[i]>='0'&&postfix[i]<='9')
       {
           push(postfix[i]-'0');
       }
       else
       {
           /**
           pop the two topmost symbols of the stack
           and perform the operation on them.
           */
           int a = pop();
           int b = pop();
           switch(postfix[i])
           {

                case '+' :
                    push(b+a);
                    break;
                case '-' :
                    push(b-a);
                    break;
                case '*' :
                    push(b*a);
                    break;
                case '/' :
                    push(b/a);
                    break;
                case '^' :
                    push(power(b,a));
                    break;
           }
       }
   }
   return pop();

}

void print()
{
    int i=0;
    cout<<"The equivalent postfix expression is :";
    while(postfix[i])
    {
        cout<<postfix[i++];
    }
    cout<<endl;
}


int main()
{
    int result;
    cout<<" Enter the infix expression : ";

    ///gets(infix);

    cin.getline(infix,MAX);
    infixToPostfix();
    result = post_eval();
    print();
    cout<<"the result obtained after postfix evaluation is : "<<result<<endl;

    return 0;
}


