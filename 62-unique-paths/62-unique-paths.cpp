class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m==1 || n==1) return 1;
        vector<vector<int>>dp(2,vector<int>(n,1));
        // dp[i][j] gives no of unique paths from (0,0) to (i,j)
        // dp[0][any no]=1
        // dp[any no][0]=1
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                dp[i%2][j]= dp[(i-1)%2][j]+ dp[i%2][j-1];
            }
        }
        return dp[(m-1)%2][n-1];
    }
};