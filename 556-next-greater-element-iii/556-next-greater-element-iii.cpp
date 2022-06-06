class Solution {
public:
    int nextGreaterElement(int n) {
        string s =to_string(n);
            int m=s.size();
            int infpt=0; 
            //finding infpt
            for(int i=m-1;i>0;i--){
                    if(s[i-1]<s[i]){ 
                            infpt=i;
                            break; }
            }
            if(infpt==0) return -1;
            int to_swap=infpt-1;
            // finding just greater no to to_swap
            
                    int temp = m-1;
                        while(s[to_swap] >= s[temp])
                                   {
                                      temp--;
                                    }
                      swap(s[to_swap],s[temp]);
            
            reverse(s.begin()+infpt, s.end());
          long res = stol(s);

        // if its more than INT_MAX , then return -1, otherwise res
        return (res > INT_MAX  ) ? -1 : res;
    }
        
};