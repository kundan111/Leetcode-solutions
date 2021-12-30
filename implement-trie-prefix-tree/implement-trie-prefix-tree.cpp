class Node{
    public:
   Node * next[26] = {NULL};
    bool isComplete;
public:
    Node()
    {
        isComplete = false;    
    }
};
class Trie {
private:
    Node *dummyHolder;
public:
    Trie() {
        
     dummyHolder  = new Node;
    
    }
    
    void insert(string word) {
        
        int i = 0;
        int sz = word.size();
        Node * curItr = dummyHolder;
        Node * yo = dummyHolder;
        
        while(i < sz)
        {
            
            int cur = word[i]-'a';
            
            if(!curItr->next[cur])
            {
                curItr->next[cur] = new Node;
            }
            curItr = curItr->next[cur];
            
            i++;
            
        }
        
        curItr->isComplete = true;
    }
    
    bool search(string word) {
        
        int i = 0;
        int sz = word.size();
        Node * curItr = dummyHolder;
        while( i < sz)
        {
            if(!curItr->next[word[i]-'a'])
            {
                return false;
            }
            curItr = curItr->next[word[i]-'a'];
            
            if(i == sz-1)
            {
                return curItr->isComplete;
            }
            
            i++;
        }
        
        return false;
        
    }
    
    bool startsWith(string prefix) {
        int i = 0;
        int sz = prefix.size();
        Node * curItr = dummyHolder;
        while( i < sz)
        {
            if(!curItr->next[prefix[i]-'a'])
            {
                return false;
            }
            curItr = curItr->next[prefix[i]-'a'];
            
            i++;
        }
        
        return true;
    }
    
    
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */