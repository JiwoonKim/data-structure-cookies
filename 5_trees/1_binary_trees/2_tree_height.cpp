/**
 *  Calculate the height of the given binary tree.
 *  (a single node in the tree has height of 0)
 * 
 *  * Terminology
 *    - Depth = length of the path from node to the root (number of edges)
 *    - Height = depth of deepest node in the tree from the root
 * 
 *  ** What I learned
 *  
 *     ** Find height of binary tree using RECURSION
 *        - BASE case: empty node -> return -1
 *        - RECURSIVE case: return (max of height of left and right node) + 1
 * 
 */ 

#include <bits/stdc++.h>
using namespace std;

/**
 *  calculate height of binary tree
*/
int getHeight(Node *root) {

    if (!root) {
        return -1;
    }
    return max(getHeight(root->left), getHeight(root->right)) + 1;
}