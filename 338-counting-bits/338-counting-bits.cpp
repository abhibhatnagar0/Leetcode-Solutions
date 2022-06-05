class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> dp(n+1,0);
            
            for(int i=1;i<=n;i++){
                    if(i&1==1) //if i is odd
                    dp[i]= dp[i>>1] + 1;  //dp[i]= dp[i/2]+1
                    else
                            dp[i]= dp[i>>1]; //dp[i]= dp[i/2]
            }
            //for i=even, right shift of i/2 gives same set bits
            //for i=7, set bits of 3 are equal to set bits of 6, adding 1 for 7 (even+1 me extra bit)
            return dp;
           
    }
};