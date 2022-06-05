class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
            int n=nums.size();
        int occursTwice=0;
        int missing=0;
            for(int i=0;i<n;i++){
                    int x=nums[i]-1;
                    if(nums[x]!=nums[i]) swap(nums[i--],nums[x]);
                    else{
                            if(i==x) continue;
                            else{
                                    occursTwice=nums[i];
                            }
                    }   
            }
            for(int i=0;i<n;i++){
                    if(nums[i]!=i+1){
                            missing=i+1;
                    }
            }
            return {occursTwice,missing};
    }
};