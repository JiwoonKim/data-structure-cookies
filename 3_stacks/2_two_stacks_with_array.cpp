/**
 *  Implement two stacks using a single array.
 * 
 *  * Solution
 * 
 *    (1) divide the space in two halves: all operations take O(1)
 *        -> divide the array space in half
 *        -> use first half for stack1, and the second half for stack2
 * 
 *    (2) start from opposite ends: all operations take O(1)
 *        -> start each stack from the extreme ends of the array
 *        => space efficient bcuz it utilizes all of the available space (flexible in space usage)
 *           (if stack1 is smaller than stack2, stack2 simply uses more of the array space,
 *            so more space efficient than (1) solution
 * 
 * 
 *  ** What I learned
 * 
 *     ** Implement k stacks in one array (extended question)
 *        
 *        (1) divide into k slots
 * 
 *        (2) 
 * 
*/

#include <bits/stdc++.h>
using namespace std;

/**
 *  (2) start from opposite ends
 */
class twoStacks {

    private:
        int size;
        int* arr;
        int top1, top2;
    
    public:
        // constructor method
        twoStacks(int n) {
            size = n;
            arr = new int[size];
            top1 = -1;
            top2 = n;
        }

        // resize array space
        void resize() {
            size = size * 2;
            int* temp = new int[size];
            for (int i = 0; i < size; i++) {
                temp[i] = arr[i];
            }
            delete arr;
            arr = temp;
        }
    
        // push operation methods
        void push1(int value) {
            if (top1 + 1 >= top2) {
                resize();
            }
            arr[++top1] = value;
        }
    
        void push2(int value) {
            if (top2 - 1 <= top1) {
                resize();
            }
            arr[--top2] = value;
        }

        // pop operation methods
        int pop1() {
            if (top1 == -1) return -1;
            return arr[top1--];
        }

        int pop2() {
            if (top2 == size) return -1;
            return arr[top2++];
        }
};