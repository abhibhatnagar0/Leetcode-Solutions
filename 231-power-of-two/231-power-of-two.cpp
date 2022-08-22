class Solution {
public:
    bool isPowerOfTwo(int n) {
       if(n<=1) return n==1;
        return (n&(n-1))==0;
    }
};