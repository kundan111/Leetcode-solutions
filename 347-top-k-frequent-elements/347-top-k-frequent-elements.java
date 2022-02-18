class Solution {
    public int[] topKFrequent(int[] nums, int k) {

        Comparator<java.util.Map.Entry<Integer,Integer>> comp = new Comparator<java.util.Map.Entry<Integer,Integer>>() {

            @Override
            public int compare(java.util.Map.Entry<Integer, Integer> o1, java.util.Map.Entry<Integer, Integer> o2) {
                
                return -1*(o1.getValue() - o2.getValue());
            }
            
        };
     
        PriorityQueue<java.util.Map.Entry<Integer,Integer>> pq = new PriorityQueue<>(comp);

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


        
        return res;
    }
}