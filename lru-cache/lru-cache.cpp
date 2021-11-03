class Node{
public:
    int key;
    int value;
    Node* next;
    Node* prev;
    Node(int _key , int _val)
    {
        this->key = _key;
        this->value = _val;
        this->next = NULL;
        this->prev = NULL;
    }
};

class LRUCache {
private:
    int cap;
    unordered_map<int, Node*> m;
    Node* s;
    Node* e;
public:
    LRUCache(int capacity) {
        this->cap = capacity;
        
        s = new Node(-1,-1);
        e = new Node(-1,-1);
        
        s->next = e;
        e->prev = s;
        
        
    }
    
    int get(int key) {
        
        auto itr = m.find(key);
        if( itr != m.end())
        {
            // take the value
            Node* temp = itr->second;
            int res = temp->value;
            m.erase(key);
            // update the values in ll
            deleteNode(temp);
            addNode(temp);
            m[key] = s->next;
            
            return res;
        }
        
        return -1;
    }
    
    void put(int key, int value) {
        
        if(m.find(key) != m.end())
        {
            Node * existingNode = m[key];
            m.erase(key);
            deleteNode(existingNode);
        }
        
        if(m.size() == cap)
        {
            m.erase(e->prev->key);
            deleteNode(e->prev);
        }
        
        addNode(new Node(key,value));
        m[key] = s->next;
    }
    
    void deleteNode(Node* cur)
    {
        Node *delprev = cur->prev;
        Node *delnext = cur->next;
        
        delprev->next = delnext;
        delnext->prev = delprev;
        
        
        
    }
    
    void addNode(Node* cur)
    {
        Node *temp = s->next;
        s->next = cur;
        cur->prev = s;
        cur->next = temp;
        temp->prev = cur;
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */