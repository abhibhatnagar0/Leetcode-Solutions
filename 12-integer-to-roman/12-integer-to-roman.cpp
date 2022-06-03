class Solution {
public:
    string intToRoman(int num) {
    string roman[13]= {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        int value[13]={1000,900,500, 400,100, 90, 50,  40,  10,  9,   5,  4,  1};
            string ans;
        while(num>0){
                for(int i=0;i<13;i++){
                        if(num<value[i]) continue;
                        else{
                                ans+=roman[i];
                                num-=value[i];
                                break;
                        }
                }
        } 
            return ans;
            
    }
};