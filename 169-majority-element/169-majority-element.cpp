class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
         int candidate=nums[0];
            int vote=1; // votes resembles no of times candidate appears more than others
            
            //candidate is in majority,others will decrease his votes until votes are 0.
            //the one appearing after 0 votes, will be the new candidate
            
            for(int i=1; i<n; i++){
                    if(vote==0) {
                            candidate=nums[i];
                            vote++;
                    }
                    else if(nums[i]==candidate) vote++;
                    else vote--;
            }
            return candidate;
    }
};