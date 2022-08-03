class MyCalendar {
public:
    map<int,int>mp; //{time,sum till that time}
    //sum=0
    //start time will make sum++, end will make sum--
    //sum shld always be 0 or 1 for non overlapping intervals
    //if sum=2, means 2 events have started before ending
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        mp[start]++;
        mp[end]--;
        int sum=0;
        for(auto p: mp){
           sum+= p.second;
            if(sum>1){
                mp[start]--;
                mp[end]++;
                return false;  
            }  
        }
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */