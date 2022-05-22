class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
         int n = capacity.size();
		vector<int> vacant(n);   // creating vector for how many vacant space are left for additional rocks
        
        for(int i = 0 ; i < n; i++) vacant[i] = capacity[i] - rocks[i];
       
        sort(vacant.begin() , vacant.end());  // sort array
        
		int cnt = 0;    // count no. of bags that are full
        for(int i = 0; i < n; i++)
        {
            if(vacant[i] == 0) cnt++;
            else
            {
                if(additionalRocks >= vacant[i])
                {
                    additionalRocks -= vacant[i];
                    cnt++;
                }
                else break;
            }
        }
        return cnt;
    }
};