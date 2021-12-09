class Node{

public:
   Node * next[26] = {NULL};
   bool isComplete = false;

};

class WordDictionary {
private:
    Node *dummyHolder;
public:
    WordDictionary() {
     
        dummyHolder  = new Node;
    }
    
    void addWord(string word) {
        int i = 0;
        int sz = word.size();
        Node * curItr = dummyHolder;
        
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
            Node* Itr = dummyHolder;
            return Trie_search(word,Itr,0,word.size());
    }
    
    bool Trie_search(string s,Node *curr,int pos,int n)
    {        
        if(s[pos]=='.')
        {
            bool res = false;
            Node *current = curr;
            for(int i=0;i<26;++i)
            {
                if(pos==n-1 && curr->next[i])
                {
                    current=curr->next[i];
                    res |= current->isComplete ?true:false;
                }
                else if(curr->next[i] && Trie_search(s,curr->next[i],pos+1,n))
                    return true;
            }
            return res;
        }
        else if(curr->next[s[pos]-'a'])
        {
            if(pos==n-1)
            {
                curr = curr->next[s[pos]-'a'];
                return curr->isComplete ?true:false;
            }
            return Trie_search(s,curr->next[s[pos]-'a'],pos+1,n);
        }
        return false;
    }
    
    
    
    
    
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */