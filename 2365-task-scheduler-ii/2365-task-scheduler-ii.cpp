class Solution {
public:
    long long taskSchedulerII(vector<int>& tasks, int space) {
        int n= tasks.size();
        unordered_map<int,long long> mp; //{task type, day}
        long long day=0;
        int i=0;
        while(i<n){
            if(mp.find(tasks[i])==mp.end()){
                day++;
                mp[tasks[i]]= day;
                i++;
                continue;
            }
            else{
                long long lastday= mp[tasks[i]];
                day= max(lastday+space+1, day+1); 
                    mp[tasks[i]]= day;
                i++;
                continue;
            }
        }
        return day;
    }
};