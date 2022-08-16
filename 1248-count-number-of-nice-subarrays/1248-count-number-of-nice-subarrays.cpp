class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return numofSubarraysWithAtmost(nums,k)- numofSubarraysWithAtmost(nums,k-1);
    }
    
    int numofSubarraysWithAtmost(vector<int>& nums, int k){
		int i = 0, j = 0, odds = 0, res = 0;

		while(j < nums.size()){
			if(nums[j] & 1)	odds++;
           
				while(odds > k){
					if(nums[i] & 1) odds--;
					i++;
				}
        	res += j-i+1;
            j++;
		}
		return res;
	}
};