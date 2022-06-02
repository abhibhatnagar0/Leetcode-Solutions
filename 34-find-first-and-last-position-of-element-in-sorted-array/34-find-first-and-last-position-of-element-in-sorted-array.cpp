class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans(2,-1);
            helper(nums,target,ans,0);
            return ans;
    }
        void helper(vector<int>& nums, int target,vector<int> & ans,int i){
                if(i==nums.size()) return;
                if(nums[i]==target){
                           if(ans[0]==-1){
                                  ans[0]=i;//first occurence
                                  ans[1]=i;//last occurence till now
                           }
                        else{
                                ans[1]=i;//last occurence till now
                        }
                }
                helper(nums,target,ans,i+1);
        }
};