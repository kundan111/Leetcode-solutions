class Node{
    
    Node[] next = new Node[26];
    boolean isComplete = false;
    
}
class Trie {

    Node holder;
    public Trie() {
        holder = new Node();    
    }
    
    public void insert(String word) {
        
        Node curIterator = holder;

        int sz = word.length();
        int i = 0;
        while(i < sz)
        {
            int curChar = word.charAt(i) - 'a';
            if(curIterator.next[curChar] == null)
            {
                curIterator.next[curChar] = new Node();
            }
            curIterator = curIterator.next[curChar];
            i++;
        }
        curIterator.isComplete = true;
    }
    
    public boolean search(String word) {
        
        int sz = word.length();
        int i = 0;

        Node curIterator = holder;

        while (i < sz) {
            
            int curChar = word.charAt(i) - 'a';
            
            if(curIterator.next[curChar] == null)
            {
                return false;
            }

            curIterator = curIterator.next[curChar];
            i++;

        }

        return curIterator.isComplete;
        
    }
    
    public boolean startsWith(String prefix) {
        

        int sz = prefix.length();
        int i = 0;

        Node curIterator = holder;

        while (i < sz) {
            
            int curChar = prefix.charAt(i) - 'a';
            
            if(curIterator.next[curChar] == null)
            {
                return false;
            }

            curIterator = curIterator.next[curChar];
            i++;

        }

        return true;

        
    }
    
}

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * boolean param_2 = obj.search(word);
 * boolean param_3 = obj.startsWith(prefix);
 */