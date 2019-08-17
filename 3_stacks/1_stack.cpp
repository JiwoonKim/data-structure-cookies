/**
 *  Implement a stack using a dynamic allocated array
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
    private:
        int* stackArr;
        size_t size;
        size_t capacity;

    public:
        // constructor method
        Stack(size_t capacity) {
            this->stackArr = new int[capacity];
            this->size = 0;
            this->capacity = capacity;
        }

        // resize method
        int* resize() {
            /** create space for twice the capacity of original
             *  and move all elements to new space
             */
            int* temp = new int[this->capacity * 2];
            for (int i = 0; i < this->size; i++) {
                temp[i] = this->stackArr[i];
            }

            // delete original and set pointer to new space
            delete stackArr;
            this->stackArr = temp;
        }

        // push value into stack
        void push(int value) {
            if (this->size == this->capacity) {
                this->stackArr = resize();
            }
            this->stackArr[this->size] = value;
            this->size++;
        }

        // pop value from stack
        void pop() {
            if (this->size == 0) {
                throw invalid_argument("cannot pop from empty stack!");
            }
            this->size--;
        }

        // return top value
        int top() {
            if (this->size == 0) {
                throw invalid_argument("stack is empty!");
            }
            return this->stackArr[this->size - 1];
        }

        // return number of elements in stack
        size_t size() {
            return this->size;
        }

        // check if stack is empty or not
        bool isEmpty() {
            if (this->size == 0) return true;
            return false;
        }
};