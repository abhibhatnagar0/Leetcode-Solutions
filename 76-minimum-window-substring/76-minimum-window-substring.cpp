class Solution {
public:
    string minWindow(string s, string t) {
        int n= s.size();
        int m= t.size();
            
            string ans= "";
            if(m>n) return ans;
            int minlen= INT_MAX;
            
        unordered_map<char,int> mp; //{char,freq} in t string
            for(char c: t){
                    mp[c]++;
            }
            
        unordered_map<char,int> mp2; //{char,freq} in curr substr of s
            int count=0;
            
        int i=0,j=0;
            while(j<n){
                    mp2[s[j]]++;
                    if(mp2[s[j]]<= mp[s[j]]){
                            count++;
                    }
                    
                    if(count==m){
                            while(mp[s[i]]==0 || mp2[s[i]]>mp[s[i]]){
                                    mp2[s[i]]--;
                                    i++;
                            }
                            if(j-i+1 < minlen){
                                    minlen=j-i+1;
                                    ans= s.substr(i,minlen);
                            }
                            
                     }
                   j++;      
            }
            cout<<count;
            return ans;
    }
};