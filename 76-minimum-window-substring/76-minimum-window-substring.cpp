class Solution {
public:
    string minWindow(string s, string t) {
        int n= s.size();
        int m= t.size();
            
            string ans= "";
            if(m>n) return ans; //size of s shld be greater than that of t
            int minlen= INT_MAX;
            
        unordered_map<char,int> mp; //{char,freq} in t string
            for(char c: t){
                    mp[c]++;
            }
            
        unordered_map<char,int> mp2; //{char,freq} in curr substr of s
            int count=0; //whenevr a char of t is found in s, count++
            //count==t.size() means ki subarry mil gya 
            
        int i=0,j=0;
            while(j<n){
                    if(mp[s[j]]==0) { //for a char of s which is not in t
                            j++;      //no need to store its freq in mp2
                            continue;
                    }
                    else mp2[s[j]]++;
                    
                    if(mp2[s[j]]<= mp[s[j]]){
                            count++;
                    }
                    
                    if(count==m){
                            while(mp[s[i]]==0 || mp2[s[i]]>mp[s[i]]){//shrinking subarray if either s[i] not in mp,
                                    mp2[s[i]]--;                     // or mp2 have its freq more than req
                                    i++;
                            }
                            if(j-i+1 < minlen){ //after shrinking (i,j) subarray is a candidate of being ans
                                    minlen=j-i+1;  //if its len is smaller
                                    ans= s.substr(i,minlen);
                            }
                            
                     }
                   j++;      
            }
         
            return ans;
    }
};