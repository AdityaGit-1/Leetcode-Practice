#include <iostream>
#include <climits>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        int rev = 0;

        while (x != 0) {
            int digit = x % 10;
            x /= 10;

            // check overflow BEFORE multiplying
            if (rev > INT_MAX / 10 || 
               (rev == INT_MAX / 10 && digit > 7))
                return 0;
            if (rev < INT_MIN / 10 || 
               (rev == INT_MIN / 10 && digit < -8))
                return 0;

            rev = rev * 10 + digit;
        }

        return rev;
    }
};

int main() {
    Solution sol;

    cout << "123       → " << sol.reverse(123)       << endl; // 321
    cout << "-123      → " << sol.reverse(-123)      << endl; // -321
    cout << "120       → " << sol.reverse(120)       << endl; // 21
    cout << "0         → " << sol.reverse(0)         << endl; // 0
    cout << "1534236469→ " << sol.reverse(1534236469)<< endl; // 0

    return 0;
}