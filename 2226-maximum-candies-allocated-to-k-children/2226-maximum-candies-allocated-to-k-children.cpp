class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
       long long n = 0;
        for(int i = 0; i < candies.size(); ++i)  n += candies[i];
        //k children me distribute krni hai n candies
        if(k>n) return 0; //cannot distribute 1 candy to each
        
        //candies to each lies in range 1 to n/k
        long long s=1, e=n/k, mid;
        long long maxCandies=0;
        while(s<=e){
            mid= s+ (e-s)/2;
            if(check(candies,k,mid)){
                maxCandies=mid;
                s=mid+1;
            }
            else e=mid-1;
        }
        return maxCandies;
    }
    bool check(vector<int>& candies, long long k, long long val){
        long long posChildren=0;
        for(int i=0;i<candies.size();i++){
             posChildren+= candies[i]/val;
        }
        if(posChildren>=k) return true;
        return false;
    }
};