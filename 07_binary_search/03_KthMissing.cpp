#include <vector>
#include <iostream>
using namespace std;

/*
Problem: Kth Missing Positive Number
Link: https://leetcode.com/problems/kth-missing-positive-number/
Difficulty: Easy
Topic: Binary Search

Approach — Binary Search O(log n):
- At index i: missing = arr[i]-(i+1) = count of missing numbers
- Binary search for first index where missing >= k
- After loop: low = that index
- Answer = low + k (elegant simplification)

Why low+k works:
arr[low-1] + (k - missing_before_arr[low-1])
= arr[low-1] + k - (arr[low-1] - low)
= low + k

Time Complexity: O(log n)
Space Complexity: O(1)
*/

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int low  = 0;
        int high = arr.size() - 1;

        while (low <= high) {
            int mid     = low + (high - low) / 2;
            int missing = arr[mid] - (mid + 1);

            if (missing < k) low  = mid + 1;
            else             high = mid - 1;
        }

        return low + k;
    }
};

int main() {
    Solution sol;

    vector<int> v1 = {2,3,4,7,11};
    vector<int> v2 = {1,2,3,4};
    vector<int> v3 = {1,2,3,4};
    vector<int> v4 = {2};

    cout << "v1 k=5 → " << sol.findKthPositive(v1,5) << endl; // 9
    cout << "v2 k=2 → " << sol.findKthPositive(v2,2) << endl; // 6
    cout << "v3 k=1 → " << sol.findKthPositive(v3,1) << endl; // 5
    cout << "v4 k=1 → " << sol.findKthPositive(v4,1) << endl; // 1

    return 0;
}   