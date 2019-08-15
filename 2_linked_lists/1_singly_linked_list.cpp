/**
 *  Implement a singly linked list
 * 
 *  * Singly Linked list
 *    : sequence of nodes linked together
 *      -> can only traverse in one direction
 * 
 *    - append/prepend: O(1) 
 * 
 *    - lookup: O(n) -> linear search

 *    - delete: O(1) for HEAD & O(n) for others
 *      -> delete head: O(1)
 *      -> delete in-between nodes or tail: O(n) (bcuz linear search included)
 * 
 *    - length: O(n) -> linear search
 * 
 * 
 *  ** What I learned
 * 
 *     ** DELETION
 *        - first, CHECK if given number is IN RANGE of list (1 <= n <= length of list)
 *          (making sure that traversing does not accidently access out of boundary (preventing seg faults))
 *        - delete node based upon whether it is head or node:
 * 
 *        (1) delete HEAD node
 *            - delete head node and update head to new node (make sure not to lose rest of list in the process)
 * 
 *        (2) delete OTHER nodes (in-between nodes or tail node)
 *            - traverse to the node BEFORE
 *            - link the BEFORE node w/ the NEXT node
 *            - finally, delete the node given (before->next)
 * 
 *     ** SEARCH
 *        - number of hops = n - 1 (n = number of node to find)
 *          -> based on the assumption that node number: 1 ~ n (0 == list is empty)
 * 
 *        => remember to CHECK HOW MANY HOPS to arrive at given node
 *           (based on whether node number starts from 0 or 1)
 *           -> careful especially when TRAVERSING NODES based on hops
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
        Node* next = nullptr;

        Node(int data) {
            this->data = data;
            this->next = nullptr;
        }
};

/**
 *  define class for singly linked list
 */
class SinglyLinkedList {
    public: 
        Node* head;

        //  constructor method
        SinglyLinkedList() {
            this->head = nullptr;
        }

        // insert an element at the start of the linked list
        void insertAtHead(int data) {

            // insert new node at front
            Node* newNode = new Node(data);
            newNode->next = this->head;

            // update new head
            this->head = newNode;
        }

        // insert an element at the end of the linked list
        void insertAtTail(int data) {

            // create new node
            Node* newNode = new Node(data);
            
            // if list is empty, insert at head
            if (!this->head) {
                this->head = newNode;
            } else {
                // if not empty, traverse to last node and insert
                Node* current = this->head;
                while (current->next) {
                    current = current->next;
                }
                current->next = newNode;
            }
        }

        // search the value of index-th node in list
        int lookupNthValue(int n) {

            // throw error for wrong input
            if (n <= 0 || n > this->length()) {
                throw invalid_argument("list is either empty or has less nodes than given input");
            }

            // traverse to index-th node in list
            Node* current = this->head;
            int hopsLeft = n - 1;
            while (hopsLeft--) {
                current = current->next;
            }
            // return the index-th node's value
            return current->data;
        }

        // delete node at index
        void deleteNthNode(int n) {

            // throw error for wrong input
            if (n <= 0 || n > this->length()) {
                throw invalid_argument("list is either empty or has less nodes than given input");
            }

            // if deleting head node, 
            if (n == 1) {
                // delete head node and update new head ptr
                Node* newHead = this->head->next;
                delete this->head;
                this->head = newHead;
                
                // terminate method
                return;
            }

            // traverse to (index - 1)th node
            int hopsLeft = n - 2;
            Node* before = this->head;
            while (hopsLeft--) {
                before = before->next;
            }

            // delete index-th node
            Node* nextNode = before->next->next;
            delete before->next;
            before->next = nextNode;
        }

        // return length of list (= number of nodes)
        size_t length() {
            size_t count = 0;

            Node* current = head;
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