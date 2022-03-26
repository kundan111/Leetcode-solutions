class RandomizedSet {

private ArrayList<Integer> al = new ArrayList<>();
    private HashMap<Integer,Integer> hm = new HashMap<>();

    public RandomizedSet() {
        
    }
    
    public boolean insert(int key) {

        if(!hm.containsKey(key))
        {
            al.add(key);
            hm.put(key, al.size()-1);
            return true;
        }


        return false;
        
    }
    
    public boolean remove(int key) {

        if(hm.containsKey(key))
        {
            int indx = hm.get(key);

            
            
            // swap values in hm
            hm.put(al.get(al.size()-1), indx);
            hm.put(key, al.size()-1);
            
            // swap 
            
            al.set(indx, al.get(al.size()-1));
            al.set(al.size()-1,key);

            // remove from list
            al.remove(al.size()-1);

            
            // remove from hashmap
            
            hm.remove(key);
            return true;

        }

        return false;
        
    }
    
    public int getRandom() {

        
        int randIndx = (int)(Math.random()*al.size());
        
        return al.get(randIndx);
        
        
    }
}

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * boolean param_1 = obj.insert(val);
 * boolean param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */