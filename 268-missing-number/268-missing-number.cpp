class Solution {
public:
    int missingNumber(vector<int>& nums) {
            int n=nums.size();
       int xorall=0;
            //n=5..... 0,1,2,3,4,5 aa skte hai, but inn 6 me se koi 5 aayenge
            //xor of all elements with 0 to 5, all duplicates cancel
            for(int i=0;i<n;i++){
                    xorall^=(nums[i]^i);
            }
            xorall^=n;
            return xorall;
    }
};