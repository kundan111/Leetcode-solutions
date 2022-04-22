class MyHashMap {

     int[] data = new int[1000001];

    public MyHashMap() {
        int sz = data.length;
        for (int i = 0; i < sz; i++) {
            data[i] = -1;
        } 
    }
    
    public void put(int key, int value) {
        data[key] = value;
    }
    
    public int get(int key) {
        return data[key];
        
    }
    
    public void remove(int key) {
        if(data[key] != -1)
        {
            data[key] = -1;
        }
        
    }
}

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap obj = new MyHashMap();
 * obj.put(key,value);
 * int param_2 = obj.get(key);
 * obj.remove(key);
 */