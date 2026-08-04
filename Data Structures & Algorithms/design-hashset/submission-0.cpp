class MyHashSet {
    // using direct addressing with a boolean array,T=O(1);S=O(10^6)
private:
    vector<bool> set;
public:
    MyHashSet():set(1000001, false) {
        
    }
    
    void add(int key) {
        set[key]=true;
    }
    
    void remove(int key) {
        set[key]=false;
    }
    
    bool contains(int key) {
        return set[key];
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */