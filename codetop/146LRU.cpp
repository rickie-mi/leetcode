struct doubleList{
    int key, val;
    doubleList *pre, *next;
    doubleList(int k=0, int v=0){key=k; val=v; pre=nullptr; next=nullptr;}
};
class LRUCache {
private:
    doubleList *head, *tail;
    int size, cap;
    unordered_map<int, doubleList*> mp;
public:
    LRUCache(int capacity) {
        head = new doubleList();
        tail = new doubleList();
        cap = capacity;
        size = 0;
        head->next = tail;
        tail->pre = head;
    }
    
    int get(int key) {
        if(mp.count(key)){
            doubleList *temp = mp[key];
            deleteNode(temp);
            addNode(temp);
            return temp->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.count(key)){
            doubleList *temp = mp[key];
            temp->val = value;
            deleteNode(temp);
            addNode(temp);
        }
        else
        {
            if(size == cap)
            {
                size--;
                removeFirst();
            }
            doubleList* temp = new doubleList(key, value);
            mp[key] = temp;
            addNode(temp);
            size++;
        }
        
    }

    void addNode(doubleList* temp){
        temp->pre = tail->pre;
        temp->next = tail;
        tail->pre->next = temp;
        tail->pre = temp;
    }

    void deleteNode(doubleList* temp){
        temp->pre->next = temp->next;
        temp->next->pre = temp->pre;
    }

    void removeFirst(){
        mp.erase(head->next->key);
        deleteNode(head->next);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */