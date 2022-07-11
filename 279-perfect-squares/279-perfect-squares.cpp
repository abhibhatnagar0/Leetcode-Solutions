class Solution {
public:
    int numSquares(int n) {
        if(n==0 || n==1 || n==2 || n==3) return n;
     vector<int> dp(n+1,1e4 + 1);   
        dp[0]=0;
        dp[1]=1;
        dp[2]=2;
        dp[3]=3;
        for(int i=4;i<=n;i++){
            for(int j=1; j*j<=i;j++){
                dp[i]= min(dp[i],dp[i-j*j]+1);
            }
        }
        return dp[n];
    }
};