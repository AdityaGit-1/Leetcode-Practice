#include <vector>
#include <iostream>
using namespace std;

/*
Problem: Reverse String
Link: https://leetcode.com/problems/reverse-string/
Difficulty: Easy
Topic: Two Pointers, Strings

Approach:
- Two pointers — one at start, one at end
- Swap characters and move pointers inward
- Stop when pointers meet or cross

Time Complexity: O(n)
Space Complexity: O(1) — in-place
*/

class Solution {
public:
    void reverseString(vector<char>& s) {
        int i = 0;
        int j = s.size() - 1;

        while (i < j) {
            char temp = s[i];
            s[i] = s[j];
            s[j] = temp;
            i++;
            j--;
        }
    }
};

int main() {
    Solution sol;

    vector<char> v1 = {'h','e','l','l','o'};
    vector<char> v2 = {'H','a','n','n','a','h'};

    sol.reverseString(v1);
    sol.reverseString(v2);

    cout << "v1 → ";
    for (char c : v1) cout << c;
    cout << endl; // olleh

    cout << "v2 → ";
    for (char c : v2) cout << c;
    cout << endl; // hannaH

    return 0;
}