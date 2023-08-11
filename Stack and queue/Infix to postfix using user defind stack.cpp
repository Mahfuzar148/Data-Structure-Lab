/**
Scan the symbols of the expression from left to right and for each symbol, do the following:
a. If symbol is an operand
■ Print that symbol onto the screen.
b. If symbol is a left parenthesis
Push it on the stack.
c. If symbol is a right parenthesis
■ Pop all the operators from the stack upto the first left parenthesis and print them on the screen.
Discard the left and right parentheses.
d. If symbol is an operator
☐ If the precedence of the operators in the stack are greater than or equal to the current operator, then Pop the operators out of the stack and print them onto the screen, and push the current operator onto the stack.
☐ else
Push the current operator onto the stack.
*/

#include<bits/stdc++.h>
using namespace std;
#define MAX 100
char Stack[MAX];
char infix[MAX],postfix[MAX];
int top = -1;
void push(char chr);
char pop();
int isEmpty();
int space(char chr);
int precedence(char symbol)
{
    /// higher value means greater precedence
    switch(symbol)
    {
    case '^' :
        return 3;
        break;
    case '*' :
    case '/' :
        return 2;
        break;
    case '+' :
    case '-' :
        return 1;
        break;
    default :
        return 0;

    }
}
void inToPost()
{
    /**
    We need a loop .
    Let's create a for loop which will run until
    all the symbols of the expression are read.
    */
    int i,j=0;
    char symbol,next;
    for(i=0;i<strlen(infix);i++)
    {
        symbol = infix[i];
        /**
        We will check all the conditions
        by using switch cases
        */
        if(!space(symbol))
        {
            switch(symbol){
            case '(' :
                push(symbol);
                break;
            case ')'  :
                /**
                Pop all the characters from the stack upto the first
                left parenthesis and store the operators in the postfix array.
                Let's take a while loop and check if the popped symbol
                is not equal to the '(' then store that symbol in the postfix array.
                */
                while((next = pop())!='(')
                    {
                        postfix[j++] = next;
                    }
                    break;
            case '+' :
            case '-' :
            case '*' :
            case '/' :
            case '^' :
                while(!isEmpty()&&precedence(Stack[top])>=precedence(symbol))
                {
                    postfix[j++] = pop();
                }
                push(symbol);
                break;
            default:
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
void print()
{
    int i=0;
    cout<<"The equivalent postfix expression is : ";
    while(postfix[i])
    {
        cout<<postfix[i];
        i++;
    }
    cout<<endl;
}
int main()
{
    cout<<strlen(infix)<<endl;
    cout<<"Enter the infix expression :";
    gets(infix);
    /**
    call the function to convert the given infix expression
    to its equivalent postfix expression
    */
    inToPost();
    print();
    return 0;

}
int space(char chr)
{
    if(chr==' '||chr=='\t')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void push(char chr)
{
    if(top>=MAX-1)
    {
        cout<<"Stack overflow"<<endl;
        return ;// indicates the end of the function
    }
     top = top + 1;
     Stack[top] = chr;
}
char pop()
{
    char c;
    if(top<0)
    {
        cout<<"Stack underflow"<<endl;
        exit(1);
    }
    c = Stack[top];
    top = top - 1;
    return c;
}
int isEmpty()
{
    if(top<0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

