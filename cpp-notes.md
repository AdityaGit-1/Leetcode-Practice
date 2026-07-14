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