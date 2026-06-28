#include <vector>
#include <iostream>
using namespace std;

/*
Problem: Merge Sorted Array
Link: https://leetcode.com/problems/merge-sorted-array/
Difficulty: Easy
Topic: Arrays, Two Pointers

Approach — Three pointers from the back:
- p1 points to last real element of nums1
- p2 points to last element of nums2
- p  points to last position of nums1
- Compare p1 and p2, place LARGER at position p
- Move backwards until one array is exhausted
- If nums2 still has elements, copy them in

Time: O(m+n)
Space: O(1) — no extra array needed
*/

class Solution {
public:
    void merge(vector<int>& nums1, int m,
               vector<int>& nums2, int n) {

        int p1 = m - 1;       // last real element in nums1
        int p2 = n - 1;       // last element in nums2
        int p  = m + n - 1;   // last position in nums1

        // fill nums1 from the back
        while (p1 >= 0 && p2 >= 0) {
            if (nums1[p1] > nums2[p2]) {
                nums1[p] = nums1[p1];
                p1--;
            } else {
                nums1[p] = nums2[p2];
                p2--;
            }
            p--;
        }

        // if nums2 still has elements remaining
        // (nums1 elements are already in place)
        while (p2 >= 0) {
            nums1[p] = nums2[p2];
            p--;
            p2--;
        }
    }
};

int main() {
    Solution sol;

    vector<int> n1 = {1,2,3,0,0,0};
    vector<int> n2 = {2,5,6};
    sol.merge(n1, 3, n2, 3);
    for (int x : n1) cout << x << " ";
    cout << endl; // 1 2 2 3 5 6

    vector<int> n3 = {0};
    vector<int> n4 = {1};
    sol.merge(n3, 0, n4, 1);
    for (int x : n3) cout << x << " ";
    cout << endl; // 1

    vector<int> n5 = {1,2,3,0,0,0};
    vector<int> n6 = {4,5,6};
    sol.merge(n5, 3, n6, 3);
    for (int x : n5) cout << x << " ";
    cout << endl; // 1 2 3 4 5 6

    return 0;
}