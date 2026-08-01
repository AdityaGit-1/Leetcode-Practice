#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

/*
Problem: 3Sum
Link: https://leetcode.com/problems/3sum/
Difficulty: Medium
Topic: Arrays, Two Pointers, Sorting

Approach — Sort + Two Pointer:
- Sort array first
- Fix i, use j and k as two pointers
- Skip duplicate i to avoid duplicate triplets
- If sum<0 → j++ (need larger value)
- If sum>0 → k-- (need smaller value)
- If sum==0 → found triplet, skip duplicates for j and k

Time Complexity: O(n²)
Space Complexity: O(1) excluding output
*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;

        for (int i = 0; i < nums.size(); i++) {
            // skip duplicate i
            if (i > 0 && nums[i] == nums[i-1]) continue;

            int j = i + 1;
            int k = nums.size() - 1;

            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];

                if (sum < 0) j++;
                else if (sum > 0) k--;
                else {
                    ans.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                    // skip duplicates
                    while (j < k && nums[j] == nums[j-1]) j++;
                    while (j < k && nums[k] == nums[k+1]) k--;
                }
            }
        }

        return ans;
    }
};

int main() {
    Solution sol;

    vector<int> v1 = {-1,0,1,2,-1,-4};
    vector<int> v2 = {0,1,1};
    vector<int> v3 = {0,0,0};
    vector<int> v4 = {-2,0,0,2,2};

    auto r1 = sol.threeSum(v1);
    auto r2 = sol.threeSum(v2);
    auto r3 = sol.threeSum(v3);
    auto r4 = sol.threeSum(v4);

    for (auto& t : r1) cout << "[" << t[0] << "," << t[1] << "," << t[2] << "] ";
    cout << endl; // [-1,-1,2] [-1,0,1]

    for (auto& t : r2) cout << "[" << t[0] << "," << t[1] << "," << t[2] << "] ";
    cout << endl; // (empty)

    for (auto& t : r3) cout << "[" << t[0] << "," << t[1] << "," << t[2] << "] ";
    cout << endl; // [0,0,0]

    for (auto& t : r4) cout << "[" << t[0] << "," << t[1] << "," << t[2] << "] ";
    cout << endl; // [-2,0,2]

    return 0;
}