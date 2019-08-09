/**
 *  Given a vector, reverse the order of the items
 * 
 *  * Solutions
 * 
 *    (1) copy backwards: O(n) time, O(n) space
 *        -> simply run through array from end to start and copy into extra array
 * 
 *    (2) swap left and right: O(n) time, O(1) space
 *        -> use two pointer technique
 *        -> swap left and right item and repeat while moving the pointers inwardly
 * 
 *    (3) swap start and end recursively: O(n) time, O(n) space
 *        -> swap start and end items and recursive on remaining middle portion
 * 
 * 
 *  ** What I learned
 * 
 *     - check if in-place is possible
 *       (make absolutely sure that there is no possibility of using the original array)
 */

#include <bits/stdc++.h>
using namespace std;

/**
 *  (1) copy backwards
 */
vector<int> reverse(vector<int> v) {

    vector<int> reversed;
    for (int i = v.size() - 1; i >= 0; i--) {
        reversed.push_back(v[i]);
    }
    return reversed;
}

/** (2) swap left and right
 *      (using two pointer technique)
 */
void reverse(vector<int>& v) {

    int left = 0;
    int right = v.size() - 1;

    while (left < right) {
        swap(v[left], v[right]);
        left++;
        right--;
    }
}

/** 
 *  (3) swap start and end recursively
 */
void reverse(vector<int>& v, int beginIndex, int endIndex) {

    if (beginIndex >= endIndex) {
        return;
    }
    swap(v[beginIndex], v[endIndex]);
    return reverse(v, beginIndex + 1, endIndex - 1);
}

/** 
 *  helper function
 */
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}