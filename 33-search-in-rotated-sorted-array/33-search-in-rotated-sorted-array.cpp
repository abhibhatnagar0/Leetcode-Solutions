class Solution {
public:
    int search(vector<int>& nums, int target) {
          int n = nums.size();
          int p=getPivotidx(nums,n);
            cout<<p;
            if(target==nums[p]) return p;
            else if(target>nums[p] && target<=nums[n-1]){
                   return binarySearch(nums,p,n-1,target);
            } 
            else{
                  return binarySearch(nums,0,p-1,target);
            }   
    }
        
     int getPivotidx(vector<int>& nums, int n){
        int s = 0;
        int e = n-1;
        while(s < e){
            int m = s + (e-s)/2;    
            if(nums[m] < nums[e]) e=m;
            else  s=m+1;
        }
        return s;
    }
        
      int binarySearch(vector<int>& nums, int s, int e, int target){
        while(s <= e){
          int m = s + (e-s)/2;
            if(nums[m]== target) return m;
            else if(nums[m]< target) s = m+1;
            else e = m-1;
        }
        return -1;
    }
};