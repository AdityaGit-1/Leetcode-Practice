#include <vector>
#include <climits>
#include <algorithm>
#include <iostream>
using namespace std;

/*
Problem: Maximum Product Subarray
Link: https://leetcode.com/problems/maximum-product-subarray/
Difficulty: Medium
Topic: Arrays, Dynamic Programming

Approach:
- Track both maxProduct and minProduct at each step
- When current element is negative → swap max and min
  because negative × negative = positive (min becomes max)
- At each step either start fresh or extend subarray
- Update global ans with maxProduct each iteration

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans     = nums[0];
        int maxProd = nums[0];
        int minProd = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            // negative flips max and min
            if (nums[i] < 0) swap(maxProd, minProd);

            maxProd = max(nums[i], maxProd * nums[i]);
            minProd = min(nums[i], minProd * nums[i]);

            ans = max(ans, maxProd);
        }

        return ans;
    }
};

int main() {
    Solution sol;

    vector<int> v1 = {2,3,-2,4};
    vector<int> v2 = {-2,0,-1};
    vector<int> v3 = {2,-5,-3};
    vector<int> v4 = {-2};
    vector<int> v5 = {-2,3,-4};

    cout << "v1 → " << sol.maxProduct(v1) << endl; // 6
    cout << "v2 → " << sol.maxProduct(v2) << endl; // 0
    cout << "v3 → " << sol.maxProduct(v3) << endl; // 30
    cout << "v4 → " << sol.maxProduct(v4) << endl; // -2
    cout << "v5 → " << sol.maxProduct(v5) << endl; // 24

    return 0;
}