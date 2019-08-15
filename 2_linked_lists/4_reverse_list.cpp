/**
 *  Given a linked list, reverse the list.
 * 
 *  * Solutions
 * 
 *    * Reverse Singly linked list
 * 
 *      (1) swap front to back values (in-place): O(n^2) time, O(1) extra space
 *          -> CHANGE DATA in each node by swapping 1st node w/ last node
 *          -> for each node, find it's reversed node and swap data
 * 
 *      (2) reverse ptr directions (in-place): O(n) time, O(1) extra space
 *          -> CHANGE PTR directions of each node
 *          -> keep track of before, current, after ptrs
 *          -> make sure to start (before = nullptr)
 * 
 *      (3) use stack to create new list (out-of-place): O(n) time, O(n) extra space
 *          -> use stack to record the values backwards
 *          -> create new list based on the stack
 * 
 * 
 *    * Reverse Doubly linked list
 * 
 *      (1) swap front to back values (in-place): O(n) time, O(1) extra space
 *          (same as (1) solution for singly linked list
 *           BUT less time consuming bcuz can move backwards in doubly linked list)
 *          -> use left and right pointer to swap values until mid point
 *          -> traverse right ptr to last node and move to prev node after swap
 * 
 *      (2) swap prev & next pointers: O(n) time, O(1) extra space
 *          -> swap prev & next ptrs of each node
 *             (same as (2) solution for singly linked list
 *              BUT less complicated since don't need to keep track of before nodes)
 *          -> don't forget to set head ptr to last node in the end
 * 
 *      (3) use stack to create new list: O(n) time, O(n) extra space
 *          (same as (3) solution for singly linked list)
 * 
 * 
 *  ** What I learned
 * 
 *     ** CHANGING linked list IN-PLACE means
 *        : either
 *          - change the node's VALUES or
 *          - change the node's POINTERS' DIRECTIONS
 * 
 *     * reversing singly linked list
 *       : most efficient way is to reverse the ptrs!
 *         -> make sure to start before ptr to nullptr in beginning!
 * 
 *     * reversing doubly linked list
 *       : most efficient way is to either swap values or reverse ptrs!
 *  
 */

#include <bits/stdc++.h>
using namespace std;

1. Reverse Singly Linked List

/**
 *  (1) swap front to back values (in-place)
 */
Node* reverseSinglyLinkedList(Node* head) {
    
    if (!head) {
        throw invalid_argument("list is empty");
    }

    // find length of list
    int length = 0;
    Node* current = head;
    while (current) {
        length++;
        current = current->next;
    }

    // reverse values in list by swapping front and back values
    current = head;
    for (int i = 1, mid = length / 2; i <= mid; i++) {

        // find the corresponding opposite node
        Node* opposite = head;
        for (int j = length - i; j > 0; j--) {
            opposite = opposite->next;
        }

        // swap values of the two nodes
        int temp = current->data;
        current->data = opposite->data;
        opposite->data = temp;

        // update current node
        current = current->next;
    }

    return head;
}

/**
 *  (2) reverse ptr directions (in-place)
 */
Node* reverseSinglyLinkedList(Node* head) {
    
    if (!head) {
        throw invalid_argument("list is empty");
    }

    // reverse the pointer directions
    Node* beforeNode = nullptr;
    Node* current = head;
    while (current) {
        // temporarily store next node
        Node* nextNode = current->next;

        // reverse ptr direction of current node
        current->next = beforeNode;

        // update before and current ptrs
        beforeNode = current;
        current = nextNode;
    }

    // return new head ptr
    return beforeNode;
}


/** 
 *   (3) use stack (out-of-place)
 */
Node* reverseSinglyLinkedList(Node* head) {

    if (!head) {
        throw invalid_argument("list is empty");
    }

    // store node values in stack
    stack<int> stack_;
    Node* current = head;
    while (current) {
        stack_.push(current->data);
        current = current->next;
    }

    // set head ptr to first reversed node
    head = new Node(stack_.top());
    stack_.pop();

    // create reversed order of nodes and link each other
    current = head;
    while (!stack_.empty()) {
        Node* newNode = new Node(stack_.top());
        stack_.pop();
        current->next = newNode;
        current = current->next;
    }

    // return head ptr of reversed list 
    return head;
}


2. Reverse Doubly Linked List

/**
 *  (1) swap front to back values (in-place)
 */
Node* reverseDoublyLinkedList(Node* head) {

    if (!head) {
        throw invalid_argument("list is empty");
    }

    // create two pointers
    Node* left = head;
    Node* right = head;

    // move right ptr to last node
    while (right->next) {
        right = right->next;
    }

    // swap values until mid point
    while (left != right && left->prev != right) {

        // swap values
        int temp = left->data;
        left->data = right->data;
        right->data = temp;

        // move ptrs inwardly
        left = left->next;
        right = right->prev;
    }

    return head;
}

/**
 *  (2) swap prev and next pointers (in-place)
 */
Node* reverseDoublyLinkedList(Node* head) {

    if (!head) {
        throw invalid_argument("list is empty");
    }

    // swap each nodes' prev & next ptr
    Node* current = head;
    while (current) {

        // update head ptr if last node
        if (!current->next) {
            head = current;
        }

        // swap ptrs
        Node* temp = current->prev;
        current->prev = current->next;
        current->next = temp;

        // update current ptr
        current = current->prev;
    }

    return head;
}