/* Implement the following operations of a stack using queues.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
empty() -- Return whether the stack is empty.
Notes:
You must use only standard operations of a queue -- which means only push to back, peek/pop from front, size, and is empty operations are valid.
Depending on your language, queue may not be supported natively. You may simulate a queue by using a list or deque (double-ended queue), as long as you use only standard operations of a queue.
You may assume that all operations are valid (for example, no pop or top operations will be called on an empty stack).
*/


class Stack {
private:
    queue<int> qa;
    queue<int> qb;
    bool isqa;
public:
    Stack () {
        bool isqa = true;
    }
    // Push element x onto stack.
    void push(int x) {
        if(isqa) qa.push(x);
        else qb.push(x);
    }

    // Removes the element on top of the stack.
    void pop() {
        if (isqa) {
            while (qa.size() != 1) {
                int temp = qa.front();
                qb.push(temp);
                qa.pop();
            }
            qa.pop();
            isqa = false;
        }
        else {
            while (qb.size() != 1) {
                int temp = qb.front();
                qa.push(temp);
                qb.pop();
            }
            qb.pop();
            isqa = true;
        }
    }

    // Get the top element.
    int top() {
        if (isqa) {
            while (qa.size() != 1) {
                int temp = qa.front();
                qb.push(temp);
                qa.pop();
            }
            return qa.front();
        }
        else {
            while (qb.size() != 1) {
                int temp = qb.front();
                qa.push(temp);
                qb.pop();
            }
            return qb.front();
        }
    }

    // Return whether the stack is empty.
    bool empty() {
        if (isqa) return qa.empty();
        else return qb.empty();
    }
};
