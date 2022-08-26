class Solution {
public:
    bool reorderedPowerOf2(int n) {
        vector<int>arr=freq(n);       
            // n can go upto 1e9
            //ie it can have powers of 2 from 0 to 30          
        for(int i=0;i<31;i++){
            if(arr==freq(pow(2,i))) return true;
        }
        return false;
    }
    vector<int> freq(int n){
        vector<int>count(10,0);
        while(n){
            count[n%10]++;
            n/=10;
        }
        return count;
    }
};