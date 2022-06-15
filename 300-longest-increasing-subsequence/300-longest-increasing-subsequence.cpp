class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
       
        vector<int> temp;
        temp.push_back(nums[0]);
        for(int i=1;i<nums.size();i++){
            if(nums[i]>temp.back()){
                temp.push_back(nums[i]);
            }
            else{
                int ind = lower_bound(temp.begin(),temp.end(),nums[i]) - temp.begin();
                temp[ind] = nums[i];
            }
        }
            for(auto x: temp) cout<<x<<" ";
        return temp.size();
            //temp may not always be same as lis, though length will be same
            // 2,3,5,1,9,4 will give 1,3,4,9
            //actual lis is 2,3,5,9
    }
};