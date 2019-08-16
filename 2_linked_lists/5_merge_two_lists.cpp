/**
 *  Given two sorted singly linked lists, merge the two into one sorted list.
 * 
 *  * Solutions
 * 
 *    (1) merge sort: O(n + m) time, O(1) extra space
 *        -> use merge function for merging the two sorted lists
 * 
 *        (a) create new list (out-of-place)
 *            : merge two lists into new list (leave the original lists)
 * 
 *        (b) merge the original lists (in-place)
 *            : merge the two lists using the original lists
 *              -> idential code except for not creating new list and 
 *                 INSTEAD linking nodes
 * 
 *        (b++) improved version of (b) by using DUMMY NODE
 *              -> removes reptetitive code 
 *                 (merging the code for setting the head ptr & linking other nodes)
 *      
 *        (c) recursive version
 *            : merge the two lists using the original lists
 *              -> base case: when either one is empty
 *              -> recursive case: find smaller node of two and use that for start point
 *                                 -> connect merged result of the next nodes with that smaller node
 * 
 *     (2) insertion sort: O(n*m) time, O(1) extra space
 *         -> insert each element in one list into rightful place in other list
 *            (for each element, need to find its place in other list)
 * 
 * 
 *  ** What I learned
 * 
 *    ** use 3 pointers (very important!!)
 *       - need one pointer for new list position recording (lastMerged)
 *       - in addition to the two pointers traversing each lists: ptr1, ptr2
 *       => use total of 3 pointers (ptr1, ptr2, lastMerged)
 * 
 *    ** checking if input lists are empty
 *       : to merge two lists, we must first check 4 cases
 *         (both empty, only first one empty, only second one empty, both not empty)
 *         -> can merge two lists only for last case where both are not empty
 *         -> the rest 3 cases must be treated as exceptional cases
 *         => USE
 *            - if (!head1) return head2
 *            - if (!head2) return head1
 *         => this way, can root out 3 cases very clean and simply
 * 
 *    ** DUMMY NODE
 *      : a node made for the purpose of uniting (head assignment & linking rest of nodes)
 *        -> compare (1-b) solution w/ (1-b++) solution
 *           - separated head assignment and linking node (while loop)
 *             bcuz if not, lastMerged ptr would be null and there would be SEG FAULT for using (lastMerged->next)
 * 
 *      => use dummy node instead to avoid SEG FAULT when using same code (not needing to separate head case)
 *         and DELETE later
 * 
 *    ** merge sort CHECKING CONDITION
 *      : always use the following check method 
 *        -> don't forget to UPDATE the pointers!
 * 
 *          while (ptr1 || ptr2)
 *              if (!ptr2 || (ptr1 && ptr1->data < ptr2->data)) => insert ptr1's node
 *              else => insert ptr2's node
 * 
 *    ** one line condition check
 *       ex. newHead = (head1->data < head2->data) ? head1 : head2;
 *       -> very useful for cleaning up code,
 *          if there is nothing else than assignment after condition checking
 * 
 */

#include <bits/stdc++.h>
using namespace std;

/**
 *  (1-a) merge sort: create new list (out-of-place)
 */
Node* mergeTwoLists(Node* head1, Node* head2) {

     // exceptional cases: if any list is empty
    if (!head1) return head2;
    if (!head2) return head1;

    // set the new head node to smaller node of two heads
    Node* head = nullptr;
    if (head1->data < head2->data) {
        head = new Node(head1->data);
        head1 = head1->next;
    } else {
        head = new Node(head2->data);
        head2 = head2->next;
    }

    /** keep track of last node in merged sorted
     *  (need it to connect w/ the smaller node of the two lists)
     */ 
    Node* lastMerged = head;

    // merge the nodes in sorted order
    while (head1 || head2) {

        // link last merged node to smaller node
        if (!head2 || (head1 && head1->data < head2->data)) {
            lastMerged->next = new Node(head1->data);
            
            // update pointers
            lastMerged = lastMerged->next;
            head1 = head1->next;
        } else {
            lastMerged->next = new Node(head2->data);

            // update pointers
            lastMerged = lastMerged->next;
            head2 = head2->next;
        }
    }

    return head;
}

/** (1-b) merge sort: merge the original two lists (in-place)
 *      -> similar code to (a) code above
 */
Node* mergeTwoLists(Node* head1, Node* head2) {

    // exceptional cases: if any list is empty
    if (!head1) return head2;
    if (!head2) return head1;

    // set the new head node to smaller node of two heads
    Node* head = nullptr;
    if (head1->data < head2->data) {
        head = head1;
        head1 = head1->next;
    } else {
        head = head2;
        head2 = head2->next;
    }

    /** keep track of last node in merged sorted
     *  (need it to connect w/ the smaller node of the two lists)
     */ 
    Node* lastMerged = head;

    // merge the nodes in sorted order
    while (head1 || head2) {

        // link last merged node to smaller node
        if (!head2 || (head1 && head1->data < head2->data)) {
            lastMerged->next = head1;
            
            // update pointers
            lastMerged = lastMerged->next;
            head1 = head1->next;
        } else {
            lastMerged->next = head2;

            // update pointers
            lastMerged = lastMerged->next;
            head2 = head2->next;
        }
    }

    return head;
}

/** (1-b++) use DUMMY NODE to improve (b) code
 *        -> similar code to (b) code above
 */
Node* mergeTwoLists(Node* head1, Node* head2) {

    // if one list is empty, return non-empty list
    if (!head1) return head2;
    if (!head2) return head1;

    /** create dummy node
     *  to set head and link other nodes
     *  w/ same code (removes repetitive code)
     */ 
    Node* dummy = new Node(0);

    Node* lastMerged = dummy;
    while (head1 || head2) {
        if (!head2 || (head1 && head1->data < head2->data)) {
            lastMerged->next = head1;

            // update pointers
            lastMerged = lastMerged->next;
            head1 = head1->next;
        } else {
            lastMerged->next = head2;

            // update pointers
            lastMerged = lastMerged->next;
            head2 = head2->next;
        }
    }

    Node* head = dummy->next;
    delete dummy;
    return head;
}

/** (1-c) merge sort: recursive version
 *      -> similar code to all solutions above
 */
Node* mergeTwoLists(Node* head1, Node* head2) {

    // base case: return non-empty list
    if (!head1) return head2;
    if (!head2) return head1;

    /** recursive case: link smaller node to merged list
     *  -> find smaller node of the two to use as start point
     *     for merged link of other nodes to branch out from
     */ 
    if (head1->data < head2->data) {
        head1->next = mergeTwoLists(head1->next, head2);
        return head1;
    } else {
        head2->next = mergeTwoLists(head1, head2->next);
        return head2;
    }
}