/**
 *  Given an array of integers, find the min and max value respectively.
 * 
 *  * Solutions
 * 
 *    (1) greedy algorithm: O(n) time, O(1) space
 *        -> iterate over each item while keeping track of min and max value so far
 * 
 *    (2) sort: O(n log n) time, O(n) or O(1) time
 *        -> 
 * 
 * 
 *  ** What I learned
 * 
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