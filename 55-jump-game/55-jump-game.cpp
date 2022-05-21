class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
            int reach=0; // till reach I can jump
          int i=0; //abhi ith index pe hu
            while(i<=reach){ // for any i, I can go from i to reach and update new reach
                    reach=max(reach,i+nums[i]);
                    if(reach>= n-1) return true;
                    i++;
            }
            return false;
            
    }
};