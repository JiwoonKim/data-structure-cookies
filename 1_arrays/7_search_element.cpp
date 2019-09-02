/**
 *  Given an array and target value k, check if k exists in the array.
 * 
 *  * Solutions
 *      
 *    (1) linear search: O(n) time, O(1) space
 *        -> works whether the array is sorted or not
 * 
 *    (2) binary search: O(log n) time, O(1) space
 *        -> works ONLY IF array is SORTED
 *        -> RECURSIVE VERSION & ITERATIVE VERSION
 * 
 *  ** What I learned
 * 
 *     ** make sure to check array is SORTED before using BINARY SEARCH!
 * 
 *     * memorize structure for binary search (both iterative & recursive)
 *       - use range (left <= right); EQUAL sign included for both versions
 *         -> if target value does not exist, the range will go out of bounds
 *       - put return false at end of code
 * 
 *       => if target value does not exist, left and right pointers will move out of bounds
 *          (left > right) so automatically stop loop or recursion
 *  
 */

#include <bits/stdc++.h>
using namespace std;

/**
 *  (1) linear search
 */
bool search(vector<int> v, int k) {

    // iterate over each element
    for (auto x : v) {
        // check if k exists in array
        if (x == k) {
            return true;
        }
    }
    // if k doesn't exist in array,
    return false;
}

/** (2-a) binary search: ITERATIVE version
 *        (based on assumption that array is sorted)
 */
bool search(vector<int> v, int k) {

    int left = 0;
    int right = v.size() - 1;
    while (left <= right) {
        // check the mid value
        int mid = (left + right) / 2;
        if (v[mid] == k) {
            return true;
        }
        // cut the range in half and continue searching
        if (k < v[mid]) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    // if k doesn't exist in array,
    return false;
}

/** (2-b) binary search: RECURSIVE version
 *        (based on assumption that array is sorted)
 */
bool search(vector<int> v, int left, int right, int k) {

    // check range is right
    if (left <= right) {
        // compare mid value w/ target k
        int mid = (left + right) / 2;
        if (v[mid] == k) {
            return true;
        }
        // cut the range in half and recursively call function
        if (k < v[mid]) {
            return search(v, left, mid - 1, k);
        } else {
            return search(v, mid + 1, right, k);
        }
    }
    // if out of range, 
    return false;
}