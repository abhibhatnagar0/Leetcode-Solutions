class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
            int n= nums.size();
            if (n==0) return ans;
            sort(nums.begin(), nums.end()); //for working of 3 pointer approach
            int p1,p2;
            for(int i=0; i<n-2; i++){
                   // nums[i] will remain fixed, p1 p2 will move to give total sum=0
                    if(i==0 || nums[i]!=nums[i-1]){ //TO AVOID SAME 3 NOS FROM i SIDE
                    p1=i+1;
                    p2=n-1;
                    while(p1<p2){  
                    if(nums[p1]+nums[p2]+nums[i]>0){
                            p2--;
                    }
                    else if(nums[p1]+nums[p2]+nums[i]<0){
                            p1++;
                    }
                    else {
                            ans.push_back({nums[i],nums[p1++],nums[p2--]});
                            // req p1,p2 mil gye, but aage p1,p2 ki nyi values milni chahiye
                            // any of p1,p2 if same, gives same 3 numbers
                             while (p1 < p2 && nums[p1] == ans.back()[1]) p1++; //TO AVOID SAME 3 NOS FROM P1 SIDE
                              while (p1 < p2 && nums[p2] == ans.back()[2]) p2--;// FROM P2 SIDE
                    }
                   
                   }
                    }
          
            
    }
            return ans;
    }
};