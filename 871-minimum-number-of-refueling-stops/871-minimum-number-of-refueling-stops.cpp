class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int count=0, i=0, curr_fuel=startFuel;
        priority_queue<int> pq;
        
        while(curr_fuel < target){
            while(i<stations.size() && curr_fuel>=stations[i][0])
                pq.push(stations[i++][1]);
            
            if(pq.empty())
                return -1;
            
            curr_fuel += pq.top();
            pq.pop();
            count++;
        }
        return count;
    }
};