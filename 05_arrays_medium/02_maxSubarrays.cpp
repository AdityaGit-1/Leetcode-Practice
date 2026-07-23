#include <vector>
#include <climits>
#include <iostream>
using namespace std;

/*
Problem: Maximum Subarray
Link: https://leetcode.com/problems/maximum-subarray/
Difficulty: Medium
Topic: Arrays, Dynamic Programming, Kadane's Algorithm

Approach — Kadane's Algorithm:
- Maintain running sum and global maximum
- Add current element to sum
- Update ans if sum is greater
- Reset sum to 0 if it goes negative
  (negative sum hurts future subarrays)
- INT_MIN handles all-negative arrays

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = INT_MIN;
        int sum = 0;

        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if (sum > ans) ans = sum;
            if (sum < 0)  sum = 0;
        }

        return ans;
    }
};

int main() {
    Solution sol;

    vector<int> v1 = {-2,1,-3,4,-1,2,1,-5,4};
    vector<int> v2 = {1};
    vector<int> v3 = {5,4,-1,7,8};
    vector<int> v4 = {-1,-2,-3,-4};  // all negative

    cout << "v1 → " << sol.maxSubArray(v1) << endl; // 6
    cout << "v2 → " << sol.maxSubArray(v2) << endl; // 1
    cout << "v3 → " << sol.maxSubArray(v3) << endl; // 23
    cout << "v4 → " << sol.maxSubArray(v4) << endl; // -1

    return 0;
}