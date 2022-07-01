class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
         sort(boxTypes.begin(),boxTypes.end(),cmp);// sort on the basis of units
        int ans=0;
        
        for(auto box: boxTypes){
            if(truckSize>box[0]){
                ans+=box[0]*box[1];
                truckSize-=box[0]; //truckSize is the remaining no of boxes to be put on truck
            }
            else{//not all boxes of this type are needed
                ans+=truckSize*box[1];
                truckSize=0;
                break;
            }
        }
        return ans;
    }
    bool static cmp(vector<int> a, vector<int> b){
        if(a[1]==b[1]) a[0]>b[0];
        return a[1]>b[1];
    }
    
};