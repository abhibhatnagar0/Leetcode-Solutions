class Solution {
public:
    int mirrorReflection(int p, int q) {
         int lcm = (p*q)/__gcd(p, q); // calculating lcm using gcd
        //m*p=n*q=lcm
        int m = lcm/p;
        int n = lcm/q;
        // n gives number of reflections
        // even no of reflections always gives 2
        // odd no of reflections with m=1 gives 1
        // odd no of reflections with m=2 gives 0

        if(m%2==0 && n%2==1) return 0;
        if(m%2==1 && n%2==1) return 1;
        if(m%2==1 && n%2==0) return 2;
        return -1;
    }
    //  int gcd(int a, int b) {
    //     while(b) {
    //         a = a % b;
    //         swap(a, b);
    //     }
    //     return a;
    // }
    
      // int gcd(int a,int b){
      // if(b==0) return a;
      // return gcd(b,a%b);
      // }
};