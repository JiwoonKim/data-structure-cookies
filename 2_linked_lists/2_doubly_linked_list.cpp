/**
 *  Implement a doubly linked list
 * 
 *  * Doubly Linked list
 *    : sequence of nodes linked together
 *      -> can traverse in both directions
 * 
 *    - append/prepend: O(1) 
 * 
 *    - lookup: O(n) -> linear search

 *    - delete: O(1) for HEAD & O(n) for others
 *      -> delete head: O(1)
 *      -> delete in-between nodes or tail: O(n) (bcuz linear search included)
 *      => MAIN DIFFERNCE w/ SLL: do not have to keep track of before node 
 *         (can access from end node's prev ptr)
 * 
 *    - length: O(n) -> linear search
 * 
 * 
 *  ** What I learned
 * 
 *     ** Deletion in Doubly linked list 
 *        -> more easier since don't need to keep track of node before
 *        -> just need to keep track of node to delete and use it's prev ptr
 *        (nevertheless, SLL와 DLL 복잡도는 동일: O(n) time & O(1) space)
 * 
 *     ** operations in Doubly linked list: need extra work
 *        -> a bit more work since need to also arrange the prev ptr as well
 *        => don't forget to change prev ptr when inserting & deleting
 * 
 */

#include <bits/stdc++.h>
using namespace std;

/**
 *  define class for node
 */
class Node {
    public:
        int data;
        Node* prev;
        Node* next;

        Node(int data) {
            this->data = data;
            this->prev = nullptr;
            this->next = nullptr;
        }
};

/**
 *  define class for doubly linked list
 */
class DoublyLinkedList {
    public:
        Node* head;

        // constructor method
        DoublyLinkedList() {
            head = nullptr;
        }

        // insert new node at head of list
        void insertAtHead(int data) {

            // create new node and link to list
            Node* newNode = new Node(data);
            newNode->next = this->head;

            /** if there are already nodes, 
             *  link next node's prev w/ new node
             */ 
            if (!this->isEmpty()) {
                this->head->prev = newNode;
            }

            // update new head
            this->head = newNode;
        }

        // insert new node at end of list
        void insertAtTail(int data) {

            // create new node
            Node* newNode = new Node(data);
            
            // if list is empty, insert at head
            if (this->isEmpty()) {
                this->head = newNode;
            } else {
                // if not empty, traverse to last node and insert
                Node* current = this->head;
                while (current->next) {
                    current = current->next;
                }
                current->next = newNode;
                newNode->prev = current;
            }
        }

        // delete node w/ given value
        bool deleteNodeOfValue(int data) {

            // if value is head node, delete head node
            if (this->head && this->head->data == data) {
                Node* newHead = this->head->next;
                delete head;
                this->head = newHead;
                this->head->prev = nullptr;
                return true;
            }
            // traverse to search for value
            Node* current = this->head;
            while (current) {
                // if value exists, delete it
                if (current->data == data) {
                    
                    // connect prev node's next ptr to next node
                    current->prev->next = current->next;

                    /** check if next node exists, 
                     *  (if so, connect next node's prev ptr to prev node
                     */ 
                    if (current->next) {
                        current->next->prev = current->prev;
                    }
                    delete current;
                    return true;
                }
                current = current->next;
            }
            // value does not exist in list
            return false;
        }

        // return length of list
        size_t length() {

            size_t count = 0;
            Node* current = this->head;
            while (current) {
                count++;
                current = current->next;
            }
            return count;
        }

        // check if list is empty or not
        bool isEmpty() {
            return !head;
        }
};