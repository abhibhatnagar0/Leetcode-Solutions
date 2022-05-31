class Solution {
public:
    bool hasAllCodes(string s, int k) {
            int n=s.size();
            if(n<k) return false;
        //total binary nos of length k = 2^k
            //if k=3 ....0 to 7
          //check every unique substring of s using sliding window
            unordered_set<string> set;
            
            for(int i=0;i<=n-k;i++){
                    set.insert(s.substr(i,k));
            }
            if(set.size()== pow(2,k)) return true;
            else return false;
    }
};