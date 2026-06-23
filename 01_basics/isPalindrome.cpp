#include <iostream>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0 || (x % 10 == 0 && x != 0))
            return false;

        int reversedHalf = 0;

        while (x > reversedHalf) {
            reversedHalf = reversedHalf * 10 + x % 10;
            x /= 10;
        }

        return x == reversedHalf || x == reversedHalf / 10;
    }
};

int main() {
    Solution sol;

    cout << "121  → " << sol.isPalindrome(121)  << endl; // 1
    cout << "-121 → " << sol.isPalindrome(-121) << endl; // 0
    cout << "10   → " << sol.isPalindrome(10)   << endl; // 0
    cout << "0    → " << sol.isPalindrome(0)    << endl; // 1
    cout << "5    → " << sol.isPalindrome(5)    << endl; // 1
    cout << "1221 → " << sol.isPalindrome(1221) << endl; // 1
    cout << "1231 → " << sol.isPalindrome(1231) << endl; // 0

    return 0;
}