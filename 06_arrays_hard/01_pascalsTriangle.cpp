#include <vector>
#include <iostream>
using namespace std;

/*
Problem: Pascal's Triangle
Link: https://leetcode.com/problems/pascals-triangle/
Difficulty: Easy
Topic: Arrays, Math

Approach — nCr formula:
- Each element in row r at col c = nCr(r-1, c)
- Instead of computing nCr from scratch each time:
  next element = prev * (row-col) / col
- This avoids factorial computation and overflow risk

Time Complexity: O(n²)
Space Complexity: O(1) extra space per row
*/

class Solution {
public:
    vector<int> generateRow(int row) {
        long long element = 1;
        vector<int> ans;
        ans.push_back(1);

        for (int col = 1; col < row; col++) {
            element = element * (row - col);
            element /= col;
            ans.push_back((int)element);
        }

        return ans;
    }

    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;

        for (int i = 1; i <= numRows; i++) {
            ans.push_back(generateRow(i));
        }

        return ans;
    }
};

int main() {
    Solution sol;

    auto r1 = sol.generate(5);
    auto r2 = sol.generate(1);

    for (auto& row : r1) {
        for (int x : row) cout << x << " ";
        cout << endl;
    }
    // 1
    // 1 1
    // 1 2 1
    // 1 3 3 1
    // 1 4 6 4 1

    cout << endl;

    for (auto& row : r2) {
        for (int x : row) cout << x << " ";
        cout << endl;
    }
    // 1

    return 0;
}