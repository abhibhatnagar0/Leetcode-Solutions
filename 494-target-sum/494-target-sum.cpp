class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        //make 2 subsets s1(all +ve signs), s2(all -ve signs)
            target = abs(target);//if target is neg, reverse sign of subsets
        //count will be same
        
        int no_of_zeros=0; //zeros have to be handled separately
        long long sum=0;
        for(int i=0; i<nums.size(); i++){
            sum+=nums[i];
            if(nums[i]==0) no_of_zeros++;
        }
        // s1 + s2 = sum
        //s1-s2= target
        //2(s1)= sum+target ie sum+target has to be even
        
        long long sum_s1= (sum+target)/2;
        if(target > sum || (sum + target) % 2 == 1)   return 0;
        return count_subsets(nums,sum_s1, no_of_zeros);
        
    }
     //count no of subsets of nums with given sum   
    int count_subsets(vector<int>& nums, long long sum, int x){
        int n= nums.size();
        vector<vector<int>> dp(2,vector<int>(sum +1,0));
    //dp[i][j] gives no of subsets with i elements of nums giving sum j
        //at dp[i][j] we are taking decision for nums[i-1]
        //if it wants to contribute its sum or not
        for(int i=0; i<=n;i++)
            dp[i%2][0]=1;
        for(int j=1; j<=sum; j++)
            dp[0][j]=0;  
            
        for(int i=1;i<=n;i++){
            for(int j=1; j<=sum; j++){
                if(nums[i-1]>j || nums[i-1]==0) //0s will be considered later
                        dp[i%2][j]= dp[(i-1)%2][j]; //not including nums[i-1]
                else
                        dp[i%2][j]= dp[(i-1)%2][j] + dp[(i-1)%2][j-nums[i-1]] ;
           //sum of count of subsets by inc and exc nums[i-1]
            }
        }
      return dp[n%2][sum]*(pow(2,x));
        //each 0 has 2 options to go in subset or not
    }
};