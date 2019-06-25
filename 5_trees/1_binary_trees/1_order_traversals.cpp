/**
 *  Given a binary tree, traverse the tree in preorder, inorder, postorder respectively.
 * 
 *  * Traversals: (pre, in, post) depending on when CURRENT NODE is printed/visited
 * 
 *    1) PRE-ORDER: current node -> left subtree -> right subtree
 *    2) IN-ORDER: left subtree -> current node -> right subtree
 *    3) POST-ORDER: left subtree -> right subtree -> current node
 * 
 *  ** What I learned
 *  
 *     * Don't have to check if left or right child node is null
 *       -> condition at beginning will check if child is null or not
 *          when called prOrder(root->left)
 * 
 *       => REMEMBER traversal 구조
 *          : if (root) {
 *              print current node's data
 *              order_function(root->left)
 *              order_function(root->right)
 *            }
 * 
 */

#include <bits/stdc++.h>
using namespace std;

/**
 *  traverse in PRE-ORDER
*/
void preOrder(Node* root) {

    if (root) {
        // print current node
        printf("%d ", root->data);

        /** traverse left and right child node
         *  (no need to check if root->left not null
         *   bcuz will check when function is called
         *   -> if (root) 부분에서 체크됨)
        */ 
        preOrder(root->left);
        preOrder(root->left);
    }
}

/**
 *  traverse in IN-ORDER
*/
void inOrder(Node* root) {

    if (root) {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

/**
 *  traverse in POST-ORDER
*/
void postOrder(Node* root) {

    if (root) {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->data);
    }
}