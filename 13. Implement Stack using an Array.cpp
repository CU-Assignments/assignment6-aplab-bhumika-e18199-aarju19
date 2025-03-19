#include <iostream>

class Stack {
private:
    int top;
    int capacity;
    int* arr;

public:
    Stack(int size) {
        capacity = size;
        arr = new int[capacity];
        top = -1;
    }

    void push(int x) {
        if (top == capacity - 1) {
            std::cout << "Stack Overflow\n";
            return;
        }
        arr[++top] = x;
    }

    void pop() {
        if (top == -1) {
            std::cout << "Stack Underflow\n";
            return;
        }
        top--;
    }

    int peek() {
        return (top == -1) ? -1 : arr[top];
    }

    bool isEmpty() {
        return top == -1;
    }

    ~Stack() {
        delete[] arr;
    }
};

int main() {
    std::cout << "13. Implement Stack using an Array\n\n";

    Stack stack(5);
    stack.push(10);
    stack.push(20);
    stack.push(30);

    std::cout << "Top Element: " << stack.peek() << std::endl;
    stack.pop();
    std::cout << "Top Element after pop: " << stack.peek() << std::endl;
    
    return 0;
}
