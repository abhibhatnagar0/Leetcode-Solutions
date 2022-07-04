class Solution {
public:
    int candy(vector<int>& ratings) {
        int n= ratings.size();
        vector<int> left(n,1);
        for(int i=1;i<n;i++){
            if(ratings[i]>ratings[i-1]) left[i]=left[i-1]+1;
            else left[i]=1;
        }
        int right=1;
        for(int i=n-2;i>=0;i--){
            if(ratings[i]>ratings[i+1]){
                right++;
                left[i]=max(left[i],right);
            }
            else{
                right=1;
                continue;
            }
        }
        int candiesSum=0;
        for(auto x:left) candiesSum+=x;
        
        return candiesSum;
    }
    /* see first relative to left, and relative to right
    left will say whenever a rating is greater than its previous      looking from left,
    increase candies there by 1.
    right will say whenver a rating is greater than its next looking from right, increase its candies by 1 (from right)
    CANDIES WITH ANY CHILD IS THE MAX OF THAT RELATIVE TO LEFT AND RIGHT.
    ie if my rating is greater than my neighbours(from left and right) my candies will be larger than both.
    */
};