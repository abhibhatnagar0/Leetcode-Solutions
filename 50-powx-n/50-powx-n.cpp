class Solution {
public:
    double myPow(double x, long int n) {    
     if(n==0) return 1;
     if(n==1) return x;       
     if (n<0){
         n = -n;
         x= 1/x;
     }
        double ans= myPow(x,n/2);
            ans*=ans;
     if(n%2==1) ans*=x;
            return ans;
    }
    
};