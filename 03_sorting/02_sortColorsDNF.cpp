#include <vector>
#include <iostream>
using namespace std;

/*
Problem: Sort Colors
Link: https://leetcode.com/problems/sort-colors/
Difficulty: Medium
Topic: Arrays, Two Pointers, Sorting

Approach 1 — Insertion Sort (your idea):
- Sort in place using insertion sort
- Time: O(n²), Space: O(1)

Approach 2 — Dutch National Flag (optimal):
- Three pointers: low, mid, high
- One pass through the array
- Time: O(n), Space: O(1)
*/

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low  = 0;
        int mid  = 0;
        int high = nums.size() - 1;

        while (mid <= high) {
            if (nums[mid] == 0) {
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            }
            else if (nums[mid] == 1) {
                mid++;
            }
            else {  // nums[mid] == 2
                swap(nums[mid], nums[high]);
                high--;
                // don't mid++ here — need to 
                // re-check swapped element
            }
        }
    }
};

int main() {
    Solution sol;

    vector<int> v1 = {2,0,2,1,1,0};
    vector<int> v2 = {2,0,1};
    vector<int> v3 = {0};
    vector<int> v4 = {1,0};

    sol.sortColors(v1);
    for (int x : v1) cout << x << " ";
    cout << endl; // 0 0 1 1 2 2

    sol.sortColors(v2);
    for (int x : v2) cout << x << " ";
    cout << endl; // 0 1 2

    sol.sortColors(v3);
    for (int x : v3) cout << x << " ";
    cout << endl; // 0

    sol.sortColors(v4);
    for (int x : v4) cout << x << " ";
    cout << endl; // 0 1

    return 0;
}