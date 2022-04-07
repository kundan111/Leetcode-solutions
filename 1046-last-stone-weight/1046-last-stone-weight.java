class Solution {
   public int lastStoneWeight(int[] stones) {
     
        PriorityQueue<Integer> pq = new PriorityQueue<>((a,b) -> b-a);

        for (Integer val : stones) {
            pq.add(val);
        }

        while (pq.size() > 1) {
            int firstHeavy = pq.poll();
            int secondHeavy = pq.poll();

            if(firstHeavy != secondHeavy)
            {
                pq.add(Math.abs(firstHeavy-secondHeavy));
            }
        }

        if(pq.size() > 0)
        {
            return pq.poll();
        }
       
        
        
        return 0;
    }
}