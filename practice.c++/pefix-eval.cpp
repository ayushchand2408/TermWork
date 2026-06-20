#include <iostream>
#include <stack>
#include <string>
#include <cctype>

// Function to evaluate a prefix expression
int evaluatePrefix(const std::string& expression) {
    std::stack<int> stack;
    
    // Loop over the expression from right to left
    for (auto it = expression.rbegin(); it != expression.rend(); ++it) {
        char ch = *it;

        if (isdigit(ch)) {
            // Convert character to integer and push onto stack
            stack.push(ch - '0');
        } else {
            // Pop two operands from stack
            int operand1 = stack.top(); stack.pop();
            int operand2 = stack.top(); stack.pop();

            // Perform the operation based on the current operator
            switch (ch) {
                case '+':
                    stack.push(operand1 + operand2);
                    break;
                case '-':
                    stack.push(operand1 - operand2);
                    break;
                case '*':
                    stack.push(operand1 * operand2);
                    break;
                case '/':
                    stack.push(operand1 / operand2);
                    break;
                default:
                    std::cerr << "Invalid operator encountered: " << ch << std::endl;
                    return -1;
            }
        }
    }

    // The final result will be the only element left in the stack
    return stack.top();
}

int main() {
    std::string expression = "-+53*82";
    int result = evaluatePrefix(expression);
    std::cout << "The result of the prefix evaluation is: " << result << std::endl;
    return 0;
}
