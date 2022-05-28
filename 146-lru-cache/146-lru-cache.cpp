class LRUCache {
public:
    int cap;// capacity of cache 
    list<int> l; //doubly ll with value as key
    unordered_map<int,list<int>::iterator> m1; //{key,address of key node}
    unordered_map<int,int> m2; //{key,value}
    
    LRUCache(int capacity) {
        cap=capacity; //cap being global variable can be used anywhere
    }
    
    int get(int key) {
        
        if(m2.find(key)==m2.end()) //if that key is not present
            return -1;
        
        l.erase(m1[key]); //l.erase(address of node to be erased)
        l.push_front(key); //making key most recently used(at front)
        m1[key]=l.begin(); //a new address alloted to key at front, so storing it in m1
        
        return m2[key];
    }
    
    void put(int key, int value) {
        
        if(m2.find(key)!=m2.end()) /* if key to be inserted is already present, so new */                 l.erase(m1[key]);  //value will be given to that key, also becomes most                                          recently used node
            
        l.push_front(key);
        m1[key]=l.begin(); //new address of node
        m2[key]=value;     // new value of node
            
        if(cap<m2.size())
        {
            int k=l.back();
            l.pop_back();
            m1.erase(k);
            m2.erase(k);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */