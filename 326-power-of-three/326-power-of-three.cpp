class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n <= 1) return n == 1;
	// return n % 3 == 0 && isPowerOfThree(n / 3);
        while(n%3 == 0){
            n/=3;
        }
        return n==1;
        
    }
};