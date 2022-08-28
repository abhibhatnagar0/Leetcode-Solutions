class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        int n=matrix[0].size();
        for(int i=0;i<m;i++)
            for(int j=1;j<n;j++)
                matrix[i][j]+=matrix[i][j-1]; //storing row wise prefix sum
        
        int ans=0;
     unordered_map<int,int>mp;
        for(int c1=0;c1<n;c1++)
            for(int c2=c1;c2<n;c2++){
                //fixing columns from c1 to c2
                //when c1=c2 we take all 1*1, 2*1, 3*1...m*1 submatrices
                //when c2-c1=1 we take all 1*2, 2*2, 3*2, 4*2 submatrices
                
                //all rows sum btw c1 and c2 act as an array element
                mp.clear();
                mp[0]=1;
                int sum=0; //prefix sum
                for(int k=0;k<m;k++) //traversing all array elements
                {
                    sum+=matrix[k][c2]-(c1>0 ? matrix[k][c1-1] : 0);
                    ans+=mp[sum-target];
                    mp[sum]++;
                }
            }
        return ans;
        //Time Complexity:- O(m*n^2)
    }
};