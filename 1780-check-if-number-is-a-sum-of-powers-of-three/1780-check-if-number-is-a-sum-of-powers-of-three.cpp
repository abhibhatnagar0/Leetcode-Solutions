class Solution {
public:
    bool checkPowersOfThree(int n) {
        //n can be upto 1e7
        //3^15 is greater than n
        for(int i=14;i>=0;i--){
            int powof3= pow(3,i);
            if(n-powof3>=0){
                n-=powof3;
            }
            if(n==0) return true;
        }
        return false;
    }
};