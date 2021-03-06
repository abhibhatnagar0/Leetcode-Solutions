class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
            vector<int> dp(10001,-1);
            dp[n-1]=0; // dp[i] stores no of min jumps req from ith index to reach n-1 index
            for(int i=n-2;i>=0;i--){
                    if(i+nums[i]>=n-1) dp[i]=1; // at ith index, we can go upto i+nums[i]
                    else{              
                            //going from i to j in 1 jump and then j to n-1 ...dp[i]=1+dp[j]
                            int reach=i+nums[i];
                            int j=i+1;
                            int minJumps=INT_MAX; // stores minJumps from j to n-1
                            while(j<=reach){  
                                    if(dp[j]!=-1)
                                minJumps=min(minJumps,dp[j]);
                                    j++;
                            }
                            if(minJumps!=INT_MAX)
                                dp[i]=1+minJumps;
                    }
            }
            if(dp[0] == INT_MAX) return 0;
            else return dp[0];
            
    }
};