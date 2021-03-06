class Solution {
public:
        vector<vector<int>> ans;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>subset;
           int currSum=0;
            helper(candidates,target,subset,0,currSum);
            return ans;
            //to make each subset sorted, phle candidate ko sort kro before passing
    }
        void helper(vector<int>& candidates, int target,vector<int>& subset, int i, int &currSum){
           if(currSum==target) {
                        ans.push_back(subset);
                        return;
                }
                if(currSum>target) return;
                if(i==candidates.size()) return; //backtrack;
                 
                // taking ith idx element in subset
                if(candidates[i]+currSum<=target){
                currSum+=candidates[i];
                subset.push_back(candidates[i]);
                helper(candidates,target,subset,i,currSum);//may think of taking i again
                currSum-=candidates[i];
                subset.pop_back();
                }
                
                //not taking i,moving to next idx
                helper(candidates,target,subset,i+1,currSum);
        }
};