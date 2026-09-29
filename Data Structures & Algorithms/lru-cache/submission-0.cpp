class LRUCache {
private:
    struct DLLNode {
        int key,value;
        DLLNode* prev;
        DLLNode* next;

        DLLNode(int key, int value) {
            this->key = key;
            this->value = value;
            this->prev = nullptr;
            this->next = nullptr;
        }
    };

    int capacity;
    DLLNode* head;
    DLLNode* tail;
    unordered_map<int,DLLNode*> mp;

    void removeNode(DLLNode* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void moveNodeToEnd(DLLNode* node) {
        this->tail->prev->next = node;
        node->next = this->tail;
        node->prev = this->tail->prev;
        this->tail->prev = node;
    }

    void moveToEnd(DLLNode* node) {
        removeNode(node);
        moveNodeToEnd(node);
    }

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        this->head = new DLLNode(-1,-1);    
        this->tail = new DLLNode(-1,-1);
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(mp.find(key) == mp.end()) return -1;
        DLLNode* node = mp[key];
        moveToEnd(node);
        return node->value;
    }
    
    void put(int key, int value) {
        if(mp.find(key) == mp.end()) {
            if(mp.size() == this->capacity) {
                DLLNode* lru = this->head->next;
                removeNode(lru);
                mp.erase(lru->key);
                delete lru;
            }
            DLLNode* newNode = new DLLNode(key,value);
            mp[key] = newNode;
            moveNodeToEnd(newNode);
        } else {
            DLLNode* node = mp[key];
            node->value = value;
            moveToEnd(node);
        }
    }
};
