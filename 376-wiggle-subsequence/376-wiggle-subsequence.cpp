class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
         int n = nums.size();
        if(n == 0) return 0;
        
        vector<int> up(n, 1); 
        //up[i] stores len of wiggle subseq upto ith idx with last inc val
        vector<int> down(n, 1);
         //down[i] stores len of wiggle subseq upto ith idx with last dec val
        
        // At i=0, there is only one number and we can use it as a subsequence, i.e up[0]=down[0]=1
        up[0] = 1;
        down[0] = 1;
        for(int i=1; i<n; ++i){
            
            if (nums[i] > nums[i-1]) {
                up[i] = down[i-1] + 1;
                down[i] = down[i-1];
            }
            else if (nums[i] < nums[i-1]) {
                down[i] = up[i-1] + 1;
                up[i] = up[i-1];
            }
            else {
                /** if nums[i] == nums[i-1], we cannot do anything more than what we did with
                     nums[i-1] so we just keep the old values of up and down
                */
                up[i] = up[i-1];
                down[i] = down[i-1];
            }
        }
        return max(up[n-1], down[n-1]);
    }
};