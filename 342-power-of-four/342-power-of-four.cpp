class Solution {
public:
    bool isPowerOfFour(int n) {            
        // if(n<1) return false;
        // else if(n==1) return true;
        // else if(n%4==0) return isPowerOfFour(n/4);
        // else return false;
        
        if(n<1) return false;
        return floor(logn(n,4))==ceil(logn(n,4));
        // floor(x) : rounds downs the nearest integer.
        //  ceil(x) : rounds up the nearest integer.
        
    }
    double logn(int n,int r){
        return log(n)/log(r);
    }
};