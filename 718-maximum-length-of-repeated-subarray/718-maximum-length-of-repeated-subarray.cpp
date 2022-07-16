class Solution {
public:
    //same as longest common substring
    int dp[1010][1010];
    
    //dp[i][j] tells len of common subarray (at suffix) of nums1 and nums2 when
    //only till i-1 and j-1 indexes of nums1 and nums2 are included
    
    //nums1 = [1,2,3,2,1], nums2 = [3,2,1,4,7]
    //dp[4][2]=2 as nums1[3]==nums2[1]
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int m= nums1.size();
        int n= nums2.size();
        memset(dp,0,sizeof(dp));
        int ans=0;
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(nums1[i-1]==nums2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                    ans=max(ans,dp[i][j]);
                }
            }
        }
        return ans;
    }
};