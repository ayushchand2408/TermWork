#include <iostream>
#include <stack>
#include <string>
#include <cctype>

// Function to determine precedence of operators
int precedence(char op) {
    switch (op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return 0;
    }
}

// Function to check if a character is an operator
bool isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

// Function to convert infix expression to postfix
std::string infixToPostfix(const std::string& expression) {
    std::stack<char> stack;
    std::string postfix;

    for (char ch : expression) {
        if (isdigit(ch) || isalpha(ch)) {
            // Add operands (numbers and letters) to the postfix expression
            postfix += ch;
        } else if (ch == '(') {
            stack.push(ch);
        } else if (ch == ')') {
            while (!stack.empty() && stack.top() != '(') {
                postfix += stack.top();
                stack.pop();
            }
            if (!stack.empty()) {
                stack.pop(); // Pop the left parenthesis
            }
        } else if (isOperator(ch)) {
            while (!stack.empty() && precedence(stack.top()) >= precedence(ch)) {
                postfix += stack.top();
                stack.pop();
            }
            stack.push(ch);
        }
    }

    // Pop any remaining operators from the stack
    while (!stack.empty()) {
        postfix += stack.top();
        stack.pop();
    }

    return postfix;
}

int main() {
    std::string expression = "3+5*2/(7-4)";
    std::string postfix = infixToPostfix(expression);
    std::cout << "The postfix expression is: " << postfix << std::endl;
    return 0;
}
