class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        //when array is immutable, we cannot negate elements to find duplicate
            //using ll cycle method
            //[5,3,4,2,5,1]
            // 0,1,2,3,4,5
            //5->1->3->2->4->5->1..........
            int n=nums.size();
            int slow=nums[0];
            int fast=nums[0];
            do{
                 slow=nums[slow]; //taking single jump
                 fast=nums[nums[fast]];// taking double jumps
             }while(slow!=fast);
               fast=nums[0];// initialising fast as first element again*
                 while(slow!=fast)
                    {
                     slow=nums[slow]; //incementing till we again encounter the element
                     fast=nums[fast];
                        }
             return fast;
           }
         };