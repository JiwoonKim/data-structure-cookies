/**
 *  Given a string containing just the characters '(', ')', '{', '}', '[' and ']', 
 *  determine if the input string is valid 
 *  -> valid: open brackets are closed by same type of bracket in the correct order
 * 
 *  * Solution
 * 
 *    (1) use stack: O(n) time, O(n) extra space
 *        -> go through each char in string
 *        -> use a stack to record opening brackets to check later when closing bracket appears
 *        -> when closing bracket appears, check if it matches MOST RECENT opening bracket
 *        -> at end of string, check if all opening brackets were successfully matched (stack == empty) or not
 * 
 * 
 *  ** What I learned
 * 
 *     * 3 INVALID cases
 *       (1) "("  : NO closing match
 *       (2) ")"  : NO opening match
 *       (3) "( ]": WRONG match
 *       
 *     ** use HASH MAP for fast checking
 * 
 *        (1) instead of CHECKING EACH CASE for opening brackets: (c == '('), (c == '{'), (c == '['),
 *            -> use UNORDERED_SET: simply insert all opening bracket cases and check if exists
 * 
 *        (2) instead of checking each case for closing brackets 
 *            and also FINDING CORRESPONDING opening bracket to it (code very complex...ㅠㅜ),
 *            -> use UNORDERED_MAP: insert MATCHING PAIRS
 *            -> use to both check each case of closing brackets and find corresponding match
 * 
*/

#include <bits/stdc++.h>
using namespace std;

/**
 *  (1) use stack
 */
bool isValid(string s) {

    /** create a set and map of brackets 
     *  for quick checking of bracket types and matches
     */ 
    unordered_set<char> close = {')', '}', ']'};
    unordered_map<char, char> openMatch = {
        {'(', ')'},
        {'{', '}'},
        {'[', ']'}
    };

    // use stack to check each bracket in string
    stack<char> bracketsBefore;
    for (char c : s) {

        // if opening bracket,
        if (openMatch.count(c) > 0) {
            bracketsBefore.push(c);
        }
        // if closing bracket,
        else if (close.count(c) > 0) {
            /** if stack is empty, no pair for closing bracket -> not valid
             *  if stack's top (opening) does not match current closing -> not valid
             */ 
            if (bracketsBefore.empty() || c != openMatch[bracketsBefore.top()]) {
                return false;
            }
            bracketsBefore.pop();
        }
    }

    // check if all brackets were successfully matched
    if (bracketsBefore.empty())
        return true;
    return false;
}