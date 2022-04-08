class KthLargest {

    private PriorityQueue<Integer> maxPq1 = new PriorityQueue<>((a,b) -> (b-a));
    private PriorityQueue<Integer> maxPq2 = new PriorityQueue<>((a,b) -> (b-a));
    private PriorityQueue<Integer> minPq = new PriorityQueue<>((a,b) -> (a-b));
    int threshhold = -1;

    public KthLargest(int k, int[] nums) {
        threshhold = k;
        
        // create a max heap of k largest elements
        for (int val : nums) {
            maxPq1.add(val);
        }

        int count = 0;
        while (count < k && maxPq1.size() > 0) {
            maxPq2.add(maxPq1.poll());
            count++;
        }


        


        // create a min heap of k largest elements

        while (!maxPq2.isEmpty()) {
            int cur = maxPq2.poll();
            // System.out.print(cur + " ");
            minPq.add(cur);
        }
        // System.out.println();

    }
    
    public int add(int val) {

        if(minPq.size() < threshhold)
        {
            minPq.add(val);
            return minPq.peek();
        }

        
        if(val < minPq.peek())
        {
            return minPq.peek();
        }

        minPq.poll();
        minPq.add(val);

        return minPq.peek();
        
    }
}