class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size(),p=1<<n; //p=total possible subsets = pow(2,n)
        set<vector<int>> st;
        
        for(int i=0;i<p;i++){
            vector<int> subset;
            for(int j=0;j<n;j++){
                if(i&(1<<j)) subset.push_back(nums[j]);
            }
            st.insert(subset); //stores all unique subsets
        }
        
        vector<vector<int>> res(st.begin(),st.end());
        return res;   
    }
};