class Solution {
public:
        vector<vector<int>> ans;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>subset;
            helper(candidates,target,subset,0,0);
            return ans;
            //to make each subset sorted, phle candidate ko sort kro before passing
    }
        void helper(vector<int>& candidates, int target,vector<int>& subset, int i, int currSum){
                if(i==candidates.size()) return; //backtrack;
                if(currSum==target) {
                        ans.push_back(subset);
                        return;
                }
                if(currSum>target) return;
                
                // taking ith idx element in subset
                currSum+=candidates[i];
                subset.push_back(candidates[i]);
                helper(candidates,target,subset,i,currSum);//may think of taking i again
                currSum-=candidates[i];
                subset.pop_back();
                
                //not taking i,moving to next idx
                helper(candidates,target,subset,i+1,currSum);
        }
};