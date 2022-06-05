class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> dp(n+1,0);
            
            for(int i=1;i<=n;i++){
                    dp[i]= dp[i & (i-1)] + 1;
            }
            return dp;
           //i & i-1 will have one set bit less than i 
    }
};