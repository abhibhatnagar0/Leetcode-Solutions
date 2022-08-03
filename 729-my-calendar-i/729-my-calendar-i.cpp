class MyCalendar {
public:
        set<pair<int,int>>v;// stores all non-overlapping intervals {end time, start time}
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        auto it = v.upper_bound({start,end}); //finds an end e' from set such that e' > start
        //this interval {start,end} only valid if it ends before starting of s'
         //                   s'              e'
         // start      end 
     if(it!=v.end() && it->second<end)
     {     //                   s'              e'
           //     start             end 
         return false;
     }
    v.insert({end,start});
    return true;
    }
    //just compare with upper bound wala it
    //as it-- wala kbhi overlap nhi kr payega {start,end} ko
    //agar it-- wala operlap kb rha hota ...toh it-- ka first would
    //be greater than end, ie it-- wala hi upper bound hota
    
};


/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */