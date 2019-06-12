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
 *        - 
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
 *  (2) 
 */
void rotate(vector<int>& nums, int k) {
    
}