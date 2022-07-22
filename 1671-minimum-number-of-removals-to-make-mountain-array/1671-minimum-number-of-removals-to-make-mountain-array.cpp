class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
         int maxlen=0; // maximum length of bitonic subsequence 
        int n = nums.size();
        vector<int> dp_inc = longestIncreasingSubsequence(nums, n);
        
        reverse(nums.begin(), nums.end());
        vector<int> dp_dec = longestIncreasingSubsequence(nums, n);
        reverse(dp_dec.begin(), dp_dec.end());
        
        //dp_inc[i] gives length of LIS ending at ith index with ith idx at peak
                 //     .
                 //   .
                 // .        
        //dp_dec[i] gives length of LDS from ith index to end with ith idx at peak
                     // .
                     //     .
                     //         .
                         
        for(int i =0;i<nums.size();i++){
            if(dp_inc[i]==1 || dp_dec[i]==1) continue;   
            //ignore all those who is 1 because it doesnt not have any to it's left or right side
			
            maxlen=max(maxlen,dp_inc[i]+dp_dec[i]-1);  //subtracting 1 to prevent double peak
        }
        return nums.size()-maxlen; //deletions
    }
    vector<int> longestIncreasingSubsequence(vector<int>nums, int n){
       
        vector<int > v; //may not be in lis sequence always
        vector<int>dp;
        dp.push_back(1);
        v.push_back(nums[0]);
        
        for(int i=1;i<nums.size();i++){
            if(nums[i]>v.back()){
                v.push_back(nums[i]);
                dp.push_back(v.size());
            }
            else{
                int idx=lower_bound(v.begin(),v.end(),nums[i])-v.begin();
                v[idx]=nums[i];
                dp.push_back(idx+1);
                //jis idx ko update kia, vhi tk ki LIS len I can give
            }
        }
        return dp;
    }
};