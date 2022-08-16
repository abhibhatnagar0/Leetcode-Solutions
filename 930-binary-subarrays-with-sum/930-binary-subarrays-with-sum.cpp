class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return numSubarraysWithSumAtmost(nums, goal) - numSubarraysWithSumAtmost(nums, goal - 1);
    }
    // our function is giving number of subarrays with sum less or equal to goal.
    int numSubarraysWithSumAtmost(vector<int>& nums, int goal) {
		if(goal < 0) return 0;

		int n = nums.size();
		int i = 0, j = 0;
		int sum = 0;
		int ans = 0;

		while(j < n) {
			sum += nums[j];
			while(sum > goal) {
				sum -= nums[i];
				i++;
			}    
			ans += j-i+1;           
			j++;  
		}
		return ans;    
	}
    
};