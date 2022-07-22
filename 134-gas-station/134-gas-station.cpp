class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n= gas.size();
        //starting gas=0
        //so start from any idx i where gas[i]>=cost[i]
        
        //2 variables
        //fuel1 stores req fuel from 0 to start-1
        //fuel2 stores req fuel from start to n-1
        
        //traversing from start, if at any idx j..fuel2 becomes neg
        //add fuel2 in fuel1
        //make fuel2=0, start=j+1
        
        //start se j-1 jane tk ka fuel hai
        //in btw them, any idx as start will give worse results
        
        int fuel1=0,fuel2=0,start=0;
        for(int i=0;i<n;i++){
            fuel2+=gas[i]-cost[i];
            if(fuel2<0){
                fuel1+=fuel2;
                fuel2=0;
                start=i+1;
            }
        }
        return fuel1 + fuel2 >=0 ? start: -1;
        
    }
};