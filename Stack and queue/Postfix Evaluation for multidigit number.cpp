#include <bits/stdc++.h>
using namespace std;

#define MAX 10000

int top = -1;
int Stack[MAX];
char infix[MAX];
char postfix[MAX];

void push(int c) {
    if (top >= MAX - 1) {
        cout << "Stack overflow" << endl;
        return;
    }
    top = top + 1;
    Stack[top] = c;
}

int pop() {
    if (top < 0) {
        cout << "Stack underflow" << endl;
        exit(1);
    }
    int c = Stack[top];
    top = top - 1;
    return c;
}

bool isEmpty() {
    return (top < 0);
}

bool space(char c) {
    return (c == ' ' || c == '\t');
}

int precedence(char c) {
    switch (c) {
        case '^':
            return 3;
        case '*':
        case '/':
            return 2;
        case '+':
        case '-':
            return 1;
        default:
            return 0;
    }
}

void infixToPostfix() {
    char symbol, next;
    int j = 0;
    for (int i = 0; i < strlen(infix); i++) {
        symbol = infix[i];
        if (!space(symbol)) {
            switch (symbol) {
                case '(':
                    push(symbol);
                    break;
                case ')':
                    while ((next = pop()) != '(') {
                        postfix[j++] = next;
                    }
                    break;
                case '^':
                case '/':
                case '*':
                case '+':
                case '-':
                    while (!isEmpty() && precedence(Stack[top]) >= precedence(symbol)) {
                        postfix[j++] = pop();
                    }
                    push(symbol);
                    break;
                default:
                    // Handle multi-digit numbers
                    while (i < strlen(infix) && isdigit(infix[i])) {
                        postfix[j++] = infix[i++];
                    }
                    i--;
                    postfix[j++] = ' '; // Add a space to separate numbers
            }
        }
    }
    while (!isEmpty()) {
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
int post_eval() {
    int i = 0;

    while (i < strlen(postfix)) {
        if (isdigit(postfix[i])) {
            int num = 0;
            while (isdigit(postfix[i])) {
                num = num * 10 + (postfix[i] - '0');
                i++;
            }
            push(num);
        } else if (postfix[i] != ' ') {
            int a = pop();
            int b = pop();
            switch (postfix[i]) {
                case '+':
                    push(b + a);
                    break;
                case '-':
                    push(b - a);
                    break;
                case '*':
                    push(b * a);
                    break;
                case '/':
                    push(b / a);
                    break;
                case '^':
                    push(power(b, a));
                    break;
            }
            i++;
        } else {
            i++;
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


// Rest of the code remains the same

int main() {
    int result;
    cout << "Enter the infix expression: ";
    cin.getline(infix, MAX);
    infixToPostfix();
    result = post_eval();
    print();
    cout << "The result obtained after postfix evaluation is: " << result << endl;
    return 0;
}

