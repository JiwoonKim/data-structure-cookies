/**
 *  Given an array of integers, find the min and max value respectively.
 * 
 *  * Solutions
 * 
 *    (1) greedy algorithm: O(n) time, O(1) space
 *        -> iterate over each item while keeping track of min and max value so far
 * 
 *    (2) sort: O(n log n) time, O(n) or O(1) time
 *        -> sort the entire array and return the first and last value
 * 
 *    (3) STL min_element & max_element: O(n) time, O(1) space
 *        -> use STL functions to find ITERATOR of each
 * 
 * 
 *  ** What I learned: 
 * 
 *     ** bonus: kth min & max
 *        (1) greedy algorithm: O(n) time, O(k) space
 *            - iterate over each item and keep track of k min and k max values so far
 * 
 *        (2) sort: O(n log n) time, O(n) or O(1) space
 *            - sort all of the items and return the v[k - 1] and v[n - k - 1]
 *   
 */

#include <bits/stdc++.h>
using namespace std;

/**
 *  (1) greedy algorithm
 */
pair<int, int> findMinMax(vector<int> v) {

    // keep track of min and max value so far
    int min_val = v[0];
    int max_val = v[0];

    // iterate over items and update min and max
    for (auto x : v) {
        min_val = min(min_val, x);
        max_val = max(max_val, x);
    }

    return make_pair(min_val, max_val);
}

/**
 *  (2) sort
 */
pair<int, int> findMinMax(vector<int> v) {

    sort(v.begin(), v.end());
    return make_pair(v[0], v[v.size() - 1]);
}

/**
 *  (3) STL min_element & max_element
 */
pair<int, int> findMinMax(vector<int> v) {

    // find the iterators for min and max values
    auto minIt = min_element(v.begin(), v.end());
    auto maxIt = max_element(v.begin(), v.end());

    return make_pair(*minIt, *maxIt);
}