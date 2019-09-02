/**
 *  Given an infix expression, convert it to postfix expression.
 *  Also, evaluate the postfix expression.
 * 
 *  * Solution
 * 
 *    (1) use a stack: O(n) time, O(n) extra space
 *        -> reverse order of operands so that higher priority comes first
 *           -> use stack to store operators in reverse order until no more higher point
 *           -> pop all those in stack which priority is equal or lower to current value
 *        -> careful with brackets ()
 *           -> use '(' as start point for sub-stack
 * 
 * 
 *  ** What I learned
 *  
 *     ** how to CONVERT: infix -> postfix
 *        = REVERSING order of operators depending on PRIORITY
 *
 *        (1) just print out operands as is
 *        (2) push operators into stack
 *        (3) pop all those with LOWER or EQUAL priority (not all in stack)
 *            -> will be printed in reversed order compared to original infix expression
 *        (4) if brackets allowed, treat them as a subproblem
 *            -> use '(' as starting point of stack 
 *               and if reached ')', pop all in stack until '(' on top
 *
 *     ** careful when popping from stack
 *        - make sure stack is NOT-EMPTY before popping
 *        - if popping until certain point, 
 *          -> make sure to use condition w/ WHILE-STATEMENT 
 *             not the if-statement bcuz that would be using (if and then while)
 *             and be confusing and error-prone
 * 
 *
 *     ** evaluate postfix expression (= calculate)
 *        : use stack to store operands this time
 *          and calculate the end result
 *          -> if operator, pop two operands from stack and calculate them
 *             push the result of calculation back on top of stack
 *          -> end result is stored in top of stack
*/

#include <bits/stdc++.h>
using namespace std;

/** 
 *  use a stack
 */
string infixToPostfix(string prefix) {

    // create string to store result
    string postfix = "";

    // create stacks to track operators
    stack<char> s;

    // convert each char in evaulation
    for (char c : prefix) {

        // if char is bracket,
        if (c == '(') {
            // push opening bracket to stack
            s.push(c);
        }
        else if (c == ')') {
            // pop all operators on top of '('
            while (!s.empty() && s.top() != '(') {
                postfix += s.top();
                s.pop();
            }
            s.pop();
        }
        // if char is operator,
        else if (priority(c) > 0) {
            
            /** if current operator has lower priority,
             *  pop all operators in stack (-> in reverse order)
             */ 
            while (!s.empty() && priority(c) <= priority(s.top())) {
                postfix += s.top();
                s.pop();
            }
            
            /** push operator to stack 
             *  (in order to REVERSE the order)
             */ 
            s.push(c);
        }
        // if char is operand,
        else {
            postfix += c;
        }
    }

    // pop all remaining operators
    while (!s.empty()) {
        postfix += s.top();
        s.pop();
    }

    // return the converted postfix expression
    return postfix;
}
// helper function
int priority(char c) {
    // sort the priorities of operators
    if (c == '*' || c == '/') return 2;
    else if (c == '+' || c == '-') return 1;
    // differentiate operands
    else return -1;
}


/** evaluate a postfix expression
 *  (assume that only one digit numbers will be given)
 */ 
int evaluatePostix(string postfix) {

    stack<int> s;

    for (char c : postfix) {
        
        // if operand, push into stack
        if (isdigit(c)) {
            string num;
            num += c;
            s.push(stoi(num));
        } 
        // if operator,
        else {
            // pop top two operands
            int top1 = s.top();
            s.pop();
            int top2 = s.top();
            s.pop();

            // calculate depending on operator
            if (c == '+') {
                s.push(top1 + top2);
            }
            else if (c == '-') {
                s.push(top2 - top1);
            }
            else if (c == '*') {
                s.push(top1 * top2);
            }
            else if (c == '/') {
                s.push(top2 / top1);
            }
        }
    }
    // return top value
    return s.top();
}