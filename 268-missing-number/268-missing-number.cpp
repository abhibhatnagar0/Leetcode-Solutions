class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n= nums.size();
            for(int i=0;i<n;i++){
                    int x=abs(nums[i]);
                    if(x==n) continue;
                    else if(x==n+1) nums[0]*=(-1);
                    else {
                            nums[x]*=(-1);
                            if(nums[x]==0) nums[x]=-n-1; }
            }
            for(int i=0;i<n;i++){
                    if(nums[i]>0) return i;
                    else if(nums[i]==0) return i;
                    else continue;
            }
            return n;
    }
};