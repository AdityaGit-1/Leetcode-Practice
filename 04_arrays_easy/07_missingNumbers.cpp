#include <vector>
#include <iostream>
using namespace std;

/*
Problem: Missing Number
Link: https://leetcode.com/problems/missing-number/
Difficulty: Easy
Topic: Arrays, Math, Bit Manipulation

Approach 1 — Math (optimal):
- Expected sum = n*(n+1)/2
- Missing = expected - actual sum
- Time: O(n), Space: O(1)

Approach 2 — XOR:
- XOR all indices and values
- Paired numbers cancel, missing survives
- Time: O(n), Space: O(1)
*/

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();

        // Approach 1 — Math
        int expected = n * (n+1) / 2;
        int actual   = 0;
        for(int i = 0; i < n; i++)
            actual += nums[i];
        return expected - actual;

        // Approach 2 — XOR (uncomment to use)
        // int result = n;
        // for(int i = 0; i < n; i++)
        //     result ^= i ^ nums[i];
        // return result;
    }
};

int main(){
    Solution sol;

    vector<int> v1 = {3,0,1};
    vector<int> v2 = {0,1};
    vector<int> v3 = {9,6,4,2,3,5,7,0,1};
    vector<int> v4 = {0};

    cout << "v1 → " << sol.missingNumber(v1) << endl; // 2
    cout << "v2 → " << sol.missingNumber(v2) << endl; // 2
    cout << "v3 → " << sol.missingNumber(v3) << endl; // 8
    cout << "v4 → " << sol.missingNumber(v4) << endl; // 1

    return 0;
}