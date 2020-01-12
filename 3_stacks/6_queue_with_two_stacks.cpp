/**
 *  Implement a queue data structure using two stacks.
 * 
 *  * Solution
 * 
 *    (1) in-stack & out-stack: O(1) push & pop
 *        - use each stack for different purposes
 *          - push: push new element into the in-stack
 *          - pop: pop new element from out-stack
 *                 if out-stack is empty, 
 * 
 * 
 *  ** What I learned
 * 
 * 
*/
#include <bits/stdc++.h>
using namespace std;

/**
 *  
 */
class Queue {
    private: 
        stack<int> inStack;
        stack<int> outStack;

    public:
        // constructor method
        Queue() {

        }

        // push value into queue
        void enqueue(int value) {
            this->inStack.push(value);
        }

        // pop value from stack
        void pop() {
            moveInFromOut();
            if (this->outStack.empty()) {
                throw invalid_argument("cannot dequeue from empty queue!");
            }
            this->outStack.pop();
        }

        // check the front value in the queue
        int front() {
            moveInFromOut();
            if (this->outStack.empty()) {
                throw invalid_argument("queue is empty!");
            }
            return this->outStack.top();
        }

        /** 
         *  helper function: enable access to front of queue
         */ 
        void moveInFromOut() {
            /** if out-stack is empty, move in-stack elements to out-stack
             *  (this reverses the order of the elements to FIFO order)
             */ 
            if (!this->outStack.empty()) {
                while(!this->inStack.empty()) {
                    int topElement = this->inStack.top();
                    this->inStack.pop();
                    this->outStack.push(topElement);
                }
            }
        }

        // check if stack is empty or not
        bool isEmpty() {
            if (this->outStack.empty() && this->inStack.empty()) {
                return true;
            }
            return false;
        }
};
