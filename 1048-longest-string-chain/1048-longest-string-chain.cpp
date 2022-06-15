class Solution {
public:
    int longestStrChain(vector<string>& words) {
        int n= words.size();
            sort(words.begin(), words.end(), cmp);
            //sorting by length 
            unordered_map<string,int> mp; //{ word, chain len upto that word}
            mp[words[0]]=1;
            int maxlen=0;
            for(auto word: words){ //for each word
                    for(int i=0; i<word.size(); i++){
                            string predecessor = word.substr(0,i) +word.substr(i+1);
                              //skipping ith idx of word
                           
                            mp[word]= max(mp[predecessor]+1, mp[word]);
                    }
                  maxlen= max(mp[word],maxlen);
            }
            return maxlen;
    }
        
       static bool cmp(string& s1, string& s2){
                return s1.size()<s2.size();
        }
};