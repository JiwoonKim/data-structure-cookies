/**
 *  Given a certain prefix/infix/postfix expression,
 *  convert it to either a prefix/infix/postfix expression.
 * 
 *  * Solution
 * 
 *    (1) use stack: O
 * 
 * 
 *  ** What I learned
 * 
 * 
*/

#include <bits/stdc++.h>
using namespace std;

/**
 *  
 */
string infixToPostfix(string s) {

    string result;

    stack<char> operands;
    stack<char> operators;

    unordered_set<char> operators = { '+', }
    for (char c : s) {

    }
}