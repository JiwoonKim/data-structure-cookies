/**
 *  Given two sorted arrays, merge the two to create one sorted array.
 * 
 *  * Solutions
 * 
 *    (1) merge sort: O(n + m) time, O(n + m) extra space
 * 
 *    (2) append and sort: O(n+m log n+m) time, O(n + m) extra space
 * 
 *    (3) heap sort: 
 * 
 *  ** What I learned
 * 
 *  
 */

#include <bits/stdc++.h>
using namespace std;

/**
 *  (1) merge sort
 */
vector<int> mergeTwoArrays(vector<int> nums1, int m, vector<int> nums2, int n) {
    
    vector<int> merged;

    // use two pointers to compare values from each array
    int ptr1 = 0, ptr2 = 0;
    while (ptr1 < m || ptr2 < n) {
        /** if values in nums2 have depleted so that there are only values in nums1
         *  or there remains values in nums1 and it is smaller than value in num2,
         *  insert ptr1's value from nums1 into merged array
         */ 
        if (ptr2 == n || (ptr1 != m && nums1[ptr1] <= nums2[ptr2])) {
            merged.push_back(nums1[ptr1]);
            ptr1++;
        } else {
            merged.push_back(nums2[ptr2]);
            ptr2++;
        }
    }
    return merged;
}


/**
 *  (2) append and sort
 */
vector<int> mergeTwoArrays(vector<int> nums1, int m, vector<int> nums2, int n) {

    // insert all values from nums1 and nums2 into merged array
    vector<int> merged = nums1;
    for (auto x : nums2) {
        merged.push_back(x);
    }

    // sort all the values in merged array
    sort(merged.begin(), merged.end());
    return merged;
}

/**
 *  (3) 
 */
void mergeTwoArrays(vector<int>& nums1, vector<int>& nums2) {

    int ptr1 = 0, ptr2 = 0;
    int size1 = nums1.size(), size2 = nums2.size();
    while (ptr1 < size1) {
        // increment
        if (ptr1 = size1 - 1 && nums1[ptr1] < nums2[ptr2]) {
            ptr2++;
        }

        // if ptr2's value is smaller, swap
        if (nums1[ptr1] > nums2[ptr2]) {
            swap(nums1[ptr1++], nums2[ptr2]);
        }
    }
    ptr1 = 0;
    while (ptr2 < size2) {
        if (nums2[ptr1] > nums2[ptr2]) {
            swap(nums2[ptr1++], nums2[ptr2++]);
        }
    }
}