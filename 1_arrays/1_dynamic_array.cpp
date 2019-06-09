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

class DynamicArr {
private:
    int *arr;
    size_t size;
    size_t capacity;

public:
    DynamicArr(size_t capacity) {
        this->size = 0;
        this->capacity = capacity;
    }
    int getValueAtIndex(size_t index) {
        return arr[index];
    }
    void setValueAtIndex(size_t index, int value) {
        if (index >= capacity) {
            throw invalid_argument("index out of boundary");
        }
        arr[index] = value;
    }
    void pushBack(int value) {
        if (size == capacity) {
            resize();
        }
        arr[size++] = value;
    }
    void remove(size_t index) {
        if (index >= capacity || index < 0) {
            throw invalid_argument("index out of boundary");
        }
        for (int i = index + 1; i < size; i++) {
            arr[i - 1] = arr[i];
        }
    }
    void resize() {
        this->capacity *= 2;
        int *tempArr = new int[capacity];
        for (int i = 0; i < size; i++) {
            tempArr[i] = arr[i];
        }
    }
    size_t getSize() {
        return this->size;
    }
};