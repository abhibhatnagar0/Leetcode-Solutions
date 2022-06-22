class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n= nums.size();
            if(n<k) return -1;
            priority_queue<int,vector<int>,greater<int>> pq; //min heap
            //stores largest, 2nd largest...upto kth largest elements (may not be               distinct)
            for(int i=0;i<k;i++){ //push k ele in pq
                 pq.push(nums[i]);   
            }
            for(int i=k;i<n;i++){
                    if(pq.size()!=0 && pq.top()<nums[i]){
                            pq.pop(); //pop smaller elements at top
                            pq.push(nums[i]);
                    }
            }
            return pq.top();// kth largest
            
    }
};