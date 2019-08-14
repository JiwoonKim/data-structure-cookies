/**
 *  Implement a dynamic array
 * 
 *  * Dynamic Array
 *    : flexible array (resizable/mutable)
 *      -> based on dynamically-allocated arrays
 *      => a.k.a VECTOR in C++ STL
 * 
 *    - append: amortized O(1) 
 *              -> worst-case O(n) bcuz of copying elements
 *    - lookup: O(1) 
 *              -> random access (by index)
 *    - insert: O(n)
 *              -> need to scoot elements
 *    - delete: O(n)
 *              -> need to scoot elements
 * 
 *  ** What I learned
 * 
 *     * how to define dynamic array (using 'new')
 * 
 *     * how to SCOOT ELEMENTS
 *       - when scooting elements to the RIGHT (for insertion)
 *         -> start from end of array to position
 *         -> use arr[i] = arr[i - 1] or arr[i + 1] = arr[i]
 * 
 *       - when scooting elements to the LEFT (for deletion)
 *         -> start from position to end of array
 *         -> use arr[i] = arr[i + 1] or arr[i - 1] = arr[i]
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

    // constructor method
    DynamicArr(size_t capacity) {
        arr = new int[capacity];
        this->size = 0;
        this->capacity = capacity;
    }

    // return value at index
    int valueAt(size_t index) {
        if (index >= capacity) {
            throw invalid_argument("index out of boundary");
        }
        return arr[index];
    }

    // push value to end of array (append)
    void pushBack(int value) {
        if (size == capacity) {
            resize();
        }
        arr[size++] = value;
    }

    // insert value at index
    void insertAt(size_t index, int value) {
        if (index >= capacity || index < 0) {
            throw invalid_argument("index out of boundary");
        }
        if (size == capacity) {
            resize();
        }
        for (int i = size - 1; i >= index; i--) {
            arr[i + 1] = arr[i];
        }
        arr[index] = value;
        size++;
    }

    // remove value at index (shift items to fill blank space)
    void removeAt(size_t index) {
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
        arr = tempArr;
    }

    // return the number of items in the array
    size_t arraySize() {
        return this->size;
    }
};