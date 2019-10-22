#include <stack>
using namespace std;

class MyQueue {
public:
    MyQueue() {

    }

    void push(int x) {
        while(!stack1.empty()){
            stack2.push(stack1.top());
            stack1.pop();
        }
        stack2.push(x);
    }

    int pop() {
        while(!stack2.empty()){
            stack1.push(stack2.top());
            stack2.pop();
        }
        int t = stack1.top();
        stack1.pop();
        return t;
    }

    int peek() {
        while(!stack2.empty()){
            stack1.push(stack2.top());
            stack2.pop();
        }
        return stack1.top();
    }

    bool empty() {
        return stack1.empty() && stack2.empty();
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};