#include <iostream>
#include <stack>
#include <string>
#include <cctype>
#include <sstream>
#include <stdexcept>
using namespace std;

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

int applyOp(int a, int b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': 
            if (b == 0) throw runtime_error("Division by zero error");
            return a / b;
    }
    return 0;
}

int evaluate(string tokens) {
    int i;
    stack<int> values;
    stack<char> ops;

    for (i = 0; i < tokens.length(); i++) {
        if (isspace(tokens[i])) continue;

        if (isdigit(tokens[i])) {
            int val = 0;
            while (i < tokens.length() && isdigit(tokens[i])) {
                val = (val * 10) + (tokens[i] - '0');
                i++;
            }
            values.push(val);
            i--;
        } else if (tokens[i] == '(') {
            ops.push(tokens[i]);
        } else if (tokens[i] == ')') {
            while (!ops.empty() && ops.top() != '(') {
                int val2 = values.top(); values.pop();
                int val1 = values.top(); values.pop();
                char op = ops.top(); ops.pop();
                values.push(applyOp(val1, val2, op));
            }
            ops.pop();
        } else if (tokens[i] == '+' || tokens[i] == '-' ||
                   tokens[i] == '*' || tokens[i] == '/') {
            while (!ops.empty() && precedence(ops.top()) >= precedence(tokens[i])) {
                int val2 = values.top(); values.pop();
                int val1 = values.top(); values.pop();
                char op = ops.top(); ops.pop();
                values.push(applyOp(val1, val2, op));
            }
            ops.push(tokens[i]);
        }
    }

    while (!ops.empty()) {
        int val2 = values.top(); values.pop();
        int val1 = values.top(); values.pop();
        char op = ops.top(); ops.pop();
        values.push(applyOp(val1, val2, op));
    }

    return values.top();
}

int main() {
    string expression;
    cout << "Enter an infix expression: ";
    getline(cin, expression);

    try {
        cout << "Result: " << evaluate(expression) << endl;
    } catch (const exception &e) {
        cout << "Error: " << e.what() << endl;
    }
    return 0;
}
