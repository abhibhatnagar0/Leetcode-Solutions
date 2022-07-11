class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int n= nums.size();
        //start val added with prefix sum upto any element shld always be greater than or equal to 1
        //let start val = x
        // x+ (prefix sum upto any ele) >= 1
        // min prefix sum upto a ele ko bhi >=1 bna dia ..toh baki ko toh bna hi denge
        int prefixSum=0;
        int minSum=0;
        for(auto x: nums){
            prefixSum+=x;
            minSum= min(minSum,prefixSum);
        }
        return minSum<0? abs(minSum)+1 : 1;  
    }
};