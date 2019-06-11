/**
 *  Check if linked list has cycle.
 * 
 *  * Two Runner Approach
 *    : use two pointers at different speeds to check if cycle exists
 * 
 *  ** What I learned
 * 
 *     * how to use TWO RUNNER APPROACH
 * 
 *       1) initialize both runners to HEAD
 * 
 *       2) while loop condition: (slowRunner && fastRunner && fastRunner->next)
 *          - this works bcuz fastrunner->next->next 유무 relies on fastrunner->next 
 *            => so fastRunner->next만 존재하면 됨!
 *          - also, efficient to check (slowRunner && fastRunner)
 *            instead of have separate if (!head) for exception
 *            => two in one! more simple and cleaner code
 * 
 *       3) UPDATED runners' positions FIRST, 
 *          and THEN, CHECK IF CYCLE
 * 
 */

#include <bits/stdc++.h>
using namespace std;

/**
 *  check if linked list has cycle
 */
bool findCycle(SinglyLinkedListNode* head) {

    SinglyLinkedListNode* fastRunner = head;
    SinglyLinkedListNode* slowRunner = head;

    while (slowRunner && fastRunner && fastRunner->next) {

        /** update runner's positions (prior to checking cycle)
         *  so that initial start position (at head) is not checked as cycle
        */ 
        fastRunner = fastRunner->next->next;
        slowRunner = slowRunner->next;

        // check for cycle (if two runners meet)
        if (fastRunner == slowRunner) {
            return true;
        }
    }

    // if either runner comes to the end,
    return false;
}