class Solution {
public:
    int singleNumber(vector<int>& nums) {
            int unique=0;
        for(int i=0;i<32;i++){ //for all bits
                int ones=0;
          for(int j=0;j<nums.size();j++){ // for all elements at a particular bit
                        if((nums[j]>>i)&1 ==1) ones++;
                }
                if(ones%3==1){
                        //set this bit in unique
                        unique|=(1<<i);
                }
        }
            return unique;
    }
        //this takes o(32*n) > 0(logn*n)
        //as log n is faster than 32 steps even for INT_MAX
        
        // other method is just sorting nums and traversing array with 3 jumps each comparing ith and i+1 th index
        //that would take o(nlogn), ie better than this 
        
};