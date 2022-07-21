class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n= colors.size();
        int cost=0;
        int lastcoloridx=0;
        priority_queue<int,vector<int>,greater<int>> pq;
        pq.push(neededTime[0]);
        for(int i=1;i<n;i++){
            if(colors[i]==colors[lastcoloridx]){
                pq.push(neededTime[i]);
                cost+=pq.top();
                pq.pop();
            }
            else{
                lastcoloridx=i;
                while(!pq.empty()) pq.pop();
                pq.push(neededTime[i]);
            }
        }
       return cost; 
    }
};