class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>>dp(2,vector<int>(n,0));
        //dp[i][j] gives length of max sq that can be made using matrix[i][j] as 
        //bottom right element
        int maxlen = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 || j==0) dp[i%2][j]= matrix[i][j]=='1'? 1 : 0;
                else{
                    if(matrix[i][j]=='1')
                    dp[i%2][j]= 1 + min(dp[(i-1)%2][j],min(dp[i%2][j-1],dp[(i-1)%2][j-1]));
                    else{
                        dp[i%2][j]=0;
                    }
                }
                maxlen= max(maxlen,dp[i%2][j]);
            }
        }
        return maxlen*maxlen;
    }
};