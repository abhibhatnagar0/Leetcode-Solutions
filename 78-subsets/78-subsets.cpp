class Solution {
public:
        vector<vector<int>> ans;
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
            int total_subsets= 1<<n; //pow(2,n)
            for(int i=0;i<total_subsets;i++){
                vector<int> subset;      //if n=3, i=6 means 110 ie bit 1,2 are set
                                         // so index 1,2 of nums are included in subset
                for(int j=0;j<n;j++){
                        if((1<<j)&i) subset.push_back(nums[j]);
                        // if jth index of nums ka eq bit set hai toh push in subset;
                }
                    ans.push_back(subset);
            }
        return ans;    
    }
};