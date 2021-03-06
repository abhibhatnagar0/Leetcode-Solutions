class Solution {
public:
    int totalNQueens(int n) {
            if(n==1) return 1;
            if(n==2 || n==3) return 0;
         vector<string> board(n);
            string s(n, '.');
               for (int i = 0; i < n; i++){
                  board[i] = s;
                 }
        //take one row at a time and check
            int count=0;
            dfs(0,board,n,count);
           return count; 
    }
        void dfs(int row,vector<string>&board, int n, int &count){
                if(row==n){
                        count++;
                        return;
                }
           for(int col=0;col<n;col++){
                   if(isValid(row,col,board,n)){
                           board[row][col]='Q';
                           dfs(row+1,board,n,count);
                           board[row][col]='.';
                   }
           }
        }
        
        bool isValid(int row,int col,vector<string>&board, int n){
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
};