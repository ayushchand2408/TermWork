#include <iostream>
#include <stack>

class Queue {
private:
    std::stack<int> stack1, stack2;

public:
    void enqueue(int x) {
        stack1.push(x);
    }

    void dequeue() {
        if (stack2.empty()) {
            while (!stack1.empty()) {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        if (!stack2.empty()) {
            stack2.pop();
        } else {
            std::cout << "Queue is empty" << std::endl;
        }
    }

    int front() {
        if (stack2.empty()) {
            while (!stack1.empty()) {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        if (!stack2.empty()) {
            return stack2.top();
        } else {
            std::cout << "Queue is empty" << std::endl;
            return -1;
        }
    }

    bool empty() {
        return stack1.empty() && stack2.empty();
    }
};

int main() {
    Queue queue;
    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);

    std::cout << "Front element is: " << queue.front() << std::endl;

    queue.dequeue();
    std::cout << "Front element after dequeue is: " << queue.front() << std::endl;

    queue.dequeue();
    queue.dequeue();
    queue.dequeue();  // Trying to dequeue from an empty queue

    return 0;
}
