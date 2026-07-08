#include <vector>
#include <iostream>
using namespace std;

/*
Problem: Best Time to Buy and Sell Stock
Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
Difficulty: Easy
Topic: Arrays, Dynamic Programming

Approach:
- Track minimum price seen so far
- At each day calculate profit if sold today
- Track maximum of all profits seen so far
- Return maxProfit

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice  = prices[0];
        int maxProfit = 0;

        for(int i = 1; i < prices.size(); i++){
            minPrice  = min(minPrice, prices[i]);
            maxProfit = max(maxProfit, prices[i] - minPrice);
        }

        return maxProfit;
    }
};

int main(){
    Solution sol;

    vector<int> v1 = {7,1,5,3,6,4};
    vector<int> v2 = {7,6,4,3,1};
    vector<int> v3 = {2,4,1};
    vector<int> v4 = {1};

    cout << "v1 → " << sol.maxProfit(v1) << endl; // 5
    cout << "v2 → " << sol.maxProfit(v2) << endl; // 0
    cout << "v3 → " << sol.maxProfit(v3) << endl; // 2
    cout << "v4 → " << sol.maxProfit(v4) << endl; // 0

    return 0;
}