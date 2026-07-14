#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

/*
Problem: Two Sum
Link: https://leetcode.com/problems/two-sum/
Difficulty: Easy
Topic: Arrays, Hashing

Approach:
- Use unordered_map to store each number and its index
- For each element calculate remainder = target - current
- If remainder exists in map → found the pair
- Add current element to map AFTER checking
  (avoids using same element twice)

Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mpp;

        for (int i = 0; i < nums.size(); i++) {
            int a   = nums[i];
            int rem = target - a;

            if (mpp.find(rem) != mpp.end()) {
                return {mpp[rem], i};
            }

            mpp[a] = i;
        }

        return {-1, -1};
    }
};

int main() {
    Solution sol;

    vector<int> v1 = {2,7,11,15};
    vector<int> v2 = {3,2,4};
    vector<int> v3 = {3,3};

    auto r1 = sol.twoSum(v1, 9);
    auto r2 = sol.twoSum(v2, 6);
    auto r3 = sol.twoSum(v3, 6);

    cout << "v1 → [" << r1[0] << "," << r1[1] << "]" << endl; // [0,1]
    cout << "v2 → [" << r2[0] << "," << r2[1] << "]" << endl; // [1,2]
    cout << "v3 → [" << r3[0] << "," << r3[1] << "]" << endl; // [0,1]

    return 0;
}