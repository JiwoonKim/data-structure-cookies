/**
 *  Given an array and integer k, find a pair which sum equals k.
 * 
 *  * Solutions
 * 
 *    (1) brute-force: O(n^2) time, O(1) space
 *        -> for each element i, find the (k - i) in array
 * 
 *    (2) use hash table: O(n) time, O(n) space
 * 
 * 
 *  ** What I learned
 * 
 *     ** MAKE SURE to NOT selecting itself!!
 *        - have to check other value is not itself
 *        - beware of duplicates
 * 
 *     - for this problem to work, there must be two assumptions:
 *       1) each input would have exactly one solution
 *       2) cannot use the same element twice 
 *       => duplicates may exist but have only one solution pair
 * 
 *     ** optimization strategy
 *        - goal: improve the run time complexity of solution (1)
 *          -> need a MORE EFFICIENT WAY TO CHECK if the complement EXISTS IN THE ARRAY
 *          => need to REDUCE LOOK UP TIME!
 *        - solution: by trading space for time
 *          => use hash table to support FAST LOOK UP TIME to NEAR constant time
 * 
 */

#include <bits/stdc++.h>
using namespace std;

/**
 *  (1) brute-force
 */
unordered_map<int, int> findPairSum(vector<int> v, int k) {

    unordered_map<int, int> pairs;

    // for each element,
    for (int i = 0, n = v.size(); i < n; i++) {
        // find other element which sum equals k
        int complement = k - v[i];
        for (int j = 0; j < n; j++) {

            // if found a pair (and it is not itself)
            if (j != i && v[j] == complement) {
                pairs.insert(make_pair(v[i], v[j]));
            }
        }
    }

    return pairs;
}

/**
 *  (2) using hash table
 */
unordered_map<int, int>  findPairSum(vector<int> v, int k) {

    unordered_map<int, int> pairs;

    // iterate over each element
    unordered_set<int> notPairedYet;
    for (int x : v) {
        
        // check if pair of x exists in notPairedYet
        int complement = k - x;
        if (notPairedYet.count(complement) > 0) {
            pairs.insert(make_pair(x, complement));
        }
        // insert x into notPiaredYet to reference later
        notPairedYet.insert(x);
    }

    return pairs;
}