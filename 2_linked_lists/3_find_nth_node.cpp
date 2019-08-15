/**
 *  Given a singly linked list and integer n, return the n-th node's value
 * 
 *  * Solutions
 * 
 *    (1) linear search
 *        -> iterate over to n-th node
 *        
 *    cf) if problem is finding n-th last node,
 * 
 *        (1) find length and linear search: O(n) time, O(1) space
 *            -> first iterate over all nodes to find length of list
 *            -> then linear search for (length - n + 1)th node
 * 
 *        (2) n-wide stick approach (= linear search): O(n) time, O(1) space
 *            -> use two pointers apart by (n-1) nodes
 *            -> iterate until end pointer reaches last node
 *            -> the start pointer == n-th last node
 * 
 * 
 *  ** What I learned
 * 
 *  
 */

#include <bits/stdc++.h>
using namespace std;

/**
 *  .find the value of nth node (linear search)
 */
int findNthNodesValue(Node* head, int n) {

    // traverse the list until n-th node
    Node* current = head;
    int movesLeft = n - 1;
    while (current) {
        // if arrived at n-th node,
        if (movesLeft == 0) {
            return current->data;
        }

        // update ptr and moves left
        current = current->next;
        movesLeft--;
    }
    throw invalid_argument("given position is beyond list's length");
}

/**  find the value of nth last node
 *  .(n-wide stick approach)
 */
int findNthLastNodeValue(Node* head, int n) {
    
    // create a n-wide stick using two pointers
    Node* left = head;
    Node* right = head;
    int movesLeft = n - 1;
    while (movesLeft--) {
        /** throw error message to exceptional cases
         *  : no nodes at all -> check right (in beginning)
         *    or less nodes than n -> check right->next
        */
        if (!right || !right->next) {
            throw invalid_argument("given position is beyond list's length");
        } 
        right = right->next;
    }

    // move the n-wide stick until it reaches end of list
    while (right->next) {
        left = left->next;
        right = right->next;
    }
    return left->data;
}