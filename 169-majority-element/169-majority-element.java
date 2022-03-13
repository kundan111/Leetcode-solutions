class Solution {
    public int majorityElement(int[] nums) {
        
        HashMap<Integer,Integer> hm = new HashMap<>();
        int sz = nums.length;

        for (int i : nums) {
            if(hm.containsKey(i))    
            {
                hm.put(i, hm.get(i)+1);

            }else{
                hm.put(i, 1);
            }
            if(hm.get(i) > sz/2)
            {
                return i;
            }
        }
     
        return -1;
        
    }
}