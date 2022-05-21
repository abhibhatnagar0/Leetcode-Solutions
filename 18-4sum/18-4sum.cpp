class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n=nums.size();
            sort(nums.begin(),nums.end());
            int p1,p2; //for c and d 
             vector<vector<int>> ans;
          for(int i=0;i<n-3;i++){
                  if(i!=0 && nums[i]==nums[i-1]) continue;
                  for(int j=i+1;j<n-2;j++){
                          if(j!= i+1 && nums[j]==nums[j-1]) continue;
                          p1=j+1;
                          p2=n-1;
                          while(p2>p1){
                                  int target2 = target - nums[i]-nums[j];
                                  int val = nums[p1] + nums[p2];
                                  if(target2>val) p1++;
                                  else if(target2<val) p2--;
                                  else{
                                          vector<int> temp={nums[i],nums[j],nums[p1],nums[p2]};
                                          ans.push_back(temp);
                                          p1++;
                                          p2--;
                                          while(p2>p1 && nums[p1]==temp[2]) p1++;
                                          while(p2>p1 && nums[p2]==temp[3]) p2--;
                                          
                                  }
                          }
                          
                  }
          }
            return ans;
    }
};