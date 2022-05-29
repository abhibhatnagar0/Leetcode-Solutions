class Solution {
public:
    int maxProduct(vector<string>& words) {
        // har 2 words ko compare krne me O(n2) toh lgega hi
        // but har 2 words me saare char ko bhi compare kia toh O(n*n*len*len) lgega
        // by bit manipulation
            // a - 0000000000000000000000000000000000000001 (32 bit me se 26 me 1 aa skta)
            // b - 0000000000000000000000000000000000000010
            // d - 0000000000000000000000000000000000001000 ('d'-'a' times left shift)
            //abd- 0000000000000000000000000000000000001011 (a|b|d)
            int n=words.size(); //total words
            int maxPro=0;
            for(int i=0;i<n-1;i++){
                    int s1= stringtostate(words[i]);
                    for(int j=i+1;j<n;j++){
                            int s2= stringtostate(words[j]);
                            if((s1 & s2) ==0){ //2 strings have no char in commom
                                    int pro= words[i].size() * words[j].size();
                                    maxPro=max(maxPro,pro);
                            }
                    }
            }
            return maxPro;     
    }
        int stringtostate(string s){
                int state=0;
                for(char c:s){
                    int charState= 1<<(c-'a');
                        state|=charState;
                }
                return state;
        }
};