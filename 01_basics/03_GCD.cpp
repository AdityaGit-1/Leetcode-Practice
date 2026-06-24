/*Problem #1979
  1. Loop termination — always ask 
   "what changes inside this loop to make 
   it eventually stop?" before writing any 
   while loop

2. Euclidean algorithm 
   while(b != 0) { 
      int t=b; b=a%b; a=t; 
    }
   return a;
   need this in multiple problems

3. no need to reach for sorting when you just 
   need min/max — one loop is always enough
*/






#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int findGCD(vector<int>& nums) {
        // Step 1 — find smallest and largest
        int smallest = nums[0];
        int largest  = nums[0];

        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] < smallest) smallest = nums[i];
            if(nums[i] > largest)  largest  = nums[i];
        }

        // Step 2 — Euclidean algorithm
        while(smallest != 0) {
            int temp  = smallest;
            smallest  = largest % smallest;
            largest   = temp;
        }

        return largest;
    }
};

int main() {
    Solution sol;

    vector<int> v1 = {2,5,6,9,10};
    vector<int> v2 = {7,5,6,8,3};

    cout << "v1 → " << sol.findGCD(v1) << endl; // 2
    cout << "v2 → " << sol.findGCD(v2) << endl; // 1

    return 0;
}