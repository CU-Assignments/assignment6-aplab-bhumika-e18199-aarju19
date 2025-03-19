#include <iostream>
#include <stack>

class PriorityQueue {
private:
    std::stack<int> mainStack;
    std::stack<int> tempStack;

public:
    void push(int x) {
        while (!mainStack.empty() && mainStack.top() > x) {
            tempStack.push(mainStack.top());
            mainStack.pop();
        }
        mainStack.push(x);
        while (!tempStack.empty()) {
            mainStack.push(tempStack.top());
            tempStack.pop();
        }
    }

    void pop() {
        if (!mainStack.empty()) {
            mainStack.pop();
        }
    }

    int top() {
        return mainStack.empty() ? -1 : mainStack.top();
    }

    bool empty() {
        return mainStack.empty();
    }
};

int main() {
    PriorityQueue pq;
    pq.push(5);
    pq.push(1);
    pq.push(3);
    pq.push(2);

    std::cout << "Top: " << pq.top() << std::endl;
    pq.pop();
    std::cout << "Top: " << pq.top() << std::endl;
    pq.pop();
    std::cout << "Top: " << pq.top() << std::endl;
    
    return 0;
}
