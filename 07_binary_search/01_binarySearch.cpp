#include <vector>
#include <iostream>
using namespace std;

/*
Problem: Binary Search
Link: https://leetcode.com/problems/binary-search/
Difficulty: Easy
Topic: Binary Search

Approach:
- low=0, high=n-1
- mid = low + (high-low)/2  → prevents overflow
- if nums[mid]==target → found
- if nums[mid]>target  → search left  (high=mid-1)
- if nums[mid]<target  → search right (low=mid+1)
- return -1 if not found

Time Complexity: O(log n)
Space Complexity: O(1)
*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low  = 0;
        int high = nums.size() - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] == target) return mid;
            else if (nums[mid] > target) high = mid - 1;
            else low = mid + 1;
        }

        return -1;
    }
};

int main() {
    Solution sol;

    vector<int> v1 = {-1,0,3,5,9,12};
    vector<int> v2 = {-1,0,3,5,9,12};
    vector<int> v3 = {5};
    vector<int> v4 = {5};

    cout << "v1 target=9  → " << sol.search(v1,9)  << endl; // 4
    cout << "v2 target=2  → " << sol.search(v2,2)  << endl; // -1
    cout << "v3 target=5  → " << sol.search(v3,5)  << endl; // 0
    cout << "v4 target=6  → " << sol.search(v4,6)  << endl; // -1

    return 0;
}