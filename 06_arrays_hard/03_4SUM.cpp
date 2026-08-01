#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

/*
Problem: 4Sum
Link: https://leetcode.com/problems/4sum/
Difficulty: Medium
Topic: Arrays, Two Pointers, Sorting

Approach — Sort + Two nested loops + Two Pointer:
- Sort array first
- Fix i and j, use k and l as two pointers
- j!=i+1 check prevents skipping valid first j
- long long prevents overflow for large values
- Skip duplicates at all four levels

Time Complexity: O(n³)
Space Complexity: O(1) excluding output
*/

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;

        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i-1]) continue;

            for (int j = i+1; j < nums.size(); j++) {
                if (j != i+1 && nums[j] == nums[j-1]) continue;

                int k = j + 1;
                int l = nums.size() - 1;

                while (k < l) {
                    long long sum = (long long)nums[i] + nums[j]
                                  + nums[k] + nums[l];

                    if (sum > target) l--;
                    else if (sum < target) k++;
                    else {
                        ans.push_back({nums[i], nums[j],
                                       nums[k], nums[l]});
                        k++;
                        l--;
                        while (k < l && nums[k] == nums[k-1]) k++;
                        while (k < l && nums[l] == nums[l+1]) l--;
                    }
                }
            }
        }

        return ans;
    }
};

int main() {
    Solution sol;

    vector<int> v1 = {1,0,-1,0,-2,2};
    vector<int> v2 = {2,2,2,2,2};
    vector<int> v3 = {-3,-2,-1,0,0,1,2,3};

    auto r1 = sol.fourSum(v1, 0);
    auto r2 = sol.fourSum(v2, 8);
    auto r3 = sol.fourSum(v3, 0);

    for (auto& t : r1) {
        cout << "[";
        for (int x : t) cout << x << " ";
        cout << "] ";
    }
    cout << endl; // [-2,-1,1,2] [-2,0,0,2] [-1,0,0,1]

    for (auto& t : r2) {
        cout << "[";
        for (int x : t) cout << x << " ";
        cout << "] ";
    }
    cout << endl; // [2,2,2,2]

    return 0;
}
