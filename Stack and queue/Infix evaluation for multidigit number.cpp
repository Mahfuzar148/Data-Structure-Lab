
#include <bits/stdc++.h>
using namespace std;

int precedence(char ch) {
    switch (ch) {
        case '^':
            return 3;
        case '*':
        case '/':
            return 2;
        case '+':
        case '-':
            return 1;
    }
    return 0;
}
int power(int a,int b);

int solve(int a, int b, char ch) {
    switch (ch) {
        case '^':
            return power(a, b);
        case '*':
            return (a * b);
        case '/':
            return (a / b);
        case '+':
            return (a + b);
        case '-':
            return (a - b);
    }
    return 0;
}

int main() {
    string str;
    getline(cin, str);
    stack<int> is;
    stack<char> op;

    for (int i = 0; i < str.length(); i++) {
      if(!isspace(str[i]))
      {
            char ch = str[i];
            if (isdigit(ch)) {
                int num = 0;
                while (i < str.length() && isdigit(str[i])) {
                    num = num * 10 + (str[i] - '0');
                    i++;
                }
                i--;
                is.push(num);
            } else if (ch == '(') {
                op.push(ch);
            } else if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^') {
                while (!op.empty() && op.top() != '(' && precedence(ch) <= precedence(op.top())) {
                    int v2 = is.top();
                    is.pop();
                    int v1 = is.top();
                    is.pop();
                    char op1 = op.top();
                    op.pop();
                    int ans = solve(v1, v2, op1);
                    is.push(ans);
                }
                op.push(ch);
            } else if (ch == ')') {
                while (!op.empty() && op.top() != '(') {
                    int v2 = is.top();
                    is.pop();
                    int v1 = is.top();
                    is.pop();
                    char op1 = op.top();
                    op.pop();
                    int ans = solve(v1, v2, op1);
                    is.push(ans);
                }
                if (!op.empty()) {
                    op.pop();
                }
            }
      }
    }

    while (!op.empty()) {
        int v2 = is.top();
        is.pop();
        int v1 = is.top();
        is.pop();
        char op1 = op.top();
        op.pop();
        int ans = solve(v1, v2, op1);
        is.push(ans);
    }

    int ans = is.top();
    is.pop();
    cout << ans << endl;

    return 0;
}

int power(int a, int b) {
    int mult = 1;
    for (int i = 0; i < b; i++) {
        mult *= a;
    }
    return mult;
}

