/**
 *  Implement a stack using a dynamic array
 * 
 *  * 
 * 
 *  ** What I learned
*/

#include <bits/stdc++.h>
using namespace std;

/**
 *  define class for stack
 */
class Stack {

    vector<int> stack_;
    size_t size_ = 0;

    // push value into stack
    void push(int value) {
        stack_[size_] = value;
        size_++;
    }

    // pop value from stack
    void pop() {
        if (size_ == 0) {
            throw invalid_argument("cannot pop from empty stack!");
        }
        size_--;
    }

    // return top value
    int top() {
        if (size_ == 0) {
            throw invalid_argument("stack is empty!");
        }
        return stack_[size_ - 1];
    }

    // return number of elements in stack
    size_t size() {
        return size_;
    }

    // check if stack is empty or not
    bool isEmpty() {
        if (size_ == 0) return true;
        return false;
    }
};