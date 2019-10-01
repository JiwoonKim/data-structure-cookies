/** 
 *  Implement a trie using a dynamic allocated array
 * 
 *  * Trie
 *    : array in LIFO order
 *      -> can only access top value
 * 
 *    - push: amortized O(1) 
 *            -> worst case O(n) bcuz need to resize
 *    - pop: O(1) 
 *    - peek: O(1)
 * 
 *  * Solution
 * 
 *  ** What I learned
 * 
 * 
*/

#include <bits/stdc++.h>
using namespace std;

/**
 *  define trie node
 */
class TrieNode {
    public:
        bool isEnd;
        TrieNode* children[26];

        // constructor method
        TrieNode() {
            this->isEnd = false;
            for (int i = 0; i < 26; i++) {
                this->children[i] = nullptr;
            }
        }
};

class Trie {
    public:
        TrieNode* root;

        Trie() {
            this->root = nullptr;
        }
};