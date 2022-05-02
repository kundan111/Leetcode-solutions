class SparseVector {

    HashMap<Integer,Integer> hm = new HashMap<>();
    
    SparseVector(int[] nums) {
        for (int i = 0; i < nums.length; i++) {
            if(nums[i] != 0)
            {
                hm.put(i, nums[i]);
            }
        }
    }
    
	// Return the dotProduct of two sparse vectors
    public int dotProduct(SparseVector vec) {

        HashMap<Integer,Integer> vecHm = vec.hm;
        

        int res = 0;
        for (java.util.Map.Entry<Integer,Integer> e : hm.entrySet()) {
            Integer curKey = e.getKey();   
            if(vecHm.containsKey(curKey))
            {
                res += (e.getValue() * vecHm.get(curKey));
            }
        }

        return res;
        
    }
}

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1 = new SparseVector(nums1);
// SparseVector v2 = new SparseVector(nums2);
// int ans = v1.dotProduct(v2);