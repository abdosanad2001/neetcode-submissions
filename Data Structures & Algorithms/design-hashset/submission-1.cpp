class MyHashSet {
    // using chaing AKA:'Linked List',T=O(n/k);S=O(n+k)
private:
    struct ListNode{
        int key;
        ListNode* next;

        ListNode(int key=false,ListNode* next=nullptr){
            this->key=key;
            this->next=next;
        }
    };
    vector<ListNode*> set;
    int hash(int key){
        return key%set.size();
    }
public:
    MyHashSet() {
        set.resize(1000000);
        for(auto& bucket : set){
            bucket=new ListNode(0);
        }
        
    }
    
    void add(int key) {
       ListNode* cur=set[hash(key)];
       while(cur->next){
            if(cur->next->key==key){
                return;
            }
            cur=cur->next;
       }
       cur->next=new ListNode(key);
    }
    
    void remove(int key) {
        ListNode* cur=set[hash(key)];
       while(cur->next){
            if(cur->next->key==key){
                ListNode* temp=cur->next;
                cur->next=cur->next->next;
                delete temp;
                return;
            }
            cur=cur->next;
       }
       
    }
    
    bool contains(int key) {
       ListNode* cur=set[hash(key)];
       while(cur->next){
            if(cur->next->key==key){
                return true;
            }
            cur=cur->next;
       }
       return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */