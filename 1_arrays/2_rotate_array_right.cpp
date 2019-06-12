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
 *    (3) 
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

    int count = nums.size();

    int curIndex = k % nums.size();
    int startIndex = curIndex;
    int prevNum = nums[0];

    while (count--)     {

        int temp = nums[curIndex];
        nums[curIndex] = prevNum;
        prevNum = temp;

        curIndex = (curIndex + k) % nums.size();
        if (curIndex == startIndex)         {
            curIndex = (curIndex + 1) % nums.size();
            prevNum = nums[curIndex];
            curIndex = (curIndex + k) % nums.size();
            startIndex = curIndex;
        }
    }
}

/**
 *  cf) use STL rotate function (if possible)
 */
void rotate(vector<int>& nums, int k) {

    // rotate to the left by (size - k)
    rotate(nums.begin(), nums.begin() + nums.size() - k, nums.end());
}
    