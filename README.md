# data-structure-cookies :cookie:
> re-inventing the wheel w/ data structures

> collection of common data structure problems

## :wrench: Useful Mechanisms To Remember
> list of useful mechanisms (functions) to remember

### 1. Arrays
1. `define dynamic array class` ([1-1. dynamic array](https://github.com/JiwoonKim/data-structure-cookies/blob/master/1_arrays/1_dynamic_array.cpp))
2. `methods for rotating array in-place` ([1-2. rotate array](https://github.com/JiwoonKim/data-structure-cookies/blob/master/1_arrays/2_rotate_array_right.cpp) :star:)
    - shift array elements one by one
    - use `cyclic replacement` in array
    - use `reverse` to rotate array by k
3. `binary search for condition to find rotation point` ([1-3. rotation pivot](https://github.com/JiwoonKim/data-structure-cookies/blob/master/1_arrays/3_rotation_pivot.cpp) :star:)
    - rotation point == smallest value's index
4. `left shift: end -> begin | right shift: begin -> end` ([1-2. rotate array](https://github.com/JiwoonKim/data-structure-cookies/blob/master/1_arrays/2_rotate_array_right.cpp) & [1-3. rotation pivot](https://github.com/JiwoonKim/data-structure-cookies/blob/master/1_arrays/4_reverse_array.cpp))
5. `use two pointers for ranging` ([1-3. rotation pivot](https://github.com/JiwoonKim/data-structure-cookies/blob/master/1_arrays/4_reverse_array.cpp) & [1-4. reverse array](https://github.com/JiwoonKim/data-structure-cookies/blob/master/1_arrays/4_reverse_array.cpp))
6. `one-pass hash table for fast lookup time` ([1-6. find pair sum](https://github.com/JiwoonKim/data-structure-cookies/blob/master/1_arrays/6_find_pair_sum.cpp))
7. `(left <= right)` and `return false at end` for binary search ([1-7. search element](https://github.com/JiwoonKim/data-structure-cookies/blob/master/1_arrays/7_search_element.cpp))
8. ([1-8. merge two arrays](https://github.com/JiwoonKim/data-structure-cookies/blob/master/1_arrays/8_merge_two_arrays.cpp) :star:)

#### + Strings


#### + Matrixes
rotate matrix

### 2. Linked List
1. `define singly-linked list class` & `define doubly-linked list class`  ([2-1. singly linked list](https://github.com/JiwoonKim/data-structure-cookies/blob/master/2_linked_lists/1_singly_linked_list.cpp) & 2-2. doubly linked list)
2. `check 2 cases for deletion: delete head & delete others` ([2-1. singly linked list](https://github.com/JiwoonKim/data-structure-cookies/blob/master/2_linked_lists/1_singly_linked_list.cpp) & [2-2. doubly linked list](https://github.com/JiwoonKim/data-structure-cookies/blob/master/2_linked_lists/2_doubly_linked_list.cpp) :star:)
    - delete head: O(1)
    - delete other nodes: O(n)
3. `two pointer technique` ([2-3. find nth node](https://github.com/JiwoonKim/data-structure-cookies/blob/master/2_linked_lists/3_find_nth_node.cpp))
    - use `n-wide stick approach`
    - use `turtle and hare approach`
4. `reverse linked list in-place` ([2-4. reverse list](https://github.com/JiwoonKim/data-structure-cookies/blob/master/2_linked_lists/4_reverse_list.cpp) :star:)
    - reverse data values
    - reverse ptr directions
5. `merge two linked lists` ([2-5. merge two lists](https://github.com/JiwoonKim/data-structure-cookies/blob/master/2_linked_lists/5_merge_two_lists.cpp) :star:)
    - handle exceptions: `if (!list1) return list2` & `if (!list2) return list1`
    - use 3 pointers: `lastMerged` + 1 for traversing each list
    - recursive version: pick smaller node -> connect w/ merged list of rest of nodes
6. `use dummy node` ([2-5. merge two lists](https://github.com/JiwoonKim/data-structure-cookies/blob/master/2_linked_lists/5_merge_two_lists.cpp))
    - to avoid separating head case from rest of nodes case
    - creates single code instead of repetitive code
7. `use length difference to find intersection point` ([2-6. find intersection](https://github.com/JiwoonKim/data-structure-cookies/blob/master/2_linked_lists/6_find_intersection.cpp) :star:)
    - give `head start` for longer runner
    - use two pointers to `cross traverse`: create illusion of same length course
8. `two runner (turtle and hare) approach for cycle detection` ([-7. cycle detection](https://github.com/JiwoonKim/data-structure-cookies/blob/master/2_linked_lists/7_cycle_detection.cpp) :star:)
    - while loop condition: check slowRunner & fastRunner & fastRunner->next
    - to start both runners at same position (head): `update pointers first` and then check cycle 

### 3. Stack
1. `define stack class` (3-1. stack :star:)
2. `implement k stacks w/ single array` (3-2. two stacks with array)
3. `use stack to reverse order` (2-4. reverse list && 3-3. reverse stack)
4. `sort` (2-)
5. (3-2. max stack :star:)
6. (3-6. queue with two stacks)
7. `use stack for checking matching pairs` (3-7. valid brackets :star:)
    - predefine pairs using `unordered_set & map`
8. `check 3 cases for invalid brackets` (3-7. valid brackets)
    - no opening match, no closing match, wrong match
9. `pop all equal or lower priority operators` (3-8. postfix expression)
    - use while loop to pop those w/ specific conditions
    - predefine precedence using helper function
10. `use 2 stacks for undo & redo action` (3-9. simple text editor :star:)

### 4. Queue

### 5. Tree

#### + Binary Tree
1. `check only current node for order traversal` ([5(1)-2. pre-order / in-order / post-order traversal](https://github.com/JiwoonKim/data-structure-cookies/blob/master/5_trees/1_binary_trees/2_order_traversals.cpp))
2. `use recursion to calculate height of binary tree` (5(1)-3. tree height)
3. `check root or !root as base case` ([5(1)-2. order traversals](https://github.com/JiwoonKim/data-structure-cookies/blob/master/5_trees/1_binary_trees/2_order_traversals.cpp) & [5(1)-3. tree height](https://github.com/JiwoonKim/data-structure-cookies/blob/master/5_trees/1_binary_trees/3_tree_height.cpp))

#### + Binary Search Tree (BST)
2. `use binary search mechanism to check if node exists in BST` ([5(2)-2. least common ancestor](https://github.com/JiwoonKim/data-structure-cookies/blob/master/5_trees/2_BST/2_least_common_ancestor.cpp))
3. `use divide-and-conquer method to find Least Common Ancestor` ([5(2)-2. least common ancestor](https://github.com/JiwoonKim/data-structure-cookies/blob/master/5_trees/2_BST/2_least_common_ancestor.cpp))

#### + Heap

### 6. Graph

### 7. Hashing


