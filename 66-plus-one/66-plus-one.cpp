class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        for(int i = n - 1; i >= 0; i--) {
            if(digits[i] != 9) {  //phli baar jb non-9 mile toh increase it and just return 
                digits[i]++;
                return digits;
            } else {
                digits[i] = 0;
            }
        }
            // idhar tk return nhi hua means vector has all 9s
            //so we will insert 1 at start
        digits.insert(digits.begin(), 1);
        return digits;
    }
    
};