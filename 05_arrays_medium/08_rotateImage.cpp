#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

/*
Problem: Rotate Image
Link: https://leetcode.com/problems/rotate-image/
Difficulty: Medium
Topic: Arrays, Matrix, Math

Approach — Transpose + Reverse:
- Step 1: Transpose matrix (swap matrix[i][j] with matrix[j][i])
          j starts at i+1 to avoid swapping back
- Step 2: Reverse each row
- Result: 90° clockwise rotation in O(1) space

Anti-clockwise rotation:
- Reverse each row first, then transpose

Time Complexity: O(n²)
Space Complexity: O(1)
*/

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // Step 1 — transpose
        for (int i = 0; i < matrix.size()-1; i++) {
            for (int j = i+1; j < matrix[i].size(); j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // Step 2 — reverse each row
        for (int i = 0; i < matrix.size(); i++) {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};

int main() {
    Solution sol;

    vector<vector<int>> m1 = {{1,2,3},{4,5,6},{7,8,9}};
    vector<vector<int>> m2 = {{5,1,9,11},{2,4,8,10},
                               {13,3,6,7},{15,14,12,16}};

    sol.rotate(m1);
    for (auto& row : m1) {
        for (int x : row) cout << x << " ";
        cout << endl;
    }
    // 7 4 1
    // 8 5 2
    // 9 6 3

    cout << endl;

    sol.rotate(m2);
    for (auto& row : m2) {
        for (int x : row) cout << x << " ";
        cout << endl;
    }
    // 15 13 2 5
    // 14 3  4 1
    // 12 6  8 9
    // 16 7 10 11

    return 0;
}