/**
 *  Calculate the height of the given binary tree.
 *  (a single node in the tree has height of 0)
 * 
 *  * Height
 * 
 *    
 * 
 *  ** What I learned
 *  
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