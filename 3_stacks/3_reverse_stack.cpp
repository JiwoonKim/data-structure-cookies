/**
 *  Use a stack to reverse the order of the given data structure.
 * 
 *  * Solution
 * 
 *    - use stack to reverse orders of given data structures
 * 
 * 
 *  ** What I learned
 * 
 *     ** stack is useful for REVERSING ORDERS
 * 
*/

#include <bits/stdc++.h>
using namespace std;

/**
 *  reverse linked list
 */
Node* reverseLinkedList(Node* head) {
    stack<int> s;
    // store node values into stack (to reverse order)
    Node* current = head;
    while (current) {
        s.push(current->data);
        current = current->next;
    }
    // reassign the node values in reverse order
    current = head;
    while (!s.empty()) {
        current->data = s.top();
        s.pop();
        current = (current->next) ? current->next : current;
    }
    return current;
}

/**
 *  reverse words in string
 */
string reverseWords(string str) {
    stack<char> s;
    for (char c : str) {
        stack.push(c);
    }
    int index = 0;
    while (!s.empty()) {
        str[index++] = s.top();
        s.pop();
    }
    return str;
}