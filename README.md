# DSA Practice — Striver A2Z Sheet + LeetCode

Solving Data Structures and Algorithms problems 
topic by topic following Striver's A2Z DSA Course 
Sheet. Every solution is written from scratch after 
a genuine attempt — no copy-paste.

## 👤 Profiles
- 🔗 LeetCode: [your-username](https://leetcode.com/u/Aditya_199153/)
- 🔗 GitHub: [your-username](https://github.com/AdityaGit-1)

## 📂 Folder Structure

\`\`\`
dsa-practice/
├── 01_basics/
│   ├── isPalindrome.cpp
│   ├── reverseInteger.cpp
│   ├── findGCD.cpp
│   ├── findEvenDigits.cpp
│   ├── commonFactors.cpp
│   ├── fibonacci.cpp
│   ├── powerOfTwo.cpp
│   ├── reverseString.cpp
│   ├── mergeSortedArray.cpp
│   └── sortColors.cpp
├── 02_arrays_easy/
│   ├── removeDuplicates.cpp
│   ├── checkSortedRotated.cpp
│   ├── containsDuplicate.cpp
│   ├── moveZeroes.cpp
│   ├── rotateArray.cpp
│   ├── bestTimeToBuyStock.cpp
│   ├── missingNumber.cpp
│   ├── maxConsecutiveOnes.cpp
│   └── twoSum.cpp
├── 03_arrays_medium/
│   ├── sortColors.cpp
│   ├── majorityElement.cpp
│   ├── majorityElementII.cpp
│   ├── maximumSubarray.cpp
│   ├── maximumProductSubarray.cpp
│   ├── rearrangeArrayBySign.cpp
│   ├── nextPermutation.cpp
│   ├── longestConsecutiveSequence.cpp
│   ├── setMatrixZeroes.cpp
│   ├── rotateImage.cpp
│   ├── spiralMatrix.cpp
│   └── subarraySumEqualsK.cpp
├── 04_arrays_hard/
│   ├── pascalsTriangle.cpp
│   ├── majorityElementII.cpp
│   ├── threeSum.cpp
│   ├── fourSum.cpp
│   ├── mergeIntervals.cpp
│   └── reversePairs.cpp
├── 05_binary_search/
├── 06_strings/
├── 07_linked_list/
├── 08_recursion_backtracking/
├── 09_hashing/
├── 10_stack_queue/
├── 11_trees/
├── 12_graphs/
├── 13_dynamic_programming/
└── cpp-notes.md
\`\`\`

## 📊 Progress

| Step | Topic                   | Solved | Total | Status     | Completed  |
|------|-------------------------|--------|-------|------------|------------|
| 1    | Basics                  | 11     | 12    | ✅ Done    | July 2026  |
| 2    | Arrays Easy             | 9      | 9     | ✅ Done    | July 2026  |
| 3    | Arrays Medium           | 11     | 11    | ✅ Done    | July 2026  |
| 4    | Arrays Hard             | 6      | 6     | ✅ Done    | July 2026  |
| 5    | Binary Search           | 0      | 12    | 🔄 Next    | —          |
| 6    | Strings                 | 0      | 8     | ⏳ Pending | —          |
| 7    | Linked List             | 0      | 14    | ⏳ Pending | —          |
| 8    | Recursion & Backtrack   | 0      | 11    | ⏳ Pending | —          |
| 9    | Hashing                 | 0      | 6     | ⏳ Pending | —          |
| 10   | Stack & Queue           | 0      | 10    | ⏳ Pending | —          |
| 11   | Trees                   | 0      | 17    | ⏳ Pending | —          |
| 12   | Graphs                  | 0      | 11    | ⏳ Pending | —          |
| 13   | Dynamic Programming     | 0      | 17    | ⏳ Pending | —          |
|      | **Total**               | **37** | **134**| —         | —          |

## 🏆 Milestones

✅ Step 1 — Basics → July 2026
✅ Step 2 — Arrays Easy → July 2026
✅ Step 3 — Arrays Medium → July 2026
✅ Step 4 — Arrays Hard → July 2026
🔄 Step 5 — Binary Search → In progress

## 📝 Solution Format

Every solution file follows this structure:

\`\`\`cpp
/*
Problem: Two Sum
Link: https://leetcode.com/problems/two-sum/
Difficulty: Easy
Topic: Arrays, Hashing

Approach:
- Brief explanation of approach

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    // solution here
};

int main() {
    // test cases here
}
\`\`\`

## 🔁 Daily Workflow

\`\`\`
Watch Striver video
        ↓
Attempt problem (20-30 min, no hints)
        ↓
If stuck → read approach only,
           close it, code from scratch
        ↓
Test locally on Codespaces
        ↓
Submit on LeetCode
        ↓
Commit with meaningful message
\`\`\`

## 🧠 Key Patterns Learned

| Pattern | Code | Problems |
|---------|------|----------|
| Digit count | `while(n!=0){d++;n/=10;}` | Find Even Digits |
| GCD | `while(b!=0){t=b;b=a%b;a=t;}` | Find GCD |
| Two pointer | `i=0,j=n-1→swap→i++,j--` | Reverse String |
| Power of 2 | `n>0&&(n&(n-1))==0` | Power of Two |
| Dutch Flag | `low,mid,high→3 cases` | Sort Colors |
| Three reverse | `rev(0,d)+rev(d,n)+rev(0,n)` | Rotate Array |
| Min tracking | `min=p[0],profit=max(profit,p[i]-min)` | Buy Stock |
| Count drops | `if(nums[i]>nums[(i+1)%n])drops++` | Check Sorted |
| Math formula | `n*(n+1)/2 - actual` | Missing Number |
| Early exit set | `if(seen.count(x))return true` | Contains Duplicate |
| Kadane's | `sum+=x,ans=max(ans,sum),if(sum<0)sum=0` | Max Subarray |
| Track max+min | `swap(max,min) when negative` | Max Product |
| Boyer-Moore | `count==0→new candidate` | Majority Element |
| Two candidates | `el1,el2 with INT_MIN init` | Majority Element II |
| Prefix sum | `mpp[0]=1,remove=preSum-k` | Subarray Sum=K |
| nCr formula | `elem=prev*(row-col)/col` | Pascal's Triangle |
| Sort+2ptr | `fix i,j=i+1,k=n-1` | 3Sum, 4Sum |
| Greedy merge | `end=max(last,current)` | Merge Intervals |
| Merge sort count | `countPairs before merge` | Reverse Pairs |
| Next permutation | `find dip,swap,reverse suffix` | Next Permutation |
| Spiral matrix | `4 boundaries shrink inward` | Spiral Matrix |
| Transpose+rev | `swap[i][j][j][i] then rev rows` | Rotate Image |
| Markers O(1) | `use first row/col as markers` | Set Matrix Zeroes |
| Consecutive seq | `only start from seq beginning` | Longest Consecutive |

## 💬 Commit Convention

\`\`\`
solve: problem name - approach O(complexity)
refactor: problem name - what changed
docs: updated README progress
skip: problem name - reason
\`\`\`

## ⚠️ Common C++ Mistakes Fixed

\`\`\`
INTEGER.MAX_VALUE  ❌ → INT_MAX (#include <climits>) ✅
push()             ❌ → push_back() ✅
int s[j]=s[i]      ❌ → s[j]=s[i] ✅
int temp for char  ❌ → char temp ✅
vector<int> v[n]   ❌ → vector<int> v(n) ✅
sort (variable)    ❌ → sortedArr (rename) ✅
map<int,int>       ❌ → unordered_map<int,int> ✅
while(no change)   ❌ → always change condition var ✅
nums.begin()-d     ❌ → nums.begin()+d ✅
nums.size() in rev ❌ → nums.end() ✅
push index         ❌ → push nums[index] ✅
forget copy back   ❌ → copy temp to nums after merge ✅
int * int overflow ❌ → 2LL * nums[i] ✅
int x=val in block ❌ → x=val (no int keyword) ✅
i<=left going left ❌ → i>=left ✅
i<=top going up    ❌ → i>=top ✅
boundary++ in loop ❌ → boundary++ outside loop ✅
\`\`\`

## 🛠️ Language
C++ with STL

## 📅 Timeline
- Started: June 2026
- Step 1 Basics completed: July 2026
- Step 2 Arrays Easy completed: July 2026
- Step 3 Arrays Medium completed: July 2026
- Step 4 Arrays Hard completed: July 2026

## 🎯 Goal
Crack off-campus placements at 12-20 LPA product 
companies by following Striver's A2Z DSA sheet 
with consistent daily practice.

---

> "Knowing DSA theory but never practicing on 
> LeetCode is the most common trap freshers fall 
> into. Interviewers don't ask you to define a 
> Linked List — they ask you to reverse it in 
> place under a time limit."