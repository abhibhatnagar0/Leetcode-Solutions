class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int m=matrix.size();
          transpose_sq_matrix(matrix);
           for(int j=0;j<m/2;j++){
                   for(int i=0;i<m;i++){
                        swap(matrix[i][j],matrix[i][m-1-j]);  
                   }
           }     
    }
        void transpose_sq_matrix (vector<vector<int>>& matrix) {
                 int m=matrix.size();
                for(int i=0;i<m;i++){
                        for(int j=0;j<i;j++){
                                swap(matrix[i][j],matrix[j][i]);
                        }
                }
        }    
};