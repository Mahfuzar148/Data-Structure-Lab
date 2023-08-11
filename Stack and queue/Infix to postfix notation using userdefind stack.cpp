#include <iostream>
#include <cstring>
using namespace std;

#define MAX 10000

int top = -1;
char Stack[MAX];
char infix[MAX];
char postfix[MAX];

void push(char c) {
    if (top >= MAX - 1) {
        cout << "Stack overflow" << endl;
        return;
    }
    top = top + 1;
    Stack[top] = c;
}

char pop() {
    if (top < 0) {
        cout << "Stack underflow" << endl;
        exit(1);
    }
    char c = Stack[top];
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
                    postfix[j++] = symbol;
            }
        }
    }
    while (!isEmpty()) {
        postfix[j++] = pop();
    }
    postfix[j] = '\0';
}

void print() {
    int i = 0;
    cout << "The equivalent postfix expression is: ";
    while (postfix[i]) {
        cout << postfix[i++];
    }
    cout << endl;
}

int main() {
    cout << "Enter the infix expression: ";
    cin.getline(infix, MAX);
    infixToPostfix();
    print();

    return 0;
}
