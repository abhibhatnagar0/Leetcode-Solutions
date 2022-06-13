class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n= triangle.size(); //no of levels
        int maxj= triangle[n-1].size();   
           vector<int> dp(n);
              for(int j=0;j<maxj;j++){
                      dp[j]= triangle[n-1][j];
              }
            
            for(int i=n-2;i>=0;i--){
                    for(int j=0;j<triangle[i].size();j++){
                        dp[j]=min(dp[j],dp[j+1])+ triangle[i][j];
                    }
            }
            return dp[0];
    }
        //bottom up approach
        // space o(n), time o(n2)
        //no modification done in original vector
};