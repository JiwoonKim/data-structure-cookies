/**
 *  Given an array, rotate the array to the right by k steps.
 *  (k is non-negative)
 * 
 *  * Solutions
 *    
 *    (1) brute-force method: O(n * k) time, O(1) space
 *        - rotate one-by-one for k times
 * 
 *    (2) 
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
    vector<int> rotated;
        
    /** recalculate k (relative to the array size)
     *  to prevent errors in indexing
    */ 
    k = k % nums.size();

    // put last k items into beginning of array
    rotated.insert(rotated.begin(), nums.begin() + nums.size() - k, nums.end());

    // put remaining items into end of array
    rotated.insert(rotated.begin() + rotated.size(), nums.begin(), nums.begin() + nums.size() - k);
        
    // reassign array
    nums = rotated;
}

/**
 *  (3) 
 */
void rotate(vector<int>& nums, int k) {

}

/**
 *  (4) use STL rotate function
 */
void rotate(vector<int>& nums, int k) {

    // rotate to the left by (size - k)
    rotate(nums.begin(), nums.begin() + nums.size() - k, nums.end());
}
    