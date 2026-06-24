/*
LeetCode 2427 - Number of Common Factors

Approach:
1. Find the smaller of the two numbers.
2. Iterate from 1 to the smaller number.
3. Count numbers that divide both a and b.

Time Complexity: O(min(a, b))
Space Complexity: O(1)
*/

class Solution {
public:
    int commonFactors(int a, int b) {
        int count = 0;
        int smaller = (a < b) ? a : b;

        for (int i = 1; i <= smaller; i++) {
            if (a % i == 0 && b % i == 0) {
                count++;
            }
        }

        return count;
    }
};