#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

/*
Problem: Subarray Sum Equals K
Link: https://leetcode.com/problems/subarray-sum-equals-k/
Difficulty: Medium
Topic: Arrays, Hashing, Prefix Sum

Approach — Prefix Sum + HashMap:
- For each index, track cumulative sum (preSum)
- If preSum-k exists in map → found subarray summing to k
- mpp[0]=1 handles subarrays starting from index 0
- Update map AFTER count to avoid using same index twice

Key insight:
preSum[j] - preSum[i] = k
→ preSum[i] = preSum[j] - k
→ check if (preSum-k) seen before

Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mpp;
        mpp[0] = 1;        // empty subarray
        int preSum = 0;
        int count  = 0;

        for (int i = 0; i < nums.size(); i++) {
            preSum += nums[i];
            int remove = preSum - k;
            count += mpp[remove];
            mpp[preSum]++;
        }

        return count;
    }
};

int main() {
    Solution sol;

    vector<int> v1 = {1,1,1};
    vector<int> v2 = {1,2,3};
    vector<int> v3 = {1,-1,1};
    vector<int> v4 = {3,4,7,2,-3,1,4,2};

    cout << "v1 k=2 → " << sol.subarraySum(v1,2) << endl; // 2
    cout << "v2 k=3 → " << sol.subarraySum(v2,3) << endl; // 2
    cout << "v3 k=1 → " << sol.subarraySum(v3,1) << endl; // 3
    cout << "v4 k=7 → " << sol.subarraySum(v4,7) << endl; // 4

    return 0;
}