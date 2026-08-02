#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

/*
Problem: Merge Intervals
Link: https://leetcode.com/problems/merge-intervals/
Difficulty: Medium
Topic: Arrays, Sorting, Greedy

Approach:
- Sort intervals by start time
- For each interval:
  → If ans empty OR no overlap (start > last end)
    → push new interval
  → Else overlap exists
    → merge by updating end = max(last end, current end)

Time Complexity: O(n log n) — sorting
Space Complexity: O(n) — output
*/

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;

        for (int i = 0; i < intervals.size(); i++) {
            if (ans.empty() || intervals[i][0] > ans.back()[1]) {
                ans.push_back(intervals[i]);
            } else {
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
            }
        }

        return ans;
    }
};

int main() {
    Solution sol;

    vector<vector<int>> v1 = {{1,3},{2,6},{8,10},{15,18}};
    vector<vector<int>> v2 = {{1,4},{4,5}};
    vector<vector<int>> v3 = {{1,4},{2,3}};
    vector<vector<int>> v4 = {{1,4},{0,4}};

    auto r1 = sol.merge(v1);
    auto r2 = sol.merge(v2);
    auto r3 = sol.merge(v3);
    auto r4 = sol.merge(v4);

    for (auto& t : r1) cout<<"["<<t[0]<<","<<t[1]<<"] ";
    cout << endl; // [1,6] [8,10] [15,18]

    for (auto& t : r2) cout<<"["<<t[0]<<","<<t[1]<<"] ";
    cout << endl; // [1,5]

    for (auto& t : r3) cout<<"["<<t[0]<<","<<t[1]<<"] ";
    cout << endl; // [1,4]

    for (auto& t : r4) cout<<"["<<t[0]<<","<<t[1]<<"] ";
    cout << endl; // [0,4]

    return 0;
}