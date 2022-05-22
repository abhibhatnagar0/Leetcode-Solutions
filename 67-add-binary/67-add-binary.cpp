class Solution {
public:
    string addBinary(string num1, string num2) {
         string ans;
         int p1=num1.size()-1;
         int p2=num2.size()-1;
            int carry=0;
         while(p1>=0 or p2>=0){
                 if(p1<0){
                      ans.push_back((num2[p2]-'0'+ carry)%2 +'0');
                      carry= (num2[p2]-'0'+ carry)/2;  
                      p2--;   
                 }
                 else if(p2<0){
                     ans.push_back((num1[p1]-'0'+ carry)%2 +'0');
                     carry= (num1[p1]-'0'+ carry)/2;
                      p1--;
                 }
                 else{
                  ans.push_back((num1[p1]-'0' + num2[p2]-'0'+ carry)%2 +'0');
                  carry= (num1[p1]-'0' + num2[p2]-'0'+ carry)/2;
                   p1--;
                   p2--;      
                 }
         }
                 if(carry!=0)
                         ans.push_back(carry +'0');
            
            reverse(ans.begin(),ans.end());  
      return ans;
    }
};