class Solution {
public:
        vector<vector<int>> ans;
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> subset;
            
            helper(k,n,subset,1,0);
            return ans;
    }
     
        void helper(int k, int n,vector<int>& subset,int i,int currSum){
                if(subset.size()==k && currSum==n){
                        ans.push_back(subset);
                        return;
                }
                if(subset.size()>k || currSum>n) return;
                if(i==10) return;
                
                //taking i in subset
                if(subset.size()<k && currSum<n){
                subset.push_back(i);
                currSum+=i;
                helper(k,n,subset,i+1,currSum);
                subset.pop_back();
                currSum-=i;
                }
                
                //w/o taking i
                helper(k,n,subset,i+1,currSum);
        }
};