class Solution {
public:
    int hammingWeight(uint32_t n) {
        int cnt=0;
            while(n>0){
                    n=n&(n-1);  //n&(n-1) has one set bit less than n
                    cnt++;      // so no of iterations= no of set bits
            }
            return cnt;
            // can take max 32 iterations of loop ie o(logn) in worst case
    }
};