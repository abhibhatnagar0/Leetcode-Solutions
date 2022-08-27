class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int i=0,j=0;
        //i se phle saare even
        //i se j-1 odd
        while(j<nums.size()){
            if((nums[j]&1)==0) swap(nums[i++],nums[j++]);
            else {
                j++;
            }
        }
        return nums;
        
    }
};