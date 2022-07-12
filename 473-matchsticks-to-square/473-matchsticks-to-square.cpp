class Solution {
public:
    bool makesquare(vector<int>& matchsticks) {
        int n= matchsticks.size();
        if(n<4) return false;
        int sum=0;
        for(auto x: matchsticks) sum+=x;
        if(sum%4 !=0) return false;
        int sidelen= sum/4;
        for(auto x:matchsticks){
            if(x>sidelen) return false;
        }
         vector<int> sides(4,0);
        return dfs(matchsticks, sidelen, sides, 0);
    }
   bool dfs(vector<int> matchsticks, int sidelen, vector<int> &sides, int idx){
        
        // base case
        if(idx == matchsticks.size()){
            if(sides[0] == sides[1] && sides[1] == sides[2] && sides[2] == sides[3]){
                return true;
            }
            return false;
        }
        for(int i = 0; i < 4; i++){
            if (sides[i] + matchsticks[idx] > sidelen){  //optimization - 1
                continue;
            }
          int j = i;
            while (--j >= 0) 
                if (sides[i] == sides[j]) break;
            if (j != -1) continue; ///when side[i] pjle bhi mila h...so dont compute same thing again
            
            sides[i] += matchsticks[idx];
            
            if( dfs(matchsticks, sidelen, sides, idx+1) ){
                return true;
            }
            sides[i] -= matchsticks[idx];
        }
        
        return false;
   }
};