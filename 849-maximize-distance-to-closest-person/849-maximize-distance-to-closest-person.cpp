class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int n= seats.size();
        int zeroInbtw=0;
        int ans=0;
        //when Alex has neighbour only in right
        for(int i=0;i<n;i++){
            if(seats[i]==1){
                ans=max(ans,i);
                break;
            }
            else continue;
        }
        //when Alex has neighbour only in left
        for(int i=n-1;i>=0;i--){
            if(seats[i]==1){
                ans=max(ans,(n-1-i));
                break;
            }
            else continue;
        }
        //when Alex has both left right neighbours
        for(int i=0;i<n;i++){
            if(seats[i]==1){
                zeroInbtw=0;
            }
            else{
                zeroInbtw++;
                ans=max(ans,(zeroInbtw+1)/2);
            }
        }
        return ans;
    }
};