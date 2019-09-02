/**
 *  Given a string, create all the possible permutations
 *  (the string may contain duplicate chars)
 * 
 *  * Solutions:
 * 
 *    (1) backtracking
 * 
 *    (2) 
 * 
 * 
 * 
 *  ** What I learned
 * 
 *     ** permutations <-> substring, subsequence
 *        - permutation: REARRANGEMENT of ORDER of characters
 *        - substring, subsequence: must FOLLOW char ORDER in original string
 *          -> substring: cannot take out middle chars (ex. "abc" -> "ac" X)
 *          -> subsequence: can take out middle chars (ex. "abc" -> "ac" possible)
 * 
*/

#include <bits/stdc++.h>
using namespace std;

/**
 *  
 */
vector<unordered_set<string>> all_k_permutations(string s) {
    
}

/**
 *  (2) k-substrings of all permutations
 */
vector<unordered_set<string>> all_k_permutations(string s) {

    /** 
     *  k_permutation[i] = all possible i-length string permutations
     */ 
    vector<unordered_set<string>> permutations(s.length() + 1);
    
    // start from very first permutation order
    sort(s.begin(), s.end());

    /** create all full-length string permutations 
     *  (length == s.original lengths)
     */ 
    do {
        /** for each permutations, 
         *  cut k-lengths from beginning to create nPk permutations
         */
        for (int k = 1, n = s.length(); k <= n; k++) {
            string k_len_str = s.substr(0, k);
            
            // 
            permutations[k].insert(k_len_str);
        }
    } while (next_permutation(s.begin(), s.end()));
}