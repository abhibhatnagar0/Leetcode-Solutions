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
                           continue;
                            }
                    }   
            
           for(int i=0; i<n; i++){
                    if(nums[i]!=i+1){ 
                            missing=i+1;
                            occursTwice=nums[i];
                            break;
                            //at idx i, i+1 hona chahiye tha, but nums[i] hai
                    }
            }
            return {occursTwice,missing};      
    }
};