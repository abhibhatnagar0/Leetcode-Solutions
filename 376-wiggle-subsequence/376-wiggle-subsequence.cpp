class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n= nums.size();
        if(n==1) return 1;
        bool lastinc =false;
        bool lastdec =false;
        int len=1;
        
        for(int i=0;i<n-1;i++){
            if(len==1){
                if(nums[i+1]>nums[i]){
                    lastinc=true;
                    len++;
                }
                else if(nums[i+1]<nums[i]){
                    lastdec=true;
                    len++;
                }
                continue;
            }
            if(lastinc){
                if(nums[i+1]<nums[i]){
                    len++;
                    lastinc=false;
                    lastdec=true;
                    continue;
                }
            }
            else if(lastdec){
                if(nums[i+1]>nums[i]){
                    len++;
                    lastinc=true;
                    lastdec=false;
                    continue;
                }
            }
        }
        return len;
    }
};