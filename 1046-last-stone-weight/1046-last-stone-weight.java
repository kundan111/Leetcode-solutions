class Solution {
    public int lastStoneWeight(int[] stones) {
        
        
        PriorityQueue<Integer> pq = new PriorityQueue<Integer>(new MyComp());
        
        for(int stone : stones)
        {
            pq.add(stone);
        }
        
        while(pq.size() > 1)
        {
            int out1 = pq.poll();
            int out2 = pq.poll();
            
            if(out1 != out2)
            {
                pq.add(Math.abs(out1-out2));
            }
        }
        
        return pq.size() == 1 ? pq.peek() : 0;
    }
}

class MyComp implements Comparator{
    
    public int compare(Object A,Object B)
    {
        Integer f = (Integer)A;
        Integer s = (Integer)B;
        
        int a = f.intValue();
        int b = s.intValue();
        
        return b-a;
        
        
    }
}