#include <vector>
#include <iostream>
using namespace std;

/*
Problem: Majority Element
Link: https://leetcode.com/problems/majority-element/
Difficulty: Easy
Topic: Arrays, Boyer-Moore Voting

Approach — Boyer-Moore Voting Algorithm:
- Maintain a candidate and count
- count==0 → pick current as new candidate
- Same as candidate → count++
- Different → count-- (cancellation)
- Majority element always survives cancellations
  because it appears > n/2 times

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int ele;

        for (int i = 0; i < nums.size(); i++) {
            if (count == 0) {
                count = 1;
                ele   = nums[i];
            }
            else if (nums[i] == ele) count++;
            else count--;
        }

        return ele;
    }
};

int main() {
    Solution sol;

    vector<int> v1 = {3,2,3};
    vector<int> v2 = {2,2,1,1,2,2,2};
    vector<int> v3 = {1};
    vector<int> v4 = {1,1,2,2,1};

    cout << "v1 → " << sol.majorityElement(v1) << endl; // 3
    cout << "v2 → " << sol.majorityElement(v2) << endl; // 2
    cout << "v3 → " << sol.majorityElement(v3) << endl; // 1
    cout << "v4 → " << sol.majorityElement(v4) << endl; // 1

    return 0;
}