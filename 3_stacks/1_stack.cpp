/**
 *  Implement a stack using a dynamic allocated array
 * 
 *  * Stack
 *    : array in LIFO order
 *      -> can only access top value
 * 
 *    - push: amortized O(1) 
 *            -> worst case O(n) bcuz need to resize
 *    - pop: O(1) 
 *    - peek: O(1)
 * 
 *  ** What I learned
 * 
 *     * how to implement stack
 *       (1) create POINTER -> to store space w/ dynamically-allocated array
 *       (2) record SIZE -> used for size and top value
 *       (3) record CAPACITY -> used for indicating when to resize (compared w/ size)
 * 
 *     * how to use size
 *       - push: assign new item at stackArr[size] and increase size (size++)
 *       - pop:  decrease size (size--)
 *       - access: get top value by stackArr[size - 1]
 *       => push AT SIZE <-> access BEFORE SIZE (size - 1)
 * 
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
        void resize() {
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
                resize();
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
        size_t getSize() {
            return this->size;
        }

        // check if stack is empty or not
        bool isEmpty() {
            if (this->size == 0) return true;
            return false;
        }
};