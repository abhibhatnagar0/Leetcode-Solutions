class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int stops=0, i=0, curr_fuel=startFuel;
        //curr_fuel gives current reach
        
        priority_queue<int> pq; //max heap
        //always fill tank with max fuel available so far
        //pq stores all previous stations fuels, where I can go with curr_fuel
        //when I reach a station where I cannot go with curr_fuel, use pq.top() to refill tank
        //if curr_fuel exceeds target, stop there and return stops
        while(curr_fuel < target){
            while(i<stations.size() && curr_fuel>=stations[i][0]) pq.push(stations[i++][1]);
            
            //curr_fuel < stations[i][0] ....cannot reach this station
            if(pq.empty()) return -1; //cannot reach end, as no stations before to refill tank
            curr_fuel += pq.top();
            pq.pop();
            stops++;
        }
        return stops;
    }
};