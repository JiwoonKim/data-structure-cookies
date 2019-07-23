/**
 *  Find the least common ancestor of the two values in the given BST.
 *  
 *  * BST (Binary Search Tree)
 *    : binary tree which has property of (left sub-tree < node < right sub-tree)    
 * 
 *  ** What I learned
 * 
 *   ** HOW to FIND LCA (Least Common Ancestor)
 * 
 *      CASES)
 *      - case 1: both in left subtree => lca in left subtree
 *      - case 2: both in right subtree => lca in right subtree
 *      - case 3: one each in subtree (diverged) => 
 *      - case 4: one is root, other is in left or right subtree
 * 
 *      SOLUTION)
 * 
 *      1. CHECK WHERE v1 and v2 is from cur pointer
 *         - (1) root, (2) left subtree, (3) right subtree
 *               => 복잡하게 일일이 left에 있냐, right에 있냐 경우 다 체크할 것 없이,
 *                  그냥 left subtree에 있는지 없는지로 간단하게 체크할 수 있음!! (따로 helper function으로 분리하자)
 *                  -> 마찬가지로 left subtree에 있는지 없는지 역시 BST 성질 이용해서
 *                     간단하게 현재 root(사실상 cur)보다 값이 작거나 같은지만 확인하면 됨!
 * 
 *         => check v1 and v2 with InLeftSubtree (true, false)
 * 
 *      2. COMPARE v1 and v2 solution
 *         1) if either v1 or v2 is root,
 *            => 현재 root = lca
 * 
 *         2) if v1 and v2 in different subtrees
 *            (InLeftSubtree 각각의 값이 XOR; 둘의 값이 != 인지로 체크 가능)
 *            => 현재 root = lca
 * 
 *         3) else, v1 and v2 located in same subtree 
 *            (InLeftSubtree 각각의 값이 BOTH true or BOTH false; 둘의 값이 == 인지로 체크 가능)
 *            => RECURSIVELY check subtree for v1 or v2 (RECURSION하기 위해 root을 다음 subtree로 설정하여 재귀적으로 함수 호출!!)
 * 
 *         => compare v1 and v2 InLeftSubtree (true, false) value
 *            if located in same subtree, recursively find lca within subtree (update to new root)
 * 
 *   ** BST -> Binary Search 방법 이용하기!
 *      : binary search tree라고 불리는 이유가 있다!!
 *       -> BST는 이분탐색을 하기에 최적화된 트리 구조
 * 
 *       - SEARCH in BST
 *         if (cur == )
 * 
 *       => BST에서 무엇을 찾으라는 문제는 무조건 Binary Search 이용하기!
 * 
 */

#include <bits/stdc++.h>
using namespace std;

/**
 *  check if v is in left subtree of root
 *  (use binary search: keep checking the lower value)
*/
bool nodeIsInLeftSubtree(Node* root, int v) {

    // if v is lower or equal to root's value, v is in left subtree
    if (v <= root->data)     {
        return true;
    }
    return false;
}

/**
 *  find the lca (least common ancestor) of the two values
 *  within the binary search tree
*/
Node* lca(Node* root, int v1, int v2) {

    // if v1 and v2 are diverged in different subtrees, root is lca
    if (root->data == v1 || root->data == v2 || nodeIsInLeftSubtree(root, v1) != nodeIsInLeftSubtree(root, v2)) {
        return root;
    }
    // v1 and v2 are both in left subtree
    else if (nodeIsInLeftSubtree(root, v1)) {
        return lca(root->left, v1, v2);
    }
    // v1 and v2 are both in right subtree
    else {
        return lca(root->right, v1, v2);
    }
}