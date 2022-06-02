class Solution {
public:
        vector<vector<string>> ans;
        //each idx of ans has 1 solution of queens position on board
    vector<vector<string>> solveNQueens(int n) {
        // make a n*n board, each row is a string
            vector<string> board(n);
            string s(n, '.');
               for (int i = 0; i < n; i++){
                  board[i] = s;
                 }
        vector<int>cols(n,0); //checks ki (row,col) ke upar wale cols me koi queen toh nhi hai
        vector<int>leftTop(2*n-1,0); //checks ki (row,col) ke leftTop diagonal me koi queen toh nhi h
            //both row,col saath me -- honge ..ie for(3,4)->(2,3) (1,2) (0,1) so (n-1)-(col-row) ranges from 0 to 2(n-1)
        vector<int>rightTop(2*n-1,0);
            //when row--,col++ honge ..ie for(3,1)->(2,2) (1,3) (0,4) so col+row ranges from 0 to 2(n-1)
            
        //take one row at a time and check
            dfs(0,board,n,cols,leftTop,rightTop);
            
            return ans;
    }
        
        void dfs(int row,vector<string>&board, int n,vector<int>&cols,vector<int>&leftTop,vector<int>&rightTop){
                if(row==n){
                        ans.push_back(board);
                        return;
                }
           for(int col=0;col<n;col++){
                   if(issValid(row,col,board,n,cols,leftTop,rightTop)){
                           board[row][col]='Q';
                           cols[col]=1;
                           leftTop[(n-1)-(col-row)]=1;
                           rightTop[row+col]=1;
                           
                           dfs(row+1,board,n,cols,leftTop,rightTop);
                           
                           board[row][col]='.';
                           cols[col]=0;
                           leftTop[(n-1)-(col-row)]=0;
                           rightTop[row+col]=0;
                           
                   }
           }
        }
        
        bool issValid(int row,int col,vector<string>&board, int n,vector<int>&cols,vector<int>&leftTop,vector<int>&rightTop){
                if(cols[col]==1) return false;
                if(leftTop[(n-1)-(col-row)]==1) return false;
                if(rightTop[row+col]==1) return false;
                return true;
        }
        
       /* bool isValid(int row,int col,vector<string>&board, int n){
          //for a queen to be placed at (row,col)
          //no queen shld be there on that row, col and diagonal
          //same row not possible as one row me daalkr, we are 
          //passing row+1 in func
          //for same col
                int tempCol=col;
                int tempRow=row;
                while(tempRow>=0){
                     if(board[tempRow][tempCol]=='Q') return false; 
                      tempRow--;
                }  
          //for north-west diagonal
                tempCol=col;
                tempRow=row;
                while(tempRow>=0 && tempCol>=0){
                    if(board[tempRow][tempCol]=='Q') return false;
                        tempRow--;
                        tempCol--;
                }
          //for north-east diagonal
               tempCol=col;
               tempRow=row;
                while(tempRow>=0 && tempCol<n){
                    if(board[tempRow][tempCol]=='Q') return false;
                        tempRow--;
                        tempCol++;
                }
             return true;   
        }
        */
        

};