class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
            int maxlen=0;
            int currlen=0;
            unordered_set<char> set; //stores unique chars of curr substr
            int i=0,j=0;
            //substring go from j to i
            //i ko substr me lena h kya..this will be checked in every step
            while(i<n){
                    if(set.find(s[i])==set.end()){
                            set.insert(s[i]);
                            currlen= i-j+1;
                            maxlen=max(currlen,maxlen);
                            i++; //for next iterations
                    }
                    else{ //s[i] already present in curr substr,
                          //so j ko aage bdao until s[j] surpasses s[i]
                          //ie set se s[i] hat jayega, then we can see new substrs
                            set.erase(s[j]);
                            j++;
                            // here substr shrink ho rhi h, so maxlen wont increase
                           
                    }
            }
            return maxlen;
    }
};