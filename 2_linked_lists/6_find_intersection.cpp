/**
 *  Given two singly linked lists, find intersection point.
 *  (if the two lists do not merge at any point, return null)
 * 
 *  * Solutions
 * 
 *    (1) brute force: O(n*m) time, O(1) extra space
 *        -> for each node in list1, check if in list2
 * 
 *    (2) hash table: O(n + m) time, O(n) or O(m) extra space
 *        -> create record of visited nodes (list1's nodes)
 *        -> check if overlapping nodes in list2
 * 
 *    (3) two pointer + length difference advantage: O(n + m) time, O(1) extra space
 *        -> find length of each list and calculate the difference
 *        -> set the pointer of longer list at position (head + length difference)
 *        -> traverse the two pointers by 1 (equal speed) and find where they meet
 * 
 *    (4) cross traverse two pointers: O(n + m) time, O(1) extra space
 *        -> traverse two pointers until two pointers meet or both reach end
 *        => KEY: traversing the two pointer for same length: (n + m)
 * 
 * 
 *  ** What I learned
 * 
 *    ** key is in LENGTH DIFFERENCE
 *       - if two lists had same length -> can find intersection w/ two pointer traversing by 1
 *       - problem arises when the two lists have different lengths
 *         -> traversing the list by 1 does not work anymore
 *         -> SO INSTEAD, make the two lists have the SAME LENGTH
 *                        by making each of the ptrs also TRAVERSING ON OPPOSITE COURSES as well
 *            THAT IS, the ptr1 runs on (m + n) nodes & ptr2 runs on (n + m) nodes
 *                     (when one reaches list's end -> move to head of other list)
 *         => this way, you can eliminate the problem of having different length
 *                      and find intersection point by traversing each pointer by 1 (at same speed)
 *         => ARTIFICALLY create ILLUSION of SAME LENGTH course 
 *            for two pointers to traverse by 1
 * 
 *    ** CHECK CONDITION (ptr1 != ptr2)
 *       - if intersection exists -> ptr1 == ptr2
 *       - if not -> both ptrs reach end of lists (nullptr == nullptr)
 *  
 */

#include <bits/stdc++.h>
using namespace std;

/**
 *  (1) brute-force method
 */
Node* findIntersection(Node* list1, Node* list2) {

    // for each node in list1, 
    Node* ptr1 = list1;
    while (ptr1) {
        // check if exists in list2 as well
        Node* ptr2 = list2;
        while (ptr2) {
            // if at intersection point,
            if (ptr1 == ptr2) {
                return ptr1;
            }
            // udate list2 ptr
            ptr2 = ptr2->next;
        }
        // update list1 ptr
        ptr1 = ptr1->next;
    }

    // if no intersection,
    return nullptr;
}

/**
 *  (2) use hash table
 */
Node* findIntersection(Node* list1, Node* list2) {

    // create set to record visited nodes
    unordered_set<Node*> visited;

    // traverse first list and record visited nodes
    Node* current = list1;
    while (current) {
        visited.insert(current);
        current = current->next;
    }

    // traverse second list and find intersection point
    current = list2;
    while (current) {
        if (visited.count(current) > 0) {
            return current;
        }
        current = current->next;
    }

    // if no intersection,
    return nullptr;
}

/**
 *  (3) two pointer + length difference advantage
 */
Node* findIntersection(Node* head1, Node* head2) {

    // find lengths of the two lists
    int length1 = head1->length();
    int length2 = head2->length();

    // set ptrs (for convenience)
    Node* longerPtr = (length1 > length2) ? head1 : head2;
    Node* shorterPtr = (length1 > lenght2) ?  head2 : head1;

    // give head start for longer list
    int diff = (length1 > length2) ? length1 - length2 : length2 - length1;
    while (diff--) {
        longerPtr = longerPtr->next;
    }
    
    /** traverse two pointers 
     *  until they meet or reach end of lists
     */ 
    while (shorterPtr != longerPtr) {
        shorterPtr = shorterPtr->next;
        longerPtr = longerPtr->next;
    }
    return shorterPtr;
}

/**
 *  (4) cross-traverse two pointers
 */
Node* findIntersection(Node* head1, Node* head2) {

    // create two pointers to traverse each list
    Node* ptr1 = head1
    Node* ptr2 = head2;

    /** traverse two pointers until they meet
     *  if itersection exists -> will meet at intersection point
     *  if not -> both ptrs will eventually reach end nullptr (==)
     */ 
    while (ptr1 != ptr2) {
        /** update pointers
         *  (if either pointer reached end of list,
         *  redirect it back to head of other list)
         */ 
        ptr1 = (ptr1 == nullptr) ? head2 : ptr1->next;
        ptr2 = (ptr2 == nullptr) ? head1 : ptr2->next;
    }

    /** if intersection exists -> ptr1 position == intersection point
     *  if not -> ptr1 & ptr2 reach end nullptr (=> return nullptr)
     */
    return ptr1; 
}