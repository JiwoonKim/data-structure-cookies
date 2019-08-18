/**
 *  Implement a queue using a dynamic array
 * 
 *  * 
 * 
 *  ** What I learned
 * 
*/

#include <bits/stdc++.h>
using namespace std;

/**
 *  define class for queue
 */
class Queue {
    private:
        int* queueArr;
        int front, back;
        size_t size;
        size_t capacity;

    public:
        Queue(size_t capacity) {
            this->queueArr = new int[capacity];
            this->front = 0;
            this->back = 0;
            this->size = 0;
            this->capacity = capacity;
        }

        void enqueue(int value) {

        }

        void dequeue() {

        }

        int front() {

        }

        int back() {

        }

        size_t getSize() {
            return this->size;
        }

        bool isEmpty() {
            if (this->size == 0) return true;
            return false;
        }
};