class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n= matrix.size();        
        int s=matrix[0][0];
        int e=matrix[n-1][n-1];
        int mid;
        int count; //stores no of values in matrix smaller than mid
        while(s<e)
        {
            count=0;
            mid = s+(e-s)/2;
            for(int i=0;i<n;i++){
                //checking elements smaller than mid in each row
             count += upper_bound(matrix[i].begin() , matrix[i].end(),mid) - matrix[i].begin(); 
            }
                if(count<k) s =mid+1;
                else e=mid;
         }
        return s;
    }
};