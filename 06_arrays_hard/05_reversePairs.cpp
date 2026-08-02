#include <vector>
#include <iostream>
using namespace std;

/*
Problem: Reverse Pairs
Link: https://leetcode.com/problems/reverse-pairs/
Difficulty: Hard
Topic: Arrays, Merge Sort, Divide and Conquer

Approach — Modified Merge Sort:
- Count pairs BEFORE merging (array still unsorted within halves)
- countPairs: for each i in left half, find how many j in right
  half satisfy nums[i] > 2*nums[j]
- Use two pointer in countPairs — right pointer never resets
  because both halves are sorted
- Then merge normally to sort for parent calls

Time Complexity: O(n log n)
Space Complexity: O(n)
*/

class Solution {
public:
    void merge(vector<int>& nums, int low, int high, int mid) {
        vector<int> temp;
        int left  = low;
        int right = mid + 1;

        while (left <= mid && right <= high) {
            if (nums[left] <= nums[right]) {
                temp.push_back(nums[left]);  // ✅ value not index
                left++;
            } else {
                temp.push_back(nums[right]); // ✅ value not index
                right++;
            }
        }
        while (left <= mid) {
            temp.push_back(nums[left]);
            left++;
        }
        while (right <= high) {
            temp.push_back(nums[right]);
            right++;
        }

        // ✅ copy back — this was missing
        for (int i = low; i <= high; i++) {
            nums[i] = temp[i - low];
        }
    }

    int countPairs(vector<int>& nums, int low, int high, int mid) {
        int cnt   = 0;
        int right = mid + 1;

        for (int i = low; i <= mid; i++) {
            while (right <= high && nums[i] > 2LL * nums[right])
                right++;
            cnt += (right - (mid + 1));
        }
        return cnt;
    }

    int mergeSort(vector<int>& nums, int low, int high) {
        if (low >= high) return 0;

        int cnt = 0;
        int mid = low + (high - low) / 2;

        cnt += mergeSort(nums, low, mid);
        cnt += mergeSort(nums, mid+1, high);
        cnt += countPairs(nums, low, high, mid); // count BEFORE merge
        merge(nums, low, high, mid);             // then sort

        return cnt;
    }

    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size()-1);
    }
};

int main() {
    Solution sol;

    vector<int> v1 = {1,3,2,3,1};
    vector<int> v2 = {2,4,3,5,1};
    vector<int> v3 = {1,2};
    vector<int> v4 = {-5,-5};

    cout << "v1 → " << sol.reversePairs(v1) << endl; // 2
    cout << "v2 → " << sol.reversePairs(v2) << endl; // 3
    cout << "v3 → " << sol.reversePairs(v3) << endl; // 0
    cout << "v4 → " << sol.reversePairs(v4) << endl; // 0

    return 0;
}