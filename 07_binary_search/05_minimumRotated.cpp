#include <vector>
#include <climits>
#include <algorithm>
#include <iostream>
using namespace std;

/*
Problem: Find Minimum in Rotated Sorted Array
Link: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
Difficulty: Medium
Topic: Binary Search

Approach:
- At every mid, one half is always sorted
- Minimum of sorted half is its leftmost element
- Left sorted (nums[low]<=nums[mid]):
  → min candidate = nums[low], search right half
- Right sorted (nums[mid]<nums[low]):
  → min candidate = nums[mid], search left half
- Track global minimum with ans

Time Complexity: O(log n)
Space Complexity: O(1)
*/

class Solution {
public:
    int findMin(vector<int>& nums) {
        int low  = 0;
        int high = nums.size() - 1;
        int ans  = INT_MAX;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[low] <= nums[mid]) {
                // left half sorted
                ans = min(ans, nums[low]);
                low = mid + 1;
            } else {
                // right half sorted
                ans = min(ans, nums[mid]);
                high = mid - 1;
            }
        }

        return ans;
    }
};

int main() {
    Solution sol;

    vector<int> v1 = {3,4,5,1,2};
    vector<int> v2 = {4,5,6,7,0,1,2};
    vector<int> v3 = {11,13,15,17};
    vector<int> v4 = {1};
    vector<int> v5 = {2,1};

    cout << "v1 → " << sol.findMin(v1) << endl; // 1
    cout << "v2 → " << sol.findMin(v2) << endl; // 0
    cout << "v3 → " << sol.findMin(v3) << endl; // 11
    cout << "v4 → " << sol.findMin(v4) << endl; // 1
    cout << "v5 → " << sol.findMin(v5) << endl; // 1

    return 0;
}