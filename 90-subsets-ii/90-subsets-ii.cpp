class Solution {
public:
        vector<vector<int>> ans;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> subset;
            sort(nums.begin(),nums.end());
            helper(nums,0, subset);
            return ans;
    }
        void helper(vector<int>& nums, int idx, vector<int>& subset){
                if(idx==nums.size()){ ans.push_back(subset);
                                      return; }
                
                subset.push_back(nums[idx]);
                helper(nums,idx+1,subset);// including ith index
                subset.pop_back();
                
                while( idx+1<nums.size() && nums[idx]==nums[idx+1]){
                        idx++;
                }
                // 1,2,2,2,3
                //when at idx=1,and we dont take it then uske aage wale 2s ko bhi nhi lena
                helper(nums,idx+1,subset); // not including ith index   
        }
    
        
};