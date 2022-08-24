class Solution {
public:
    bool checkPowersOfThree(int n) {
        int x = 1;
        stack<int> st;
        
        while(x <= n){
            st.push(x);
            x *= 3;
        }
        //if n=30, we will push 1,3,9,27 in stack
        
        int sum = 0;
        while(st.size()>0){
            if(sum + st.top() <= n){
                sum += st.top();
            }
            st.pop();
        }
        return sum == n;
    }
};