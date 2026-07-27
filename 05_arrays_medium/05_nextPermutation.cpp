#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

/*
Problem: Next Permutation
Link: https://leetcode.com/problems/next-permutation/
Difficulty: Medium
Topic: Arrays, Two Pointers

Approach:
- Step 1: Find rightmost index where nums[i] < nums[i+1]
          (first dip from right)
- Step 2: If no such index → array is fully descending
          → reverse entire array (smallest permutation)
- Step 3: Find rightmost element greater than nums[index]
- Step 4: Swap them
- Step 5: Reverse suffix after index
          (makes it the next smallest arrangement)

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int index = -1;

        // Step 1 — find first dip from right
        for (int i = nums.size()-2; i >= 0; i--) {
            if (nums[i] < nums[i+1]) {
                index = i;
                break;
            }
        }

        // Step 2 — fully descending → reverse all
        if (index == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }

        // Step 3 & 4 — find and swap
        for (int i = nums.size()-1; i >= 0; i--) {
            if (nums[i] > nums[index]) {
                swap(nums[i], nums[index]);
                break;
            }
        }

        // Step 5 — reverse suffix
        reverse(nums.begin() + index + 1, nums.end());
    }
};

int main() {
    Solution sol;

    vector<int> v1 = {1,2,3};
    vector<int> v2 = {3,2,1};
    vector<int> v3 = {1,1,5};
    vector<int> v4 = {1,3,2};

    sol.nextPermutation(v1);
    for (int x : v1) cout << x << " ";
    cout << endl; // 1 3 2

    sol.nextPermutation(v2);
    for (int x : v2) cout << x << " ";
    cout << endl; // 1 2 3

    sol.nextPermutation(v3);
    for (int x : v3) cout << x << " ";
    cout << endl; // 1 5 1

    sol.nextPermutation(v4);
    for (int x : v4) cout << x << " ";
    cout << endl; // 2 1 3

    return 0;
}
