class Solution {
public:
        
    int minimumTotal(vector<vector<int>>& triangle) {
        int n= triangle.size(); //no of levels
            int maxj= triangle[n-1].size();
            vector<vector<int>> dp(n, vector<int>(maxj,INT_MAX));
            return helper(triangle,n,0,0,dp);
    }
        
        int helper(vector<vector<int>>& triangle,int n, int i,int j,vector<vector<int>>& dp){
              if(i==n) return 0;
                
                 if(dp[i][j]!=INT_MAX) return dp[i][j];
                
                return dp[i][j]= min(helper(triangle,n,i+1,j,dp), helper(triangle,n,i+1,j+1,dp)) + triangle[i][j];
              
                }
};