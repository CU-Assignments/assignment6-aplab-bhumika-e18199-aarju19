#include <iostream>
#include <stack>

class MinStack {
private:
    std::stack<int> mainStack;
    std::stack<int> minStack;

public:
    void push(int x) {
        mainStack.push(x);
        if (minStack.empty() || x <= minStack.top()) {
            minStack.push(x);
        }
    }

    void pop() {
        if (mainStack.empty()) return;
        if (mainStack.top() == minStack.top()) {
            minStack.pop();
        }
        mainStack.pop();
    }

    int top() {
        return mainStack.empty() ? -1 : mainStack.top();
    }

    int getMin() {
        return minStack.empty() ? -1 : minStack.top();
    }
};

int main() {
    MinStack minStack;
    minStack.push(5);
    minStack.push(3);
    minStack.push(7);
    std::cout << "Min: " << minStack.getMin() << std::endl;
    minStack.pop();
    std::cout << "Top: " << minStack.top() << std::endl;
    minStack.pop();
    std::cout << "Min: " << minStack.getMin() << std::endl;
    return 0;
}
