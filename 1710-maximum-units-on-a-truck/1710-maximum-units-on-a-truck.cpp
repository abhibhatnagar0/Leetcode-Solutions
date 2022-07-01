class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        priority_queue<vector<int>> pq; //max heap
        for(auto v: boxTypes){
            pq.push({v[1],v[0]}); //sort on basis of decreasing units/box
        }
        //pq.top()[0] gives max units/box
        //pq.top()[1] gives corresponding no. of boxes
        
        int boxesTaken=0; //so far
        int maxUnits=0;
        
        while(!pq.empty() && boxesTaken<truckSize ){
            //can I take all boxes of pq.top() ?
            if(boxesTaken+ pq.top()[1] <=truckSize){
                boxesTaken+= pq.top()[1];
                maxUnits+= pq.top()[1] * pq.top()[0];
                pq.pop();
            }
            else{
                int reqBoxes= truckSize-boxesTaken;
                boxesTaken+=reqBoxes;
                maxUnits+= reqBoxes * pq.top()[0];
            }
        }
        //if pq.empty() has become true
        //or if boxesTaken==truckSize
        return maxUnits;
        
    }
};