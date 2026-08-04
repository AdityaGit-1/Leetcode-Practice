#include <iostream>
using namespace std;

/*
Problem: Sqrt(x)
Link: https://leetcode.com/problems/sqrtx/
Difficulty: Easy
Topic: Binary Search, Math

Approach:
- Binary search in range [1, x/2]
- Find largest mid where mid*mid <= x
- Use long long to prevent overflow
- x<2 handled separately (0→0, 1→1)

Time Complexity: O(log n)
Space Complexity: O(1)
*/

class Solution {
public:
    int mySqrt(int x) {
        if (x < 2) return x;

        long long low  = 1;
        long long high = x / 2;
        long long ans  = 0;

        while (low <= high) {
            long long mid = low + (high - low) / 2;

            if (mid * mid <= x) {
                ans = mid;
                low = mid + 1;  // search right for larger valid mid
            } else {
                high = mid - 1; // too large, search left
            }
        }

        return (int)ans;
    }
};

int main() {
    Solution sol;

    cout << "4  → " << sol.mySqrt(4)          << endl; // 2
    cout << "8  → " << sol.mySqrt(8)          << endl; // 2
    cout << "0  → " << sol.mySqrt(0)          << endl; // 0
    cout << "1  → " << sol.mySqrt(1)          << endl; // 1
    cout << "MAX→ " << sol.mySqrt(2147483647) << endl; // 46340

    return 0;
}