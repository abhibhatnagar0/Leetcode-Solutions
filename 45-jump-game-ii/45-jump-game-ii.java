class Solution {
    public int jump(int[] nums) {
            //greedy way
        int curReach = 0; // i=0 kaha tk le kr ja skta
        int maxReach = 0; // i=0 ki reach tk aa rhe elements, kha tk max le kr ja skte
            //i=0 has nums[i]=3, so any one of 1,2,3 will give maxReach
        int jumps = 0;
        
        for(int i = 0;i<nums.length-1;i++){
            if(i+nums[i] > maxReach){
                maxReach = i +nums[i];
            }
            
            if(i==curReach){
                jumps++; // i=0 se 1,2,3 me se koi ek that gives maxReach
                curReach = maxReach;
            }
        }
        return jumps;
    }
}