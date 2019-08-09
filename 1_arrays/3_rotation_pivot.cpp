/**
 *  Given a sorted array shifted to the left or right, find the shifted offset k.
 *  (k is non-negative)
 * 
 *  * Solutions
 * 
 *    (1) linear search: O(n)
 *        (a) find point where (before > after; goes against increasing order)
 *        (b) find smallest value's index
 * 
 *    (2) binary search: O(log n)
 *        - use two pointer technique to keep a range
 *        1. FIRST check (v[start] < v[end]) -> no rotation or shift => return 0
 *        2. search for (v[mid] > v[mid + 1]); point which goes against ascending order)
 *          -> return (mid + 1) bcuz that is the smallest value (= shifted offset)
 *          -> cut the range into half by COMPARING START VALUE w/ MID VALUE: (start ~ mid-1) | (mid+1 ~ end)
 *             -> if (v[start] > v[mid]): pivot point in left side (left side goes against ascending order)
 *                else: pivot point in right side (right side " )
 * 
 * 
 *  ** What I learned
 * 
 *     - for this problem to work properly, 
 *       it must assume that the given sorted array does NOT HAVE DUPLICATES
 *       (bcuz if {1, 1, 1} -> shifted version == original version; problem does not make sense)
 *          
 *     ** find offset == FIND SMALLEST VALUE'S INDEX
 * 
 *     ** BINARY SEARCH to find PIVOT
 *        - check if there is rotation at all: (v[start] < v[end]) => return 0
 *        - binary search to find (v[mid] > v[mid+1]) point => return (mid+1)
 *        - cut range in half by comparing (v[start] > v[mid]) => search left
 *                                         (v[start] < v[mid]) => search right
 *        cf) two pointer technique for ranging: while (start < end)
 *            => binary search when there are at least two elements
 * 
 *     ** left shift <-> right shift
 *        - left shift: check end -> begin
 *        - right shift: check begin -> end
 *        => left shift = (n - right shift) 또는 right shift = (n - left shift)를 사용하여
 *           INVERSE 방식으로 구할 수도 있다
 *  
 */

#include <bits/stdc++.h>
using namespace std;

/**
 *  (1-a) find left shifted offset - linear search
 */
int findLeftShift(vector<int> v) {

    // if no rotation, return 0 as offset
    if (*v.begin() < *(v.end()-1)) {
        return 0;
    }

    // count offset from end of array
    int count = 1;
    for (auto it = v.end() - 1; it != v.begin(); it--) {
        /** if element before goes against increasing order,
         *  current element (*it) is the original first element
         */ 
        if (*(it - 1) > *it) {
            break;
        }
        count++;
    }
    return count;
}

/**
 *  (1-b) find right shifted offset - linear search
 *        (== find smallest value's index)
 */
int findRightShift(vector<int> v) {

    int min_index = 0;
    int min = v[min_index];

    for (int i = 0, n = v.size(); i < n; i++) {
        if (min > v[i]) {
            min = v[i];
            min_index = i;
        }
    }
    return min_index;
}

/**
 *  (2) find right shifted offset - binary search
 */
int findRightShift(vector<int> v) {

    int start = 0;
    int end = v.size() - 1;

    if (v.size() <= 1 || v[start] < v[end]) {
        return 0;
    }

    /** binary search to find point: (before > after)
     *  -> use two pointers to keep a range
     */ 
    while (start < end) {

        /** check if mid point is the last element
         *  (mid always smaller value of two elements -> compare mid and mid+1 )
         */ 
        int mid = (start + end) / 2;
        if (v[mid] > v[mid + 1]) {
            return mid + 1;
        }

        /** cut the range in half
         *  (compare mid value w/ start value)
         */ 
        if (v[start] > v[mid]) {
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }
    /** if only one element remaining in range, 
     *  that element is the last value in vector
     */
    return start + 1;
}