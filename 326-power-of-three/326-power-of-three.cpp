class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n<1) return false;
        return floor(log10(n)/log10(3))==ceil(log10(n)/log10(3));
        // floor(x) : rounds downs the nearest integer.
        //  ceil(x) : rounds up the nearest integer.
    }
};