/**
 *  Create a simple text editor which supports the following functions:
 *   - L: move cursor to left
 *   - R: move cursor to right
 *   - D: delete letter before cursor (on the left)
 *   - I (char): insert (char) letter before cursor
 *   (cursor initially starts at the end of the given string)
 *  [Reference: https://www.acmicpc.net/problem/1406]
 * 
 *  * Solution
 * 
 *    (1) recreate string: O(n * m) time, O(n + m) extra space
 *        -> move cursor as instructions accordingly
 *        -> recreate string everytime inserting or deleting
 * 
 *    (2) use two stacks: O(m) time, O(n + m) extra space
 *        -> use two stacks to represent total string
 *           -> cursor is tracked by where the two stacks diverge
 *              ex. stack 1 = "ab", stack2 = "cd" -> then, cursor at "ab | cd"
 *        -> insert and delete at stack 1's top
 * 
 * 
 *  ** What I learned
 * 
 *     ** UNDO & REDO action
 *        : use TWO STACKS!
 *        - keep stack of actions (most recent action on top)
 *        - UNDO: pop top action (to another stack) and revert back to last action
 *        - REDO: push back action (kept in the other stack)
 * 
*/

#include <bits/stdc++.h>
using namespace std;

/**
 *  (2) use two stacks
 */
string editText(string s, vector<string> commands) {

    // create two stacks to track cursor
    stack<char> left, right;
    for (char c : s) {
        left.push(c);
    }

    // execute given commands
    for (string command : commands) {
        /** move cursor left or right
         *  by moving left's top to right's top
         */ 
        if (command[0] == 'L' && !left.empty()) {
            right.push(left.top());
            left.pop();
        }
        if (command[0] == 'R' && !right.empty()) {
            left.push(right.top());
            right.pop();
        }
        // insert new char at cursor
        if (command[0] == 'I') {
            left.push(command[2]);
        }
        // delete char at cursor
        if (command[0] == 'D' && !left.empty()) {
            left.pop();
        }
    }

    // reattach result string together
    while (!left.empty()) {
        right.push(left.top());
        left.pop();
    }
    string editted = "";
    while (!right.empty()) {
        editted += right.top();
        right.pop();
    }
    return editted;
}