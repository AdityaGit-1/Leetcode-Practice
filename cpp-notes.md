## ────────────────────────────────────────
## STEP 1 — BASICS (Completed)
## ────────────────────────────────────────

## Patterns Learned

### Math
- Digit count      → while(n!=0) { digits++; n/=10; }
- Reverse number   → while(x!=0) { rev=rev*10+x%10; x/=10; }
- Reverse half     → while(x>rev) { rev=rev*10+x%10; x/=10; }
                     return x==rev || x==rev/10
- GCD Euclidean    → while(b!=0) { t=b; b=a%b; a=t; } return a
- Power of two     → n>0 && (n & (n-1)) == 0  (bit trick)
- Power of two     → while(n!=1) { if(n%2!=0) return false; n/=2; }

### Recursion
- Fibonacci        → base case: n<=1 return n
                     return fib(n-1) + fib(n-2)
- Reverse string   → two pointer, swap s[i] and s[n-1-i]

### Sorting
- Two pointer merge → i=0 j=0, compare front elements,
                      push smaller, handle leftovers
- Three pointer merge (optimal) →
                      p1=m-1, p2=n-1, p=m+n-1
                      fill from back, place larger element
- Dutch National Flag →
                      low=0, mid=0, high=n-1
                      0→swap(low,mid),low++,mid++
                      1→mid++
                      2→swap(mid,high),high-- (NO mid++)
- Insertion sort   → j=i, while(j>0 && nums[j-1]>nums[j])
                      { swap; j--; }

## My Mistakes & Fixes

### Mistake 1 — Infinite while loop (happened 3 times)
  while(i < j) { swap; }  ← i and j never change = TLE
  Fix → always ask: what line changes the condition variable?
  Rule → every while loop must have something that moves
         it toward termination

### Mistake 2 — Wrong syntax for array assignment
  int s[j] = s[i];  ❌  declares new array
  s[j] = s[i];      ✅  correct assignment

### Mistake 3 — Java habits in C++
  INTEGER.MAX_VALUE  ❌
  INT_MAX            ✅  (needs #include <climits>)
  temp.push()        ❌
  temp.push_back()   ✅  (for vectors)
  nums1.replace()    ❌  doesn't exist
  copy back manually ✅

### Mistake 4 — Wrong temp type for char arrays
  int temp = s[i];   ❌
  char temp = s[i];  ✅

### Mistake 5 — Modifying original array
  while(nums[i] != 0) { nums[i]/=10; }  ❌ destroys original
  int temp = nums[i];
  while(temp != 0) { temp/=10; }        ✅ safe

### Mistake 6 — Loop condition too specific
  while(n != 2)  ❌ misses edge cases like n=0
  while(n != 1)  ✅ correct termination for power of two

### Mistake 7 — Overflow check on wrong variable
  if(x > INT_MAX)  ❌ x is already int, can't overflow
  if(rev > INT_MAX/10)  ✅ check rev BEFORE multiplying

## Headers Reference
  #include <climits>   → INT_MAX, INT_MIN
  #include <cmath>     → sqrt, pow, floor, ceil
  #include <algorithm> → min(a,b), max(a,b), swap(a,b)
  #include <vector>    → vector<int>, push_back, size
  #include <iostream>  → cout, endl

## Interview Talking Points

### Dutch National Flag (Sort Colors)
  "Brute force is O(n log n) sort. Better is
  O(n) two-pass count and refill. Optimal is
  O(n) one-pass Dutch National Flag with three
  pointers — low, mid, high."
  
  Key insight → don't mid++ when swapping with high
  because the swapped element is unchecked

### Merge Sorted Array
  "Fill from the back using three pointers so
  we never overwrite unprocessed elements.
  O(m+n) time, O(1) space."

### Power of Two — bit trick
  "Powers of 2 have exactly one bit set.
  n & (n-1) clears that bit → result is 0
  only for powers of 2."
  n=8  → 1000 & 0111 = 0000 ✓
  n=6  → 0110 & 0101 = 0100 ✗

### Reverse Integer — overflow
  "Check rev > INT_MAX/10 BEFORE multiplying
  by 10 to detect overflow without using long."

## Problems Skipped (come back later)
  #147 Insertion Sort List → needs Linked List knowledge
                           → revisit at Step 5

## ────────────────────────────────────────
## STEP 2 — ARRAYS EASY (Completed)
## ────────────────────────────────────────

## Patterns Learned

### Two Pointer
- Remove duplicates → i tracks last unique,
                      j scans forward
                      nums[i+1]=nums[j] when different
- Move zeroes      → find first zero (i),
                      swap non-zeros to position i,
                      i++ after each swap
                      add: if(i==-1) return for no zeros
- Rotate array     → three reverse trick
                      RIGHT rotate by k → split at n-k
                      LEFT rotate by k  → split at k
                      always: rev(first)+rev(second)+rev(all)

### Hashing
- Contains duplicate → unordered_set early exit
                       if(seen.count(x)) return true
                       insert AFTER checking
- Two Sum           → unordered_map stores {value:index}
                       rem = target - current
                       check rem in map FIRST
                       insert AFTER checking
                       (avoids using same element twice)

### Math / Observation
- Check sorted rotated → count drops where nums[i]>nums[(i+1)%n]
                          drops<=1 → true, else false
                          % n handles wrap-around
- Missing number      → expected = n*(n+1)/2
                          missing = expected - actual sum
- Best time to stock  → track minPrice and maxProfit
                          one pass left to right
                          minPrice = min(minPrice, prices[i])
                          maxProfit = max(maxProfit, prices[i]-minPrice)
- Max consecutive ones → count ones, reset on 0
                          return max(store,count)
                          max() handles array ending with ones

### Sorting
- Sort colors         → Dutch National Flag
                          low=0, mid=0, high=n-1
                          0→swap(low,mid),low++,mid++
                          1→mid++
                          2→swap(mid,high),high--
                          NO mid++ when swapping with high
- Merge sorted array  → three pointer from back
                          p1=m-1, p2=n-1, p=m+n-1
                          fill from back, place larger
                          if nums2 leftover → copy in

## My Mistakes & Fixes

### Mistake 1 — Accessing nums[-1]
  for(int i=0; i<n; i++) nums[i-1]  ❌
  when i=0, i-1=-1 → runtime error
  Fix → start loop from i=1
         OR use % n for wrap-around

### Mistake 2 — Wrong split point for rotation
  int d = k+1  ❌ → this is LEFT rotate
  int d = n-k  ✅ → this is RIGHT rotate
  Rule → RIGHT rotate splits at n-k
          LEFT rotate splits at k

### Mistake 3 — Overwriting maxProfit
  maxProfit = prices[i] - minPrice  ❌
  overwrites previous best profit
  maxProfit = max(maxProfit, prices[i]-minPrice)  ✅

### Mistake 4 — Variable name conflicts
  vector<int> sort = nums  ❌ 'sort' is reserved in C++
  vector<int> sortedArr = nums  ✅ rename it

### Mistake 5 — map vs unordered_map
  map<int,int>          → O(log n) per lookup ❌
  unordered_map<int,int> → O(1) per lookup    ✅
  Always use unordered_map for hashing problems

### Mistake 6 — Not handling no-zeros edge case
  in Move Zeroes if no zeros exist i stays -1
  second loop does nums[-1] → crash
  Fix → if(i==-1) return; after finding first zero

### Mistake 7 — Rotation logic corruption
  trying to undo rotation manually between iterations
  corrupts the array
  Fix → reset to sorted copy at start of each iteration
         OR use the correct split point from the start

## Interview Talking Points

### Two Sum
  "I use a hashmap to store each number and its index
   as I scan. For each element I calculate the remainder
   needed to reach target and check if it's already in
   the map. Insert after checking to avoid using the
   same element twice. O(n) time, O(n) space."

### Best Time to Buy and Sell Stock
  "At each day I ask two questions:
   Is this a new minimum? Update minPrice.
   What profit if I sell today? Update maxProfit.
   One pass is enough because minPrice always holds
   the best buying opportunity seen so far."

### Check Sorted and Rotated
  "A sorted+rotated array has at most one drop point
   where nums[i] > nums[i+1]. Count drops including
   wrap-around using % n. If drops <= 1 → true."

### Sort Colors
  "Dutch National Flag — three pointers low, mid, high.
   0 goes left, 2 goes right, 1 stays in middle.
   Key insight — don't increment mid when swapping
   with high because swapped element is unchecked."

### Missing Number
  "Math formula — expected sum is n*(n+1)/2,
   actual sum from array, difference is missing number.
   O(n) time O(1) space. XOR approach also works."

### Rotate Array
  "Three reverse trick — reverse first n-k elements,
   reverse last k elements, reverse entire array.
   Split point for right rotation is n-k not k."

## New C++ Things Learned

  unordered_map<int,int> mpp  → hash map O(1) lookup
  mpp.find(x) != mpp.end()   → check if key exists
  mpp.find(x) vs mpp.count(x)→ both work, count cleaner
  mpp[key] = value            → insert/update
  max(a,b)                    → needs #include<algorithm>
  auto r = function()         → type inference for return

## Problems Completed — Step 2 Arrays Easy

  ✅ #26   Remove Duplicates from Sorted Array
  ✅ #1752 Check if Array is Sorted and Rotated
  ✅ #217  Contains Duplicate
  ✅ #283  Move Zeroes
  ✅ #189  Rotate Array
  ✅ #121  Best Time to Buy and Sell Stock
  ✅ #268  Missing Number
  ✅ #485  Max Consecutive Ones
  ✅ #1    Two Sum
  
## Step 2 Completed — July 2026

## ────────────────────────────────────────
## STEP 3 — ARRAYS MEDIUM (Completed)
## ────────────────────────────────────────

## Patterns Learned

### Kadane's Algorithm
- Maximum Subarray →
  sum += nums[i]
  ans = max(ans, sum)
  if(sum < 0) sum = 0
  initialize ans = INT_MIN (handles all negative)
  update ans BEFORE resetting sum

- Maximum Product Subarray →
  track BOTH maxProd and minProd
  when nums[i] < 0 → swap(maxProd, minProd)
  maxProd = max(nums[i], maxProd * nums[i])
  minProd = min(nums[i], minProd * nums[i])
  reason: negative × negative = positive
          min can become max after negative

### Voting Algorithm
- Majority Element →
  Boyer-Moore Voting
  count==0 → new candidate
  same → count++
  different → count--
  works because majority > n/2 times

### Hashing / Prefix Sum
- Subarray Sum = K →
  preSum + hashmap
  mpp[0]=1 (handles subarrays from index 0)
  remove = preSum - k
  count += mpp[remove]
  mpp[preSum]++ AFTER count update
  use unordered_map not map

- Longest Consecutive →
  insert all into unordered_set
  only start counting from sequence START
  (check st.find(it-1) == st.end())
  while(st.find(x+1) != st.end()) extend

### Matrix Problems
- Set Matrix Zeroes O(1) space →
  use first row/col as markers
  col0 variable tracks column 0 separately
  (matrix[0][0] can't track both row 0 and col 0)
  fill from (1,1) in second pass
  handle row 0 and col 0 last

- Rotate Image 90° clockwise →
  transpose (swap matrix[i][j] with matrix[j][i])
  j starts at i+1 to avoid double swap
  then reverse each row
  anti-clockwise → reverse rows first then transpose

- Spiral Matrix →
  four boundaries: top, bottom, left, right
  traverse: right → down → left → up
  shrink boundary AFTER each traversal
  top++ and right-- OUTSIDE their loops
  check top<=bottom before left traversal
  check left<=right before up traversal
  going left → i>=left (not i<=left)
  going up   → i>=top  (not i<=top)

### Two Index / Placement
- Rearrange Array by Sign →
  posIndex=0, negIndex=1, both += 2
  vector<int> ans(n) → parentheses not brackets
  O(1) space impossible here (relative order must preserve)

### Permutation
- Next Permutation →
  Step 1: find rightmost dip (nums[i] < nums[i+1])
  Step 2: if no dip → reverse all (smallest permutation)
  Step 3: find rightmost element > nums[index]
  Step 4: swap them
  Step 5: reverse suffix after index
  suffix is always descending → reversing gives smallest

## My Mistakes & Fixes

### Mistake 1 — Variable scoping with 'int' keyword
  if(condition) {
      int x = value;  ❌ new LOCAL variable
      int cnt = 1;    ❌ dies after closing brace
  }
  // fix — remove 'int' to use outer variable:
  if(condition) {
      x = value;  ✅ updates outer x
      cnt = 1;    ✅ updates outer cnt
  }

### Mistake 2 — Boundary update inside loop
  for(int i=left; i<=right; i++){
      ans.push_back(matrix[top][i]);
      top++;  ❌ increments top n times
  }
  // fix — move boundary update outside:
  for(int i=left; i<=right; i++)
      ans.push_back(matrix[top][i]);
  top++;  ✅

### Mistake 3 — Wrong loop direction
  for(int i=right; i<=left; i--)  ❌ never executes
  for(int i=right; i>=left; i--)  ✅ going left
  for(int i=bottom; i<=top; i--)  ❌ never executes
  for(int i=bottom; i>=top; i--)  ✅ going up
  Rule: going left/up → use >= not <=

### Mistake 4 — vector declaration syntax
  vector<int> ans[nums.size()]  ❌ array of vectors
  vector<int> ans(nums.size())  ✅ vector of n ints
  Rule: [] = array, () = size/constructor

### Mistake 5 — map vs unordered_map (repeated)
  map<int,int>           → O(log n) ❌
  unordered_map<int,int> → O(1)     ✅
  Always use unordered_map for hashing problems

### Mistake 6 — Reset logic differs for sum vs product
  Sum Kadane:     reset to 0 when negative
                  (negative sum always hurts)
  Product Kadane: track BOTH max and min
                  (negative × negative = positive)
                  swap max/min when current < 0

## Interview Talking Points

### Kadane's Algorithm
  "Initialize ans=INT_MIN to handle all-negative.
   Key: update ans BEFORE resetting sum to 0.
   Resetting works because negative prefix
   can never help future subarrays."

### Maximum Product Subarray
  "Extension of Kadane's — track both max and min
   because negative × negative = positive.
   Swap max and min when current element is negative."

### Boyer-Moore Voting
  "Majority element appears > n/2 times so it
   survives all cancellations. Each non-majority
   element cancels one majority element at most."

### Subarray Sum = K
  "Prefix sum + hashmap. preSum[j]-preSum[i]=k
   means subarray i+1 to j sums to k.
   So check if preSum-k exists in map.
   mpp[0]=1 handles subarrays starting from 0."

### Set Matrix Zeroes
  "O(1) space: use first row/col as markers.
   matrix[0][0] tracks row 0.
   col0 variable tracks col 0 separately.
   Fill from (1,1) to avoid corrupting markers."

### Rotate Image
  "Transpose then reverse each row = 90° clockwise.
   Reverse each row then transpose = anti-clockwise."

### Next Permutation
  "Find rightmost dip, swap with rightmost greater,
   reverse suffix. Suffix is always descending so
   reversing gives smallest next arrangement."

### Spiral Matrix
  "Four shrinking boundaries. Boundary updates
   go OUTSIDE their loops. Going left/up needs
   >= comparison not <=."

## New C++ Things Learned

  swap(a, b)              → swaps two values in place
  auto it : container     → range based for loop
  st.find(x) == st.end()  → element NOT in set
  st.find(x) != st.end()  → element IS in set
  matrix[i].size()        → columns of row i
  matrix.size()           → number of rows
  reverse(v.begin()+i, v.end()) → reverse from index i

## Problems Completed — Step 3 Arrays Medium

  ✅ #75   Sort Colors
  ✅ #169  Majority Element
  ✅ #53   Maximum Subarray
  ✅ #152  Maximum Product Subarray
  ✅ #2149 Rearrange Array Elements by Sign
  ✅ #31   Next Permutation
  ✅ #128  Longest Consecutive Sequence
  ✅ #73   Set Matrix Zeroes
  ✅ #48   Rotate Image
  ✅ #54   Spiral Matrix
  ✅ #560  Subarray Sum Equals K
  ⏭️ #229  Majority Element II → pending

## Step 3 Completed — July 2026

## ────────────────────────────────────────
## STEP 4 — ARRAYS HARD (Completed)
## ────────────────────────────────────────

## Patterns Learned

### nCr Formula
- Pascal's Triangle →
  element = prev * (row-col) / col
  start each row with 1
  use long long for element to avoid overflow
  divide AFTER multiply (integer division works
  because nCr is always integer)

### Extended Boyer-Moore (Two Candidates)
- Majority Element II →
  at most 2 elements appear > n/3 times
  track el1, el2 and count1, count2
  el2 = INT_MIN to avoid initial conflict
  when assigning el1 → check el2 != current
  when assigning el2 → check el1 != current
  decrement both when neither matches
  ALWAYS verify in second pass
  mini = n/3 + 1 threshold

### Two Pointer with Sorting
- 3Sum →
  sort first
  fix i, two pointer j and k
  skip duplicate i: i>0 && nums[i]==nums[i-1]
  skip duplicate j and k after finding triplet
  sum<0 → j++, sum>0 → k--

- 4Sum →
  same as 3Sum but two fixed pointers i and j
  j duplicate skip: j!=i+1 && nums[j]==nums[j-1]
  use long long — 4 values can overflow int
  cast: (long long)nums[i] + nums[j] + nums[k] + nums[l]

### Greedy
- Merge Intervals →
  sort by start time
  if ans empty OR start > last end → push new
  else → merge: end = max(last end, current end)
  max() handles contained intervals correctly

### Modified Merge Sort
- Reverse Pairs →
  count pairs BEFORE merging (halves still sorted)
  countPairs: two pointer, right never resets
  because as i increases threshold only gets harder
  use 2LL to prevent overflow: nums[i] > 2LL*nums[right]
  merge normally AFTER counting

## My Mistakes & Fixes

### Mistake 1 — Pushing index instead of value in merge
  temp.push_back(left)       ❌ pushes index number
  temp.push_back(nums[left]) ✅ pushes actual value
  Rule: always push nums[index] not index itself

### Mistake 2 — Forgetting to copy temp back to nums
  merge function built temp but never wrote back ❌
  Fix: for(int i=low; i<=high; i++) nums[i]=temp[i-low]
  Without this: array never actually sorted
  countPairs on parent level gets wrong data

### Mistake 3 — int overflow with multiplication
  2 * nums[right]    ❌ can overflow if nums[right] ~ 10^9
  2LL * nums[right]  ✅ forces long long multiplication
  Same for 4Sum: use (long long) cast on first element

### Mistake 4 — Dead variable declaration
  int sum = 0; outside loop  ❌ unused, dead code
  int sum = ... inside loop  ✅ only declare where used
  Rule: declare variables as close to use as possible

### Mistake 5 — j duplicate skip condition
  if(nums[j]==nums[j-1]) continue          ❌
  skips valid first j when nums[i]==nums[i+1]
  if(j!=i+1 && nums[j]==nums[j-1]) continue ✅
  j!=i+1 protects first iteration of j

## Interview Talking Points

### Pascal's Triangle
  "nCr formula: next = prev*(row-col)/col
   Avoids factorial computation.
   Use long long for intermediate values.
   Divide after multiply — integer division
   works because nCr is always integer."

### Majority Element II
  "At most 2 elements appear > n/3 times.
   Extended Boyer-Moore tracks two candidates.
   Critical: check other candidate before assigning
   to avoid both being same element.
   Always verify with second pass."

### 3Sum
  "Sort then fix i, two pointer j and k.
   Skip duplicates at three levels — i, j, k.
   O(n²) time O(1) space."

### 4Sum
  "Extension of 3Sum — two fixed pointers.
   long long prevents overflow.
   j!=i+1 check for correct duplicate skipping.
   O(n³) time O(1) space."

### Merge Intervals
  "Sort by start. Greedy scan:
   no overlap → push new interval.
   overlap → extend end with max().
   max() handles contained intervals."

### Reverse Pairs
  "Modified merge sort.
   Count pairs BEFORE merging while halves sorted.
   Two pointer in countPairs — right never resets.
   2LL prevents overflow.
   O(n log n) time O(n) space."

## New C++ Things Learned

  2LL * x              → forces long long multiplication
  (long long)a + b     → cast first operand to long long
  ans.back()           → reference to last element of vector
  ans.back()[1]        → modify last interval's end in place
  sort(v.begin(),v.end()) → sorts vector of vectors by first element
  intervals[i][0]      → first element of i-th interval
  intervals[i][1]      → second element of i-th interval

## Problems Completed — Step 4 Arrays Hard

  ✅ #118  Pascal's Triangle
  ✅ #229  Majority Element II
  ✅ #15   3Sum
  ✅ #18   4Sum
  ✅ #56   Merge Intervals
  ✅ #493  Reverse Pairs
  ⏭️ #152  Maximum Product Subarray → done in Step 3

## Step 4 Completed — August 2026