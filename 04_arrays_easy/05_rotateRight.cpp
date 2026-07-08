#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

/*
Problem: Rotate Array
Link: https://leetcode.com/problems/rotate-array/
Difficulty: Medium
Topic: Arrays, Two Pointers

Approach — Three reverse trick:
- Rotating right by k = moving last k elements to front
- Step 1: reverse first n-k elements
- Step 2: reverse last k elements  
- Step 3: reverse entire array

Example: [1,2,3,4,5,6,7] k=3
Step 1: reverse [1,2,3,4] → [4,3,2,1,5,6,7]
Step 2: reverse [5,6,7]   → [4,3,2,1,7,6,5]
Step 3: reverse all       → [5,6,7,1,2,3,4] ✓

Time: O(n)
Space: O(1)
*/

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;           // handle k > n
        if (k == 0) return;  // no rotation needed

        int d = n - k;       // split point

        reverse(nums.begin(), nums.begin()+d);   // reverse first part
        reverse(nums.begin()+d, nums.end());      // reverse second part
        reverse(nums.begin(), nums.end());        // reverse all
    }
};

int main() {
    Solution sol;

    vector<int> v1 = {1,2,3,4,5,6,7};
    vector<int> v2 = {-1,-100,3,99};
    vector<int> v3 = {1,2};
    vector<int> v4 = {1};

    sol.rotate(v1, 3);
    for (int x : v1) cout << x << " ";
    cout << endl; // 5 6 7 1 2 3 4

    sol.rotate(v2, 2);
    for (int x : v2) cout << x << " ";
    cout << endl; // 3 99 -1 -100

    sol.rotate(v3, 3);
    for (int x : v3) cout << x << " ";
    cout << endl; // 2 1

    sol.rotate(v4, 0);
    for (int x : v4) cout << x << " ";
    cout << endl; // 1

    return 0;
}