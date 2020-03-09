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
 *        (1) divide into k slots (size of n/k each)
 * 
 *        (2) simulate linked list:
 *            - track top[] (k-size array): top index for each stack
 *              -> initialized all to -1 to indicate empty stack)
 *            - track link[] (n-size array): 
 *              - if array[i] is used, link[i] = points to index of previous value in stack
 *                not used, link[i] = points to index of next freed available space
 *              => linking prev values helps to track down previous top value in stack when pop()
 *                 linking next values (free) helps to update next free space after push()
 *                 (especially, useful in cases of pop->push since next values can track
 *                  both the new freed space and free space after that (= free before))
 *              -> initialized all to next index: link[i] = i++ (link[n-1] = 0)
 *            - track free: next free space for any stack to use
 * 
 *            * push(n, x): push x to stack n
 *              -> insert element to array: array[free index] = x
 *              -> temporarily store: nextFree = link[free index]
 *              -> create link to prev top: link[free index] = top[n] 
 *              -> update stack n's top: top[n] = free index
 *              -> update free to new space: free index = nextFree
 * 
 *            * pop(n): pop from stack n
 *              -> temporarily store: newTop = link[top[n]]
 *              -> current top, which will become new free space, should have link to current free space
 *                 (so that even after re-filling current top's space, we don't have to tediously search
 *                  for the next free space since we keep the current free space as next free space :) )
 *                 : link[top[n]] = free
 *              -> free current top space: free = top[n]
 *              -> update top to value before: top[n] = newTop
 * 
 *            ex. stack1 = 1,2 : stack2 = 3, 4
 *                push(1, 1) -> push(2, 3) -> push(1, 2) -> pop(1) -> push(2, 4)
 * 
 *            start:     array[0,0,0,0,0] : link[1,2,3,4,0]   : top[1] = -1, top[2] = -1 : free = 0
 *            push(1,1): array[1,0,0,0,0] : link[-1,2,3,4,0]  : top[1] = 0, top[2] = -1  : free = 1
 *            push(2,3): array[1,3,0,0,0] : link[-1,-1,3,4,0] : top[1] = 0, top[2] = 1   : free = 2
 *            push(1,2): array[1,3,2,0,0] : link[-1,-1,0,4,0] : top[1] = 2, top[2] = 1   : free = 3
 *            pop(1):    array[1,3,2,0,0] : link[-1,-1,3,4,0] : top[1] = 0, top[2] = 1   : free = 2
 *            push(2,4): array[1,3,4,0,0] : link[-1,-1,1,4,0] : top[1] = 0, top[2] = 2   : free = 3
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
            for (int i = 0; i < top1; i++) {
                temp[i] = arr[i];
            }
            for (int i = size * 2; i > top2; i--) {
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