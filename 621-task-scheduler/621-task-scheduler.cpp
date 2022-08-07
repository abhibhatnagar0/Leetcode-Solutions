class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26,0);
        for(auto t: tasks){
            freq[t-'A']++;
        }
        
        sort(freq.begin(),freq.end(), greater<int>());
        //task with greatest freq has freq= freq[0]
        //freq[0] pos occupied by that task
        //btw any 2 task(of same type) n spaces for other tasks
        //gaps after 1st task (freq[0]-1)*n
        //task with 2nd most freq will reduce gap
        
        //if at any pt, gap<0....that means no cooldown req
        //so ans will be tasks.size()
        
        int gaps= (freq[0]-1)*n;
        for(int i=1;i<freq.size();i++){
            gaps-=min(freq[i],freq[0]-1);
            //when(freq[1]<freq[0], freq[1]=freq[0])
            if(gaps<0) break;
        }
        return tasks.size() + max(0,gaps);
        
        
        
    }
};