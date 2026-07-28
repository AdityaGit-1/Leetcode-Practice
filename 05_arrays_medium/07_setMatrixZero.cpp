#include <vector>
#include <iostream>
using namespace std;

/*
Problem: Set Matrix Zeroes
Link: https://leetcode.com/problems/set-matrix-zeroes/
Difficulty: Medium
Topic: Arrays, Matrix

Approach — O(1) space using first row/col as markers:
- Use first row to mark which columns need zeroing
- Use first col to mark which rows need zeroing
- col0 variable handles column 0 separately
  (matrix[0][0] can't track both row 0 and col 0)

Steps:
1. Scan matrix, mark first row/col, track col0
2. Fill matrix from (1,1) using markers
3. Handle first row using matrix[0][0]
4. Handle first col using col0

Time Complexity: O(m×n)
Space Complexity: O(1)
*/

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int col0 = 1;

        // Step 1 — mark first row and col
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    if (j != 0) matrix[0][j] = 0;
                    else col0 = 0;
                }
            }
        }

        // Step 2 — fill from (1,1)
        for (int i = 1; i < matrix.size(); i++) {
            for (int j = 1; j < matrix[i].size(); j++) {
                if (matrix[i][j] != 0) {
                    if (matrix[i][0] == 0 || matrix[0][j] == 0)
                        matrix[i][j] = 0;
                }
            }
        }

        // Step 3 — handle first row
        if (matrix[0][0] == 0) {
            for (int j = 0; j < matrix[0].size(); j++)
                matrix[0][j] = 0;
        }

        // Step 4 — handle first column
        if (col0 == 0) {
            for (int i = 0; i < matrix.size(); i++)
                matrix[i][0] = 0;
        }
    }
};

int main() {
    Solution sol;

    vector<vector<int>> m1 = {{1,1,1},{1,0,1},{1,1,1}};
    vector<vector<int>> m2 = {{0,1,2,0},{3,4,5,2},{1,3,1,5}};

    sol.setZeroes(m1);
    for (auto& row : m1) {
        for (int x : row) cout << x << " ";
        cout << endl;
    }
    // 1 0 1
    // 0 0 0
    // 1 0 1

    cout << endl;

    sol.setZeroes(m2);
    for (auto& row : m2) {
        for (int x : row) cout << x << " ";
        cout << endl;
    }
    // 0 0 0 0
    // 0 4 5 0
    // 0 3 1 0

    return 0;
}