# data-structure-cookies :cookie:
> re-inventing the wheel w/ data structures

> collection of common data structure problems

## :wrench: Useful Mechanisms To Remember
> list of useful mechanisms (functions) to remember

### 1. Arrays
1. `define dynamic array class` (1-1. dynamic array)
2. `methods for rotating array in-place` (1-2. rotate array :star:)
    - shift array elements one by one
    - use `cyclic replacement` in array
    - use `reverse` to rotate array by k
3. `binary search for condition to find rotation point` (1-3. rotation pivot :star:)
    - rotation point == smallest value's index
4. `left shift: end -> begin | right shift: begin -> end` (1-2. rotate array & 1-3. rotation pivot)
5. `use two pointers for ranging` (1-3. rotation pivot & 1-4. reverse array)
6. `one-pass hash table for fast lookup time` (1-6. find pair sum)
7. `(left <= right)` and `return false at end` for binary search (1-7. search element)
8. (1-8. merge two arrays :star:)

#### + Strings


#### + Matrixes
rotate matrix

### 2. Linked List
1. `define singly-linked list class` & `define doubly-linked list class`  (2-1. singly linked list & 2-2. doubly linked list)
2. `check 2 cases for deletion: delete head & delete others` (2-1. singly linked list & 2-2. doubly linked list :star:)
    - delete head: O(1)
    - delete other nodes: O(n)
3. `two pointer technique` (2-3. find nth node)
    - use `n-wide stick approach`
    - use `turtle and hare approach`
4. `reverse linked list in-place` (2-4. reverse list :star:)
    - reverse data values
    - reverse ptr directions
5. `merge two linked lists` (2-5. merge two lists :star:)
    - handle exceptions: `if (!list1) return list2` & `if (!list2) return list1`
    - use 3 pointers: `lastMerged` + 1 for traversing each list
    - recursive version: pick smaller node -> connect w/ merged list of rest of nodes
6. `use dummy node` (2-5. merge two lists)
    - to avoid separating head case from rest of nodes case
    - creates single code instead of repetitive code
7. `use length difference to find intersection point` (2-6. find intersection :star:)
    - give `head start` for longer runner
    - use two pointers to `cross traverse`: create illusion of same length course
8. `two runner (turtle and hare) approach for cycle detection` (2-7. cycle detection :star:)
    - while loop condition: check slowRunner & fastRunner & fastRunner->next
    - to start both runners at same position (head): `update pointers first` and then check cycle 

### 3. Stack
1. `define stack class` (3-1. stack :star:)
2. (3-2. max stack :star:)
3. `use stack for checking matching pairs` (3-3. valid brackets :star:)
    - predefine pairs using `unordered_set & map`
4. `check 3 cases for invalid brackets` (3-3. valid brackets)
    - no opening match, no closing match, wrong match
5. `pop all equal or lower priority operators` (3-4. postfix expression)
    - use while loop to pop those w/ specific conditions
    - predefine precedence using helper function
6. `use 2 stacks for undo & redo action` (3-5. simple text editor :star:)
7. `use stack to reverse order` (2-4. reverse list)

### 4. Queue

### 5. Tree

#### + Binary Tree
1. `check only current node for order traversal` (5(1)-2. pre-order / in-order / post-order traversal)
2. `use recursion to calculate height of binary tree` (5(1)-3. tree height)
3. `check root or !root as base case` (5(1)-2. order traversals & 5(1)-3. tree height)

#### + Binary Search Tree (BST)
2. `use binary search mechanism to check if node exists in BST` (5(2)-2. least common ancestor)
3. `use divide-and-conquer method to find Least Common Ancestor` (5(2)-2. least common ancestor)

#### + Heap

### 6. Graph

### 7. Hashing


