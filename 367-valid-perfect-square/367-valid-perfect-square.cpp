class Solution {
public:
    bool isPerfectSquare(int num) {
       int s=0, e=num;
        bool ans= false;   
            //sqrt of num will lie in 0 to num
            while(s<=e){
                   long long m = s+ (e-s)/2;
                    if(m*m == num){
                        ans= true;
                            break;
                    }
                    else if (m*m > num){
                            e=m-1;
                    }
                    else s= m+1;
            }
            return ans; 
    }
};