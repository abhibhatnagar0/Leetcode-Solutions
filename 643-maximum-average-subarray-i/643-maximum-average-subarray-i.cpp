class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
         int currSum=0;
        int n = nums.size();
        
        for(int i=0;i<k;i++) currSum+=nums[i];
        
        int maxSum=currSum;
        
        for(int i=k;i<n;i++){
            currSum+=nums[i]-nums[i-k];
            maxSum=max(currSum,maxSum);
        }
        
        return (double)maxSum/(double)k;
    }
};