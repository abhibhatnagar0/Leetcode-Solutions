class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
            int n= nums1.size(); //smaller
            int m= nums2.size(); //larger
            if(n>m) return findMedianSortedArrays(nums2,nums1);
            
            int l1,l2,r1,r2;
            /*if n+m=10, left and right sides have 5-5 ele in total
              if n+m =9, left will have 4, right will have 5 ele in total
              */
            int s=0, e=n; //as s se e cuts can be at n+1 spaces
            while(s<=e){
                 int cut1= s+ (e-s)/2; // cut1=3 means 3 ele of nums1 in left side
                 int cut2= (n+m)/2 - cut1; 
                    
                 if(cut1!=0) l1=nums1[cut1-1];
                 else l1= INT_MIN;
                    
                 if(cut1!=n) r1=nums1[cut1];
                 else r1= INT_MAX;
                    
                 if(cut2!=0) l2=nums2[cut2-1];
                 else l2= INT_MIN;
                    
                 if(cut2!=m) r2=nums2[cut2];
                 else r2= INT_MAX;
                    
                    if(l1>r2){
                            //left of nums1 ko chota kro...cut1 phle kro
                            e=cut1-1;
                    }
                    else if(r1<l2){
                            //right of nums1 ko bda kro..cut1 aage kro
                            s=cut1+1;
                    }
                    else{
                            //cuts are at correct positions
                            if((n+m)%2 ==0){
                                  return (max(l1,l2) + min(r1,r2))/2.0;  
                            }                     
                            else{
                                    //in even len, right side has extra element
                                    return min(r1,r2);
                            }
                    }
            }
            cout<<l1;
          return -1;  
    }
};