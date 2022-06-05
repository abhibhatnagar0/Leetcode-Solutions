class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n=nums.size();
            if(n==1) return {};
            vector<int> ans;
           for(int i=0;i<n;i++){
                   int x= nums[i]-1;
                   if(nums[x]!=nums[i]){
                           swap(nums[i--],nums[x]); //put no at its correct position
                   }
                   else{
                          continue;
                   }
                   
           }
            for(int i=0;i<n;i++){
                    if(nums[i]!=i+1){
                            ans.push_back(nums[i]);
                    }
            }
            
            return ans;
    }
};