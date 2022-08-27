class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
     //speed of eating bananas can vary from 1 to max_element in piles
         int s = 1;
         int e = INT_MIN;
        for(int i=0; i<piles.size(); i++) e = max(e,piles[i]);
        //when going with e speed, koko can eat all bananas
        //in piles.size() hours
        
        //when speed of eating inc, hours taken dec.
        //if at currSpeed, hrs taken is more... inc currSpeed
        //if hrs taken is less or eq to h...store it in ans nd try to reduce speed
        
        
        int minPosSpeed = INT_MAX;
        while(s<=e){
            int mid = s+ (e-s)/2;
            if(check(piles,h,mid)){
                minPosSpeed = min(minPosSpeed,mid);
                e = mid-1;
            }
            else s = mid+1;
        }
        return minPosSpeed;
    }
    //check if with currSpeed, koko can eat all bananas in h hrs
    //currSpeed is number of bananas koko is eating per hour
    bool check(vector<int>&piles, int h, int currSpeed){
        long long hrs = 0; //hrs taken with currSpeed
        for(int i=0; i<piles.size(); i++){
            if(piles[i] >= currSpeed){
                hrs += (int) ceil(piles[i]*1.0/currSpeed);
            }
            else  hrs++; //when piles[i] < currSpeed
        }
        if(hrs > h) return false;
        return true;
    }
};