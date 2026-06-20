#include <iostream>
#include <stack>
#include <string>
#include <cctype>

int evaluatePostfix(const std::string& expression) {
    std::stack<int> stack;
    
    for (char ch : expression) {
        if (isdigit(ch)) {
            // Convert character to integer and push onto stack
            stack.push(ch - '0');
        } else {
            // Pop two operands from stack
            int operand2 = stack.top(); stack.pop();
            int operand1 = stack.top(); stack.pop();

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
    std::string expression = "53+82-*";
    int result = evaluatePostfix(expression);
    std::cout << "The result of the postfix evaluation is: " << result << std::endl;
    return 0;
}
