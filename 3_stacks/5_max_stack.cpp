/**
 *  Design a max stack with the following methods
 *  : push(x), pop(), top(), getMax()
 * 
 *  * Solution
 * 
 *    (1) brute-force: O(n) time, O(1) extra space
 *        -> simply use a single stack for push, pop, top methods
 *        -> for getMax(), linear search to find max value SO FAR
 * 
 *    (2) store max values in stack: O(1) time, O(n) extra space
 *        -> use additional space O(n) for getMax() to be constant time
 * 
 *        (2-a) store (val, max val SO FAR) in one stack
 *        (2-b) use an extra stack for max val SO FAR
 * 
 *        => 코드는 (2-a)가 훨씬 간편함 (push만 따로 적으면 되고 나머지는 스택 메소드 사용)
 * 
 *    (3) store gap: O(1) time, O(1) or O(n) extra space
 *        -> keep track of max and store gap btw last max into stack
 *           -> when updating max, store the difference between last max and current value
 *        -> when popping, update max back to last max using difference
 * 
 *        ** INTEGER OVERFLOW PROBLEM
 *           : since use (max * 2 - top) and INT range = (-2,147,483,648 ~ 2,147,483,647),
 *             if (max = -2,147,483,648 & top = 2,147,483,647)
 * 
 *        => MORE EFFICIENT ONLY when nums are SUFFICIENTLY SMALL!!
 *           : if numbers in range = (-715,827,882 ~ 715,827,882) 
 *                                   -> CAN USE store gap solution (using INT)
 *                                      : O(1) time, O(1) extra space
 *           : if NOT in range -> CANNOT USE store gap solution as is
 *                             => have to use LONG LONG instead
 *                                : O(1) time, O(n) extra space (actually n * 4 bytes added)
 * 
 *    (4) Doubly linked list + TreeMap: O(log n) time, O(n) extra space
 *        - if popMax() is included in the problem,
 *          implementing the stack using a doubly-linked list and tree map structure
 *          will help improve the time complexity for removal
 * 
 * 
 *  ** What I learned
 * 
 *     * record GAP instead of storing all prev maxes
 *       - everytime max value is updated -> need way to store prev MAX value
 *         => store the GAP instead of the new incoming value into stack (which is new_max)
 *            -> since incoming value (a.k.a new_max) is already updated into max value,
 *               use the GAP and MAX value to reverse engineer in CALCULATING prev max
 * 
 *         => need GAP value which satisfied 2 conditions
 *            1) (new_max -> prev_max): have to be able to DERIVE prev_max FROM new_max value
 *            2) (GAP == indicator): gap value has to somehow indicate that it is GAP value
 *                -> if maxStack: GAP > new_max so that it indicates that top value is GAP and not simply stacked value
 *                -> if minStack: GAP < new_min
 *                (since there should be no value in stack > new_max, means anomaly => indicator of GAP stored
 *                  vice-verse for minStack in that no value < new_min)
 * 
 *         * how to create appropriate math equation to finding 
 *           - use what conditions you have:
 *             1) new_max > prev_max
 *             2) need to create GAP > new_max
 *             -> 1번 뒤집어서: (new_max - prev_max) > 0
 *             -> 양쪽에 new_max 더해서: (new_max + new_max - prev_max) > new_max
 *             => GAP = (2 * new_max) - prev_max
 *                (cf. 반대로 minStack에서도 new_min < prev_min하고 GAP <new_max 조건 충족해야 되어
 *                      마찬가지로 GAP = (2 * new_max) - prev_max 이다)
 * 
 *     ** PROBLEM w/ using MATH!!
 *        -> possibility of INTEGER OVERFLOW!!
 *        => either use larger data type 
 *           or use only when input is sufficiently small
 * 
*/

#include <bits/stdc++.h>
using namespace std;

/**
 *  (1) brute-force
 */
class MaxStack {
    private: 
        stack<int> s;

    public:
        void push(int x) {
            s.push(x);
        }
        
        void pop() {
            s.pop();
        }
        
        int top() {
            return s.top();
        }
        
        int getMax() {
            int max_element = numeric_limits<int>::min();

            /** check all items in stack
             *  to find max element
             */ 
            int* temp = new int[s.size()];
            for (int i = 0, n = s.size(); i < n; i++) {
                temp[i] = s.top();
                s.pop();
                max_element = max(max_element, temp[i]);
            }

            // restore stack to original state
            for (int i = s.size() - 1; i >= 0; i--) {
                s.push(temp[i]);
            }
            delete temp;

            return max_element;
        }
};

/**
 *  (2-a) store val and max values together
 */
class MaxStack {
    private:
        stack<pair<int, int>> s;

    public:
        void push(int x) {
            // update max value
            int max_element = (this->s.size() == 0) ? numeric_limits<int>::min() : this->s.top().second;
            max_element = max(max_element, x);

            // push pair into stack
            this->s.push(make_pair(x, max_element));
        }
        
        void pop() {
            this->s.pop();
        }
        
        int top() {
            return this->s.top().first;
        }
        
        int getMax() {
            return this->s.top().second;
        }
};

/**
 *  (2-b) use an extra stack for max values
 */
class MaxStack {
    private:
        stack<int> stackValue;
        stack<int> stackMax;
        
    public:
        void push(int x) {
            // push value into stack
            stackValue.push(x);

            // update max value into stackMin
            if (stackMax.empty() || x >= stackMax.top()) {
                stackMax.push(x);
            }
        }
        
        void pop() {
            // pop value from stack
            int popped = stackValue.top();
            stackValue.pop();

            // update max value
            if (popped == stackMax.top()) {
                stackMax.pop();
            }
        }
        
        int top() {
            if (stackValue.empty()) {
                throw invalid_argument("stack is empty");
            }
            return stackValue.top();
        }
        
        int getMax() {
            if (stackMax.empty()) {
                throw invalid_argument("stack is empty");
            }
            return stackMax.top();
        }
};

/** (3) store difference
 *  
 */
class MaxStack {
private: 
    stack<long long> s;
    long long max;

public:
    MaxStack() {
        this->max = numeric_limits<int>::min();
    }

    void push(int x) {
        /** if max value is outdated -> push difference and update min
         *  else -> just push the new value (x)
         */ 
        if (s.empty()) {
            s.push(x);
            this->max = x;
        } else if (x > this->max) {
            s.push((long long) x * 2 - this->max);
            this->max = (long long)x;
        } else {
            s.push(x);
        }
    }
    
    void pop() {
        /** if difference stored in top -> update max and pop
         *  else -> just pop the top value
         */ 
        if (s.top() > this->max) {
            this->max = this->max * 2 - (long long) s.top();
        }
        s.pop();
    }
    
    int top() {
        if (s.top() > this->max) {
            return this->max;
        }
        return s.top();
    }
    
    int getMax() {
        return this->max;
    }
        
};