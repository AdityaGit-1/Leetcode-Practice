#include <iostream>
using namespace std;

/*
Problem: Power of Two
Link: https://leetcode.com/problems/power-of-two/
Difficulty: Easy
Topic: Math, Bit Manipulation

Approach 1 — Loop:
- If n <= 0 return false
- Keep dividing by 2, if remainder != 0 return false
- If we reach 1, it's a power of two

Approach 2 — Bit manipulation (optimal):
- Powers of 2 have exactly one bit set
- n & (n-1) clears that bit → result is 0
- One line, O(1)

Time Complexity: O(log n) — Approach 1
                 O(1)     — Approach 2
Space Complexity: O(1) both
*/

class Solution {
public:
    bool isPowerOfTwo(int n) {
        // Approach 1 — Loop
        if (n <= 0) return false;

        while (n != 1) {
            if (n % 2 != 0) return false;
            n /= 2;
        }
        return true;

        // Approach 2 — Bit manipulation (one line)
        // return n > 0 && (n & (n - 1)) == 0;
    }
};

int main() {
    Solution sol;

    cout << "1  → " << sol.isPowerOfTwo(1)  << endl; // 1
    cout << "16 → " << sol.isPowerOfTwo(16) << endl; // 1
    cout << "3  → " << sol.isPowerOfTwo(3)  << endl; // 0
    cout << "0  → " << sol.isPowerOfTwo(0)  << endl; // 0
    cout << "-4 → " << sol.isPowerOfTwo(-4) << endl; // 0

    return 0;
}