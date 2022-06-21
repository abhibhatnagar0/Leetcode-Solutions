class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int n= heights.size();
            priority_queue<int> pq; //max heap
            //will give max no of bricks used in 1 step in past
            int i=0; //my curr position
            while(i<n-1){
                    if(heights[i+1]<=heights[i]){
                            //just move ahead
                            i++;
                            continue;
                    }
                    else{
                            int diff= heights[i+1]- heights[i];
                            if(ladders==0 && bricks<diff){
                                    return i;
                            }
                            else if(bricks>0 && diff<=bricks){
                                    bricks-=diff;
                                    pq.push(diff);
                            }
                            else {
                                    if(ladders>0){
                                            if(pq.size()>0 && pq.top()>diff){
                                            bricks+=pq.top()-diff;
                                             pq.pop();
                                             pq.push(diff);
                                            }
                                            ladders--;
                                    }
                            }
                    }
                 i++;
            }
            //i==n-1
            return i;
            
            
    }
};