class Solution {
public:
    
    int dp[55][55][55];
    long long mod = 1e9 + 7;
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        memset(dp, -1, sizeof(dp));
        return dfs(startRow, startColumn, maxMove,m,n);
    }
    int dfs(int i,int j, int moves, int m,int n){
         if(moves<0) return 0;       
        if(i>=m || j>=n || i<0 || j<0) return 1;
        
        
        if(dp[i][j][moves] != -1) return dp[i][j][moves];
        
        int down= dfs(i+1,j,moves-1,m,n);
        int up= dfs(i-1,j,moves-1,m,n);
        int right= dfs(i,j+1,moves-1,m,n);
        int left= dfs(i,j-1,moves-1,m,n);
        
        dp[i][j][moves]=(up % mod + down % mod + left % mod + right % mod) % mod;;
        return dp[i][j][moves];
    }
};