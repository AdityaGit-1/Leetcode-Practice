#include <vector>
#include <climits>
#include <iostream>
using namespace std;

/*
Problem: Majority Element II
Link: https://leetcode.com/problems/majority-element-ii/
Difficulty: Medium
Topic: Arrays, Boyer-Moore Voting

Approach — Extended Boyer-Moore (two candidates):
- At most 2 elements can appear > n/3 times
- Track two candidates and their counts
- When assigning el1: check el2!=current (avoid duplicates)
- When assigning el2: check el1!=current (avoid duplicates)
- Decrement both counts when neither candidate matches
- Verification pass confirms candidates actually qualify

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int count1 = 0, count2 = 0;
        int el1, el2 = INT_MIN;

        // Phase 1 — find candidates
        for (int i = 0; i < nums.size(); i++) {
            if (count1 == 0 && el2 != nums[i]) {
                count1 = 1;
                el1 = nums[i];
            }
            else if (count2 == 0 && el1 != nums[i]) {
                count2 = 1;
                el2 = nums[i];
            }
            else if (nums[i] == el1) count1++;
            else if (nums[i] == el2) count2++;
            else {
                count1--;
                count2--;
            }
        }

        // Phase 2 — verify candidates
        int cnt1 = 0, cnt2 = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (el1 == nums[i]) cnt1++;
            if (el2 == nums[i]) cnt2++;
        }

        int mini = int(nums.size() / 3) + 1;
        vector<int> ans;
        if (cnt1 >= mini) ans.push_back(el1);
        if (cnt2 >= mini) ans.push_back(el2);

        return ans;
    }
};

int main() {
    Solution sol;

    vector<int> v1 = {3,2,3};
    vector<int> v2 = {1,2};
    vector<int> v3 = {1,1,1,3,3,2,2,2};
    vector<int> v4 = {1,2,3};

    auto r1 = sol.majorityElement(v1);
    auto r2 = sol.majorityElement(v2);
    auto r3 = sol.majorityElement(v3);
    auto r4 = sol.majorityElement(v4);

    for (int x : r1) cout << x << " "; cout << endl; // 3
    for (int x : r2) cout << x << " "; cout << endl; // 1 2
    for (int x : r3) cout << x << " "; cout << endl; // 1 2
    for (int x : r4) cout << x << " "; cout << endl; // (empty)

    return 0;
}