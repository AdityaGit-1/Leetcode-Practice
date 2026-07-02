#include <vector>
#include <iostream>
using namespace std;

/*
Problem: Remove Duplicates from Sorted Array
Link: https://leetcode.com/problems/remove-duplicates-from-sorted-array/
Difficulty: Easy
Topic: Arrays, Two Pointers

Approach:
- Two pointers — i tracks last unique element position
- j scans through the array
- When nums[j] != nums[i], a new unique element found
- Place it at nums[i+1] and increment i
- Return i+1 (count of unique elements)

Time Complexity: O(n)
Space Complexity: O(1) — in-place
*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;

        for (int j = 1; j < nums.size(); j++) {
            if (nums[j] != nums[i]) {
                nums[i+1] = nums[j];
                i++;
            }
        }

        return i + 1;
    }
};

int main() {
    Solution sol;

    vector<int> v1 = {1,1,2};
    vector<int> v2 = {0,0,1,1,1,2,2,3,3,4};

    cout << "v1 → " << sol.removeDuplicates(v1) << endl; // 2
    cout << "v2 → " << sol.removeDuplicates(v2) << endl; // 5

    return 0;
}