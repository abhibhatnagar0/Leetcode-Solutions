class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n=nums.size();
            sort(nums.begin(), nums.end());
            int minDiff=INT_MAX;
            int ans;
            int p1,p2;
            for(int i=0;i<n-2;i++){
                    p1=i+1;
                    p2=n-1;
                    while(p2>p1){
                    int val= nums[i]+nums[p1]+nums[p2];
                    if(target>val) p1++; //so as to increase val
                    else if(target<val) p2--; // so as to decrease val
                    else return target; //target=val 
                    
                    if(abs(target-val)<minDiff){
                            minDiff=abs(target-val);
                            ans=val;
                    }
                    }
            }
            return ans;
    }
};