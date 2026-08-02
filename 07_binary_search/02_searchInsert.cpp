#include <vector>
#include <iostream>
using namespace std;

/*
Problem: Search Insert Position
Link: https://leetcode.com/problems/search-insert-position/
Difficulty: Easy
Topic: Binary Search

Approach:
- ans initialized to nums.size() (target larger than all)
- When target <= nums[mid]:
  → mid is a candidate insert position
  → update ans, search left for smaller position
- When target > nums[mid]:
  → search right
- Returns exact index if found, insert position if not

Time Complexity: O(log n)
Space Complexity: O(1)
*/

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low  = 0;
        int high = nums.size() - 1;
        int ans  = nums.size();

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (target <= nums[mid]) {
                ans  = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};

int main() {
    Solution sol;

    vector<int> v1 = {1,3,5,6};
    vector<int> v2 = {1,3,5,6};
    vector<int> v3 = {1,3,5,6};
    vector<int> v4 = {1,3,5,6};
    vector<int> v5 = {1};

    cout << "target=5 → " << sol.searchInsert(v1,5) << endl; // 2
    cout << "target=2 → " << sol.searchInsert(v2,2) << endl; // 1
    cout << "target=7 → " << sol.searchInsert(v3,7) << endl; // 4
    cout << "target=0 → " << sol.searchInsert(v4,0) << endl; // 0
    cout << "target=0 → " << sol.searchInsert(v5,0) << endl; // 0

    return 0;
}