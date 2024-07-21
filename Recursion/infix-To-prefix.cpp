#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

int precedence(char c) {
    if (c == '^') {
        return 3;
    } else if (c == '*' || c == '/') {
        return 2;
    } else if (c == '+' || c == '-') {
        return 1;
    } else {
        return -1;
    }
}

string infixToPrefixRecursive(string infix, int i, stack<char> &s) {
    if (i == infix.length()) {
        string prefix = "";
        while (!s.empty()) {
            prefix = s.top() + prefix;
            s.pop();
        }
        return prefix;
    }

    if (infix[i] == '(') {
        infix[i] = ')';
    } else if (infix[i] == ')') {
        infix[i] = '(';
    }

    if (isalnum(infix[i])) {
        return infix[i] + infixToPrefixRecursive(infix, i + 1, s);
    } else if (infix[i] == '(') {
        s.push(infix[i]);
        return infixToPrefixRecursive(infix, i + 1, s);
    } else if (infix[i] == ')') {
        string prefix = "";
        while (!s.empty() && s.top() != '(') {
            prefix = s.top() + prefix;
            s.pop();
        }
        s.pop();
        return prefix + infixToPrefixRecursive(infix, i + 1, s);
    } else {
        string prefix = "";
        while (!s.empty() && precedence(s.top()) >= precedence(infix[i])) {
            prefix = s.top() + prefix;
            s.pop();
        }
        s.push(infix[i]);
        return prefix + infixToPrefixRecursive(infix, i + 1, s);
    }
}

string infixToPrefix(string infix) {
    reverse(infix.begin(), infix.end());
    stack<char> s;
    return infixToPrefixRecursive(infix, 0, s);
}

int main() {
    string infix = "(A+B)*(C+D)";
    cout << "Infix expression: " << infix << endl;
    string prefix = infixToPrefix(infix);
    reverse(prefix.begin(), prefix.end());
    cout << "Prefix expression: " << prefix << endl;
    return 0;
}
