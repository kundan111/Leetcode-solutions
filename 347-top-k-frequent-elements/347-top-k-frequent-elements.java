class Solution {
    public int[] topKFrequent(int[] nums, int k) {

        PriorityQueue<java.util.Map.Entry<Integer,Integer>> pq = new PriorityQueue<>((a,b) -> -1*(a.getValue() - b.getValue()));

        HashMap<Integer,Integer> hm = new HashMap<>();
        
        for (int val : nums) {
            if(hm.containsKey(val))
            {
                int prevFreq = hm.get(val);
                hm.put(val, prevFreq+1);
            }else{
                hm.put(val, 1);
            }
        }

        for (java.util.Map.Entry<Integer,Integer> entry : hm.entrySet()) {
            pq.offer(entry);
        }

        
        int counter = 0;
        int[] res = new int[k];

        while (counter < k) {
            res[counter] = pq.poll().getKey();
            counter++;    
        }

        
        pq.clear();
        
        return res;
    }
}