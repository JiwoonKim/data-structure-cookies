/** 
 *  Implement a binary tree structure
 * 
 *  * Binary Tree
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
 *  define class for binary tree node
 */
class BinaryTreeNode {
    public: 
        int data;
        BinaryTreeNode* left;
        BinaryTreeNode* right;

        // constructor method
        BinaryTreeNode(int data) {
            this->data = data;
            this->left = nullptr;
            this->right = nullptr;
        }
};

/**
 *  define class for binary tree
 */
class BinaryTree {
    public: 
        BinaryTreeNode* root;

        // constructor method
        BinaryTree() {
            this->root = nullptr;
        }
};