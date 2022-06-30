class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n= nums.size();
        sort(nums.begin(),nums.end());
        //for odd len of nums, median ke barabar lana hai sbko
        //for even len, any val btw 2 middle elements par la skte hai
        //1,3,8,10
        //1+x=10-y....x+y=9=diff = cost to make first,last equal
        //3+x=8-y.....x+y=5=diff 
        int s=0, e=n-1;
        int minMoves=0;
        while(s<e){
            minMoves+= nums[e]-nums[s];
            s++;
            e--;
        }
        //here either s=e(odd len)...this indicates no jiske barabar sb aayenge
        //s>e(even len)
        return minMoves;
    }
};