class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int n= heights.size();
            priority_queue<int> pq; //max heap
            //will give max no of bricks used in any one step in past
            int i=0; //my curr position
            while(i<n-1){
                    if(heights[i+1]<=heights[i]){
                            //just move ahead
                            i++;
                            continue;
                    }
                    else{
                            int diff= heights[i+1]- heights[i];
                            if(ladders==0 && bricks<diff){ //when I have no bricks and ladders left
                                    return i;
                            }
                            else if(bricks>0 && diff<=bricks){ //ladders are of greater imp, so phle bricks use kro
                                    bricks-=diff;
                                    pq.push(diff);//if at any step, too many bricks used,that can be replaced with ladder
                                                  //as ladders are better for large diff
                            }
                            else { 
                                    if(ladders>0){
                                            if(pq.size()>0 && pq.top()>diff){//if diff small and no bricks left
                                            bricks+=pq.top()-diff; //use pq.top wali bricks here and ladder there
                                             pq.pop();
                                             pq.push(diff); //iss step ke liye 
                                            }
                                            ladders--;//ye toh hona h hi, either iss step me ya large bricks wale step me
                                    }
                            }
                    }
                 i++;
            }
            //i==n-1
            return i;
            
            
    }
};