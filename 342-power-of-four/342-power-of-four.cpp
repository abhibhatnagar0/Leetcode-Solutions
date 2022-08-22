class Solution {
public:
    bool isPowerOfFour(int n) {            
        // if(n<1) return false;
        // else if(n==1) return true;
        // else if(n%4==0) return isPowerOfFour(n/4);
        // else return false;
        
        if(n<1) return false;
       if((n & (n - 1)) == 0 && (n - 1) % 3 == 0) return true;
        
        return false;
    }
    
};