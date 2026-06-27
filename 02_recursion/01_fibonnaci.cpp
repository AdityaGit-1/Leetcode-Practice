/*---------Leetcode Problem #509------------
   Problem Link - https://leetcode.com/problems/fibonacci-number/description/ 
*/


class Solution {
public:
    int fib(int n) {
        int last = 1 , secondLast = 0;
        int fibonn = 0;
        if (n==0) fibonn = 0;
        if (n==1) fibonn = 1;
        for (int i=2 ; i<=n ; i++){
             fibonn = last + secondLast;
             secondLast = last;
             last = fibonn ;
        }
        return fibonn;

    }
};