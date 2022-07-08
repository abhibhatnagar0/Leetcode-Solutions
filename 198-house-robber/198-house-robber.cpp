class Solution {
public:
    int rob(vector<int>& nums) {
        int n= nums.size();
        
        //dp[i] means max value gained if i houses are there to rob
        int prevbytwo =0; //total 0 house dp[0]
        int prevbyone =nums[0]; //total 1 house dp[1]
        for(int i=1;i<n;i++){
            int curr = max(prevbytwo +nums[i], prevbyone);//dp[2]
            
            prevbytwo= prevbyone;
            prevbyone= curr;
        }
        return prevbyone;//=curr
    }
};