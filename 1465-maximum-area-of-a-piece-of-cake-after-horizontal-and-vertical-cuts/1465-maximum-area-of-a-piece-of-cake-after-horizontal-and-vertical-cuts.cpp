class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        horizontalCuts.push_back(0);
        horizontalCuts.push_back(h);
        sort(horizontalCuts.begin(),horizontalCuts.end());
         verticalCuts.push_back(0);
         verticalCuts.push_back(w);
        sort(verticalCuts.begin(),verticalCuts.end());
        
        int maxhd=0;
        for(int i=0;i<horizontalCuts.size()-1;i++){
            if(horizontalCuts[i+1]-horizontalCuts[i] >maxhd){
                maxhd= horizontalCuts[i+1]-horizontalCuts[i];
            }
        }
        
         int maxvd=0;
        
        for(int i=0;i<verticalCuts.size()-1;i++){
            if(verticalCuts[i+1]-verticalCuts[i] >maxvd){
                maxvd= verticalCuts[i+1]-verticalCuts[i];
            }
        }
        
        return ((long long)(maxhd%1000000007)*(maxvd%1000000007)) % 1000000007;
        
    }
};