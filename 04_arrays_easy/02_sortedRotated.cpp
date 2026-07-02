#include <vector>
#include <iostream>
using namespace std;

/*
Problem: Check if Array is Sorted and Rotated
Link: https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/
Difficulty: Easy
Topic: Arrays

Approach:
- A sorted+rotated array has at most ONE drop point
  where nums[i] > nums[i+1]
- Count drops including wrap-around (last vs first)
- If drops <= 1 → true, else → false

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int drops = 0;

        for (int i = 0; i < n; i++) {
            // % n handles wrap-around (last → first)
            if (nums[i] > nums[(i+1) % n]) {
                drops++;
            }
        }

        return drops <= 1;
    }
};

int main() {
    Solution sol;

    vector<int> v1 = {3,4,5,1,2};
    vector<int> v2 = {2,1,3,4};
    vector<int> v3 = {1,2,3};
    vector<int> v4 = {1,1,1};

    cout << "v1 → " << sol.check(v1) << endl; // 1
    cout << "v2 → " << sol.check(v2) << endl; // 0
    cout << "v3 → " << sol.check(v3) << endl; // 1
    cout << "v4 → " << sol.check(v4) << endl; // 1

    return 0;
}