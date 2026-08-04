class MyHashMap {
    
private:
    struct ListNode{
        int key,val;
        ListNode* next;
        ListNode(int key=-1,int val=-1,ListNode* next=nullptr){
            this->key=key;
            this->val=val;
            this->next=next;
        }
    };
    vector<ListNode*> map;
    int hash(int key){
        return key%map.size();
    }
public:
    MyHashMap() {
        map.resize(10009);//avoid collision 
        for(auto& bucket :map){
            bucket=new ListNode(0);
        }
    }
    
    void put(int key, int value) {
        ListNode* cur=map[hash(key)];//intialize at dummy node
        while(cur->next){
            if(cur->next->key==key){
                cur->next->val=value;
                return;
            }
            cur=cur->next;
        }
        cur->next=new ListNode(key,value);
    }
    
    int get(int key) {
        ListNode* cur=map[hash(key)]->next;//intialize at dummy node->next
        while(cur){
            if(cur->key==key){
                return cur->val;
            }
            cur=cur->next;
        }
        return -1;
    }
    
    void remove(int key) {
        ListNode* cur=map[hash(key)];//at dummy node
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
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */