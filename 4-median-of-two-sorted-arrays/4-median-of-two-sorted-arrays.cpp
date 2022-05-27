class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
          
        vector<int> v= merged(nums1,nums2);
            double med;
            int size=v.size();
            
            if(size%2==1){
                    med= v[size/2]*1.00;
            }
            else {
                    int p= v[size/2]+v[(size/2)-1] ;
                    med= p/2.00;
            }
            return med;
            
    }
        vector<int> merged(vector<int>& nums1, vector<int>& nums2){
                int p1=0,p2=0;
                int m=nums1.size();
                int n=nums2.size();
                if(m==0) return nums2;
                if(n==0) return nums1;
                vector<int> ans;
                while(p1<m && p2<n){
                        if(nums1[p1]<nums2[p2]) ans.push_back(nums1[p1++]);
                        else  ans.push_back(nums2[p2++]);
                }
                if(p1==m){
                        while(p2<n) ans.push_back(nums2[p2++]);
                }
                 if(p2==n){
                        while(p1<m) ans.push_back(nums1[p1++]);
                }
                return ans;
        }
};