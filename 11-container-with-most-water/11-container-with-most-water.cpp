class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
            int l=0;
            int r=n-1;
            int maxwater=0;
            while(r>l){                                         
                  maxwater=max(maxwater,min(height[l],height[r])*(r-l));
  //on l++ or r--, base l-r will reduce for sure
  // height of water is to be increased which depends on min    of l and r height                  
                    if(height[l]<height[r])
                            l++; //move the minimum of both
                    //larger height cannot make area greater anyway
                    else
                            r--;                                            
                      }
            return maxwater;
    }
};