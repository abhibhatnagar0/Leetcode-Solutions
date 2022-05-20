class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size();
            int n=board[0].size();
           vector<pair<int,int>> dirs={{1,0},{-1,0},{0,1},{0,-1}};
            //finding word[0] in matrix so as to start dfs from it
            for(int i=0;i<m;i++){
                    for(int j=0;j<n;j++){
                            if(board[i][j]==word[0]){
                                    if(dfs(board,word,1,i,j,dirs)) //idx=1 se aage ka findout krna
                                            return true;
                            }
                    }
            }
            return false;
    }
        bool dfs(vector<vector<char>>& board,string word,int idx,int i,int j,vector<pair<int,int>> dirs){
        if(idx==word.size()) return true;
                char c=board[i][j];
                board[i][j]='#';
                int newi,newj;
                for(auto p: dirs){
                        newi= i+p.first;
                        newj= j+p.second;
                        
                 if(newi>=0 && newi<board.size() && newj>=0 && newj<board[0].size() && board[newi][newj]==word[idx] && board[newi][newj]!='#'){
                         if(dfs(board,word,idx+1,newi,newj,dirs))
                                            return true;   
                }
                }
                board[i][j]=c;
                return false;
        }
        
};