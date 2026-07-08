#include <vector>
#include <iostream>
using namespace std;

/*
Problem: Move Zeroes
Link: https://leetcode.com/problems/move-zeroes/
Difficulty: Easy
Topic: Arrays, Two Pointers

Approach:
- Find position of first zero (i)
- Scan from i+1, swap every non-zero with position i
- Increment i after each swap
- Zeroes naturally bubble to the end

Time Complexity: O(n)
Space Complexity: O(1) — in-place
*/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = -1;

        // find first zero
        for (int j = 0; j < nums.size(); j++) {
            if (nums[j] == 0) {
                i = j;
                break;
            }
        }

        // no zeros found — already done
        if (i == -1) return;

        // swap non-zeros to front
        for (int j = i+1; j < nums.size(); j++) {
            if (nums[j] != 0) {
                int temp = nums[j];
                nums[j]  = nums[i];
                nums[i]  = temp;
                i++;
            }
        }
    }
};

int main() {
    Solution sol;

    vector<int> v1 = {0,1,0,3,12};
    vector<int> v2 = {0};
    vector<int> v3 = {1,2,3};      // no zeros
    vector<int> v4 = {0,0,0,1};

    sol.moveZeroes(v1);
    for (int x : v1) cout << x << " ";
    cout << endl; // 1 3 12 0 0

    sol.moveZeroes(v2);
    for (int x : v2) cout << x << " ";
    cout << endl; // 0

    sol.moveZeroes(v3);
    for (int x : v3) cout << x << " ";
    cout << endl; // 1 2 3

    sol.moveZeroes(v4);
    for (int x : v4) cout << x << " ";
    cout << endl; // 1 0 0 0

    return 0;
}