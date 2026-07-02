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
