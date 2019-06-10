/**
 *  Implement a dynamic array
 * 
 *  Time Complexity: O(
 *  Space Complexity: O(
 * 
 *  * What I learned:
 * 
 *    ** define class of dynamic array
 *       - take a good look at how a graph class is structured!
 *       - use it as reference /example for future
 * 
 */

#include <bits/stdc++.h>
using namespace std;

/**
 *  define class for dynamic array
 */
class DynamicArr {
private:
    int *arr;
    size_t size;
    size_t capacity;

public:

    // constructor function
    DynamicArr(size_t capacity) {
        arr = new int[capacity];
        this->size = 0;
        this->capacity = capacity;
    }

    // return value at index
    int getValueAtIndex(size_t index) {
        return arr[index];
    }

    // set value at index
    void setValueAtIndex(size_t index, int value) {
        if (index >= capacity) {
            throw invalid_argument("index out of boundary");
        }
        arr[index] = value;
    }

    // push value to end of array
    void pushBack(int value) {
        if (size == capacity) {
            resize();
        }
        arr[size++] = value;
    }

    // remove value at index (shift items to fill blank space)
    void removeValueAtIndex(size_t index) {
        if (index >= capacity || index < 0) {
            throw invalid_argument("index out of boundary");
        }
        for (int i = index + 1; i < size; i++) {
            arr[i - 1] = arr[i];
        }
        size--;
    }

    // resize array to twice the capacity
    void resize() {
        this->capacity *= 2;
        int *tempArr = new int[capacity];
        for (int i = 0; i < size; i++) {
            tempArr[i] = arr[i];
        }
    }

    // return the number of items in the array
    size_t getSize() {
        return this->size;
    }
};