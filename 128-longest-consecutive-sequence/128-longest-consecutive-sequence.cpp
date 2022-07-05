class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        int max_length=0;
        for(int i=0; i<nums.size(); i++){
            s.insert(nums[i]);   
        }
        for(int i=0; i<nums.size(); i++){
            if (s.find(nums[i]-1)!= s.end()){
                continue;
            }
            else{
               int count=0;
               while(s.find(nums[i])!= s.end()) {
                   count++;
                   nums[i]++;
               }
                //cant find nums[i]
             //count stores len of curr consecutive sequence
              max_length=max(max_length,count)  ;
            }   
        }
      return max_length;  
    }
};