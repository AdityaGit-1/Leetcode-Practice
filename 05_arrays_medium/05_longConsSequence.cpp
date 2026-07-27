#include <vector>
#include <unordered_set>
#include <algorithm>
#include <iostream>
using namespace std;

/*
Problem: Longest Consecutive Sequence
Link: https://leetcode.com/problems/longest-consecutive-sequence/
Difficulty: Medium
Topic: Arrays, Hashing

Approach:
- Insert all elements into unordered_set
- For each element that is a SEQUENCE START
  (no element-1 exists in set)
- Count consecutive elements from there
- Track maximum count

Why check for sequence start?
→ Avoids counting same sequence multiple times
→ Each sequence counted exactly once

Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;

        unordered_set<int> st;
        for (int i = 0; i < nums.size(); i++)
            st.insert(nums[i]);

        int longest = 1;

        for (auto it : st) {
            if (st.find(it-1) == st.end()) { // sequence start
                int x   = it;  // ✅ no 'int' keyword
                int cnt = 1;   // ✅ no 'int' keyword

                while (st.find(x+1) != st.end()) {
                    x++;
                    cnt++;
                }

                longest = max(longest, cnt);
            }
        }

        return longest;
    }
};

int main() {
    Solution sol;

    vector<int> v1 = {100,4,200,1,3,2};
    vector<int> v2 = {0,3,7,2,5,8,4,6,0,1};
    vector<int> v3 = {1};
    vector<int> v4 = {};

    cout << "v1 → " << sol.longestConsecutive(v1) << endl; // 4
    cout << "v2 → " << sol.longestConsecutive(v2) << endl; // 9
    cout << "v3 → " << sol.longestConsecutive(v3) << endl; // 1

    return 0;
}