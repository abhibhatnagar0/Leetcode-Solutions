class Solution {
public:
        vector<vector<int>> ans;
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> subset;
            helper(nums,0, subset);
            return ans;
    }
        void helper(vector<int>& nums, int idx, vector<int>& subset){
                if(idx==nums.size()){ ans.push_back(subset);
                                      return; }
                
                helper(nums,idx+1,subset); // not including ith index
                subset.push_back(nums[idx]);
                helper(nums,idx+1,subset);// including ith index
                subset.pop_back();
        }
};