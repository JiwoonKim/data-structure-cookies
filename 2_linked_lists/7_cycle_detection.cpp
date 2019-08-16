/**
 *  Check if linked list has cycle.
 * 
 *  * Solutions
 *      
 *    (1) two runner approach: O(n) time, O(1) extra space
 *        -> use two pointers at different speeds to check if cycle exists
 * 
 *    (2) hash table: O(n) time, O(n) extra space
 *        -> use hash table to record visited nodes
 *        -> check if visited nodes are revisited
 * 
 *  ** What I learned
 * 
 *     * how to use TWO RUNNER APPROACH
 * 
 *       (1) initialize both runners to HEAD
 * 
 *       (2) while loop condition: (slowRunner && fastRunner && fastRunner->next)
 *           - this works bcuz fastrunner->next->next 유무 relies on fastrunner->next 
 *             => so fastRunner->next만 존재하면 됨!
 *           - also, efficient to check (slowRunner && fastRunner)
 *             instead of have separate if (!head) for exception
 *             => two in one! more simple and cleaner code
 * 
 *       (3) FIRST UPDATE runners' positions,
 *           and THEN, CHECK IF CYCLE
 *           -> can start both runners at same position (both at head)
 *              and do not have to check if head is empty or not
 *           cf) if opposite order (1. check cycle 2. update ptrs)
 *               -> need to start (fastRunner = head->next)
 *                  and have to handle exceptional cases of if (!head) -> return false
 *          
 *          => CLEANER code and FASTER runtime
 * 
 */

#include <bits/stdc++.h>
using namespace std;

/**
 *  (1) two runner approach
 */
bool findCycle(Node* head) {

    Node* fastRunner = head;
    Node* slowRunner = head;

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

/**
 *  (2) hash table
 */
bool findCycle(Node* head) {
    
    // create visited record
    unordered_set<Node*> visited;

    // traverse list while checking records
    Node* current = head;
    while (current) {
        // check if visited node before
        if (visited.count(current) > 0) {
            return true;
        }
    }
    return false;
}