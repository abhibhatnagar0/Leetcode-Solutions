class Solution {
public:
    int longestSubsequence(string s, int k) {
        int n= s.size();
          int len=0;
           int val=0; //decimal value of curr subsequence of string
            bool flag= false; 
            //from back,when we find a 1 whose inclusion makes val>k,
            //so we wont take 1s before that as well
            for(int i=n-1;i>=0;i--){
                   if(s[i]-'0'==0) len++; //all 0s in s will be part of len
                   else{
                             if(flag==false && n-i-1<31){ //include 1s until flag=false
                                //k cannot exceed 1e9......2^31 >1e9 so 2^31 nhi kr payenge kabhi
                                 //if 2^31 is added to val, it will overflow int range
                              val+=pow(2,n-i-1);
                              if(val<=k) len++;
                               else { //for that 1 which make flag=true
                                       flag=true;
                                       val-=pow(2,n-i-1);
                               }
                            }
                   }
            }
         return len;          
    }
};