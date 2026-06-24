#include <vector>
#include <iostream>
using namespace std;

/*
Problem: Find Numbers with Even Number of Digits
Link: https://leetcode.com/problems/find-numbers-with-even-number-of-digits/
Difficulty: Easy
Topic: Arrays, Math

Approach:
- Loop through each number in the array
- Count digits by repeatedly dividing by 10
- If digit count is even, increment result counter

Time Complexity: O(n * log m) — n numbers, log m digits each
Space Complexity: O(1)
*/

class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int digits = 0;
        int flag   = 0;

        for (int i = 0; i < nums.size(); i++) {
            int temp = nums[i];         // use temp to preserve original

            while (temp != 0) {
                digits++;
                temp /= 10;
            }

            if (digits % 2 == 0) flag++;

            digits = 0;                 // reset for next number
        }

        return flag;
    }
};

int main() {
    Solution sol;

    vector<int> v1 = {12, 345, 2, 6, 7896};
    vector<int> v2 = {555, 901, 482, 1771};

    cout << "v1 → " << sol.findNumbers(v1) << endl; // 2
    cout << "v2 → " << sol.findNumbers(v2) << endl; // 1

    return 0;
}