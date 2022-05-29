class Solution {
public:
    string largestWordCount(vector<string>& messages, vector<string>& senders) {
            int n=messages.size();
        map<string,int> mp;
            for(int i=0;i<n;i++){
                    mp[senders[i]]+=count_words(messages[i]);
            }
           
            int count=0;
            string ans="";
           for(auto i : mp){
            if(i.second>=count){
                count = i.second;
                if( ans<i.first) ans = i.first;
            }
        }
        
        return ans;
           
    }
        int count_words(string s){
                    int n=s.size();
                            int cnt=1;
                            int i=0;
                   while(n--){
                           if(s[i++]==' ') cnt++;
                   }
                    return cnt;
            }
};