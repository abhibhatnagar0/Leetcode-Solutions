class NumMatrix {
public:
        vector<vector<int>> sum;
    NumMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
         
           sum=matrix;
            for(int i=0;i<m;i++){
                    for(int j=1;j<n;j++){
                            sum[i][j]+=sum[i][j-1]; //row wise prefix sum
                    }
            }
            for(int i=1;i<m;i++){
                    for(int j=0;j<n;j++){
                            sum[i][j]+=sum[i-1][j]; //column wise prefix sum
                    }
            }
     // sum[i][j] is sum of all elements inside the rectangle [0,0,i,j] after row wise and column wise prefix sum       
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
            if(row1==0 && col1==0) return sum[row2][col2];
            if(col1==0){
                   
                   return sum[row2][col2]-sum[row1-1][col2];
            }
            if(row1==0){
                    
                    return sum[row2][col2]-sum[row2][col1-1];
            }
        return sum[row2][col2]-sum[row2][col1-1]-sum[row1-1][col2] + sum[row1-1][col1-1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */