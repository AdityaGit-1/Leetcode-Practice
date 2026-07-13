#include <vector>
#include <iostream>
using namespace std;

/*
Problem: Max Consecutive Ones
Link: https://https://leetcode.com/problems/max-consecutive-ones/
Difficulty: Easy
Topic: Arrays, Math,

Approach 1 — Math (optimal):
- Counting ones and storing the max value of count
- Time: O(n), Space: O(1)
*/

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0;
        int store = 0;
        for (int i=0 ; i<nums.size() ; i++){
            if (nums[i]==1) count++;
            if (nums[i]!=1){
                if (store<count){
                    store = count;
                }
                count = 0;
            }
        }
        return max(store,count);
    }
};

int main(){
    Solution sol;

    vector<int> v1 = {1,1,0,1,1,1};
    vector<int> v2 = {1,0,1,1,0,1};

    cout << "v1 → " << sol.findMaxConsecutiveOnes(v1) << endl; // 3
    cout << "v2 → " << sol.findMaxConsecutiveOnes(v2) << endl; // 2
    return 0;
}