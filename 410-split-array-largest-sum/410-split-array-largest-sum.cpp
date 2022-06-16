class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        
//m subarrays means m-1 cuts in nums array
// when m=1 , no cut, sum of all ele is max sum of a subarray
//as m increases, max sum of all subarrays decreases
//when m= nums.size() max sum of a subarray is max ele in nums
//so max sum of a subarray lies in range [max ele, sum of all ele]
            
        int s= *max_element(nums.begin(),nums.end());  
        int e= accumulate(nums.begin(),nums.end(),0);
            int ans=s;
            while(s<=e){
                    int mid = s+ (e-s)/2 ;
                   
                    //if subarrays are made so as to keep max sum of any
                    //subarray upto mid
                    int p = func(nums,mid);
                    
                    //p is no of current subarrays
                    if(p<m){
                            //p ko increase krna hai ie
                            //max sum of subarry ko decrease krna hai
                          e= mid-1;         
                    }
                    else if(p==m){
                            ans= mid; // mid can be an ans
                            e= mid-1; //trying to minimize max sum
                                      //if possible hua toh ans update
                                      // ho jayega aage
                            
                    }
                    else{ // no of partitions are larger
                          //max sum of any subarray is smaller
                            s=mid+1;       
                    }
            }
            return ans;    
    }
        
        int func(vector<int>& nums, int mid){
         // returns no of subarrays with max sum of any subarray 
        //less than or equal to mid
               
                int sum =0;
               int count = 1;
        
        for(int i=0;i<nums.size();i++)
        {
            if(sum+nums[i]>mid)
            {
                sum = nums[i];
                count++;
            }
            else
                sum+=nums[i];
        }
      
      return count;
        }
};