class Solution {
public:
        vector<vector<int>> ans;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
          vector<int>subset;
            sort(candidates.begin(),candidates.end());
            //jisse duplicates saath me aa jaye
            //when a ele will not come, then all its duplicates too wont come, skip kr denge unko
            //when ele comes, simpily i++
            helper(candidates,target,subset,0,0);
            return ans;
            
    }
    
        void helper(vector<int>& candidates, int target,vector<int>& subset, int i, int currSum){
                if(currSum==target) {
                        ans.push_back(subset);
                        return;
                }
                if(currSum>target) return;
                
                if(i==candidates.size()) return; //backtrack;
                
                // taking ith idx element in subset
                currSum+=candidates[i];
                subset.push_back(candidates[i]);
                helper(candidates,target,subset,i+1,currSum);//cant take i again
                subset.pop_back();
                currSum-=candidates[i];
                
                //not taking i,moving to next idx which is different
                while(i+1<candidates.size() && candidates[i]==candidates[i+1]) i++;
                helper(candidates,target,subset,i+1,currSum);
        }
};