class Solution {
public:
        vector<vector<int>> ans;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> subset;
            sort(nums.begin(),nums.end());
            helper(nums,0, subset,false);
            return ans;
    }
        void helper(vector<int>& nums, int idx, vector<int>& subset, bool incLastidx){
                if(idx==nums.size()){ ans.push_back(subset);
                                      return; }
                
                helper(nums,idx+1,subset,false); // not including ith index
                if( idx!=0 && nums[idx]==nums[idx-1] && incLastidx==false){
                        //phle duplicate ko include nhi kia toh ab  idx ko bhi nhi krna
                        return;
                }
                subset.push_back(nums[idx]);
                helper(nums,idx+1,subset,true);// including ith index
                subset.pop_back();
        }
    
        
};