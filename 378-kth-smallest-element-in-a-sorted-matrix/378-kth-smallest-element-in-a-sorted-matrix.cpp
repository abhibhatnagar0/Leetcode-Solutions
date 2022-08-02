class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n= matrix.size();        
        int s=matrix[0][0];
        int e=matrix[n-1][n-1];
        int mid;
        int count; //stores no of values in matrix smaller than or eq to mid
        while(s<e)
        {
            count=0;
            mid = s+(e-s)/2;
            for(int i=0;i<n;i++){
                //checking elements smaller than or eq to mid in each row
             count += upper_bound(matrix[i].begin() , matrix[i].end(),mid) - matrix[i].begin(); 
            }
                if(count<k) s =mid+1;
                else e=mid;
         }
        return s;
    }
 //    matrix = [[1, 5, 9],
 //              [10,11,13],
 //              [12,13,15]],
 //    1,5,9,10,11,12,13,13,15
 // K= 1,2,3,4 ,5 ,6 ,7 ,8 ,9 ....Kth smallest
    
};