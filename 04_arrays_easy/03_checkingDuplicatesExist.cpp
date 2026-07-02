#include <vector>
#include <unordered_set>
#include <iostream>
using namespace std;

/*
Problem: Contains Duplicate
Link: https://leetcode.com/problems/contains-duplicate/
Difficulty: Easy
Topic: Arrays, Hashing

Approach:
- Use unordered_set to track seen elements
- For each element check if it already exists in set
- If yes → duplicate found → return true immediately (early exit)
- If no → insert into set and continue
- Return false if no duplicates found

Time Complexity: O(n) — single pass
Space Complexity: O(n) — set stores up to n elements
*/

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> seen;

        for (int i = 0; i < nums.size(); i++) {
            if (seen.count(nums[i])) return true; // duplicate found
            seen.insert(nums[i]);
        }

        return false;
    }
};

int main() {
    Solution sol;

    vector<int> v1 = {1,2,3,1};
    vector<int> v2 = {1,2,3,4};
    vector<int> v3 = {1,1,1,3,3,4,3,2,4,2};

    cout << "v1 → " << sol.containsDuplicate(v1) << endl; // 1
    cout << "v2 → " << sol.containsDuplicate(v2) << endl; // 0
    cout << "v3 → " << sol.containsDuplicate(v3) << endl; // 1

    return 0;
}