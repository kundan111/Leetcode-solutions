class Solution {
    public int findKthLargest(int[] nums, int k) {
        
        /*
            Read more about heap: https://www.geeksforgeeks.org/priority-queue-class-in-java/  
        */
        Comparator<Integer> c = new Comparator<Integer>() {

            @Override
            public int compare(Integer o1, Integer o2) {
                
                return -(o1-o2);
            }
            
        };
        
        PriorityQueue<Integer> pq = new PriorityQueue<>(c);

        for (Integer i : nums) {
            pq.offer(i);
        }

        int counter = 0;
        while (counter < k-1) {
            pq.poll();
            counter++;
        }
        
        Integer res = pq.poll();
        pq.clear();

        return res;
    }
}