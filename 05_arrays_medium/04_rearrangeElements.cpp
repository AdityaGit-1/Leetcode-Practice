#include <vector>
#include <iostream>
using namespace std;

/*
Problem: Rearrange Array Elements by Sign
Link: https://leetcode.com/problems/rearrange-array-elements-by-sign/
Difficulty: Medium
Topic: Arrays, Two Index

Approach:
- Create result array of same size
- posIndex starts at 0, increments by 2
- negIndex starts at 1, increments by 2
- Place positives at even indices
- Place negatives at odd indices

Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> ans(nums.size()); // ✅ fixed
        int posIndex = 0;
        int negIndex = 1;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < 0) {
                ans[negIndex] = nums[i];
                negIndex += 2;
            } else {
                ans[posIndex] = nums[i];
                posIndex += 2;
            }
        }

        return ans;
    }
};

int main() {
    Solution sol;

    vector<int> v1 = {3,1,-2,-5,2,-4};
    vector<int> v2 = {-1,1};

    auto r1 = sol.rearrangeArray(v1);
    auto r2 = sol.rearrangeArray(v2);

    for (int x : r1) cout << x << " ";
    cout << endl; // 3 -2 1 -5 2 -4

    for (int x : r2) cout << x << " ";
    cout << endl; // 1 -1

    return 0;
}