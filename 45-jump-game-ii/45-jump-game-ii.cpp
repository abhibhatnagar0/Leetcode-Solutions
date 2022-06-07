class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
            if(n==1) return 0;
            
            int currReach= 0; 
            int maxReach= 0;
            int minJumps=0;
            
            for(int i=0;i<n-1;i++){
                    maxReach=max(i+nums[i],maxReach);
                    
                    if(i==currReach){
                            minJumps++;
                            currReach=maxReach;
                    }
            }
      return minJumps;
    }
};