/**
 *  Given an array, rotate the array to the right by k steps.
 *  (k is non-negative)
 * 
 *  * Solutions
 *    
 *    (1) brute-force method: O(n * k) time, O(1) space
 *        -> rotate one-by-one for k times
 * 
 *    (2) use extra array: O(n) time, O(n) space
 *        -> store rotated version and copy that into original array
 * 
 *    (3) cyclic replacement: O(n) time, O(1) space
 *        -> direcly place every item in its rightfully rotated position + cycle checking
 *        => use PREV + TEMP + use START (for checking cycles)
 *        
 *           - place item in rotated position while temporarily storing original item value
 *             -> use as next item to store
 *           - need to check for CYCLES
 *             ex. {1, 2, 3, 4, 5, 6}, k = 2 와 같은 경우, 같은 item이 중복 저장될 수 있음 bcuz of cycle
 *             => use START to store initial index to check for cycles 
 * 
 *    (4) use reverse: O(n) time, O(1) space
 *        -> reverse entire array and then reverse parts
 *           (take advantage of helper functions: reverse & swap)
 *           - first, reverse entire array
 *           - then, reverse first k elements
 *           - finally, reverse remaining elements
 *        
 * 
 *  ** What I learned
 * 
 *     ** SHIFTING ITEMS BY 1
 *        - use PREVIOUS value to store into current index
 *          -> prev initialized to LAST item's value
 *        - use TEMP value to temporarily store value at current index
 *          -> use later to update prev value
 * 
 *          int prev = arr[arr.size() - 1];
 *          for (int i = 0; i < arr.size(); i++) {
 *              int temp = arr[i];
 *              arr[i] = prev;
 *              prev = temp;
 *          }
 * 
 *        => use PREV & TEMP
 * 
 *     2) shifting RIGHT <-> LEFT
 *        - RIGHT: last k items come to front
 * 
 *        - LEFT: front k items come to last
 * 
 *        => 계속 틀리는 부분이니 조심할 것!
 * 
 *     3) careful w/ INDEXING
 *        -> (i - k) might end up to be negative and be erroneous
 * 
 *        => use (i + k) instead!
 * 
 */

#include <bits/stdc++.h>
using namespace std;

/**
 *  (1) brute-force method: O(n * k) time, O(1) space
 */
void rotate(vector<int>& nums, int k) {
        
        // for k times,
        for (int i = 0, size = nums.size(); i < k; i++) {

            // set prev to last num in array
            int prev = nums[size - 1];

            // rotate the array by one
            for (int j = 0; j < size; j++) {

                // temporarily store num at current index
                int temp = nums[j];

                // set the current index to prev num
                nums[j] = prev;

                // update prev num w/ temporarily stored num
                prev = temp;
            }
        }
    }

/**
 *  (2) use extra array: O(n) time, O(n) space
 */
void rotate(vector<int>& nums, int k) {
    
    // create extra array to store 
    vector<int> rotated(nums.size());
        
    // create rotated array
    for (int i = 0, size = nums.size(); i < size; i++) {
        rotated[(i + k) % size] = nums[i];
    }

    // copy rotated version into original array
    for (int i = 0; i < nums.size(); i++) {
        nums[i] = rotated[i];
    }
}

/**
 *  (3) cyclic replacement: O(n) time, O(1) space
 */
void rotate(vector<int>& nums, int k) {

    // curIndex = nums[0] value's rotated position
    int curIndex = k % nums.size();
    int startIndex = curIndex;
    int prevNum = nums[0];

    // replace elements (nums.size() times)
    int count = nums.size();
    while (count--)     {

        /** put prev item in rotated position
         *  (temporarily store original item to update prev later)
        */
        int temp = nums[curIndex];
        nums[curIndex] = prevNum;

        // update prev item value
        prevNum = temp;

        // update index to next rotated position
        curIndex = (curIndex + k) % nums.size();

        // if next position is cycle
        if (curIndex == startIndex) {

            // store next position's item in prev
            prevNum = nums[(curIndex + 1) % nums.size()];

            // update index to prev's new rotated position
            curIndex = (curIndex + k + 1) % nums.size();

            // update start for checking new cycle
            startIndex = curIndex;
        }
    }
}

/**
 *  (4) use reverse: O(n) time, O(1) space
 *      (use helper functions: reverse & swap)
 */
void rotate(vector<int>& nums, int k) {
    k = k % nums.size();
        
    // reverse entire array
    reverse(nums, 0, nums.size() - 1);
        
    // reverse array in range (0 - k]
    reverse(nums, 0, k - 1);
        
    // reverse array in range (k - end)
    reverse(nums, k, nums.size() - 1);
}

/**
 *  cf) use STL rotate function (if possible)
 */
void rotate(vector<int>& nums, int k) {

    // rotate to the left by (size - k)
    rotate(nums.begin(), nums.begin() + nums.size() - k, nums.end());
}
    