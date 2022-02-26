public class MyHashSet {
    private HashMap<Integer,Integer> hs;
    public MyHashSet() {
        hs = new HashMap<>();
    }
    
    public void add(int key) {
        if(!hs.containsKey(key))
        {
            hs.put(key, 1);
        }
    }
    
    public void remove(int key) {
        if(hs.containsKey(key))
        {
            hs.remove(key);
        }
    }
    
    public boolean contains(int key) {
        
        return hs.containsKey(key);

    }
}

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet obj = new MyHashSet();
 * obj.add(key);
 * obj.remove(key);
 * boolean param_3 = obj.contains(key);
 */