class Solution {
    class Pair implements Comparable<Pair>{
        
        Character c;
        int count;

        public Pair(Character c, int count) {
            this.c = c;
            this.count = count;
        }

        @Override
        public int compareTo(Pair o) {
            return o.count - this.count;
        }

        @Override
        public String toString() {
            return "Pair [c=" + c + ", count=" + count + "]";
        }

        
    }

    public String reorganizeString(String s) {

        if(s.equals(""))
        {
            return "";
        }

        PriorityQueue<Pair> pq = new PriorityQueue<>();
        
        HashMap<Character,Integer> hm = new HashMap<>();
        for (int i = 0; i < s.length(); i++) {
            Character curKey = s.charAt(i);
            if(hm.containsKey(curKey))
            {
                hm.put(curKey, hm.get(curKey)+1);
            }else{
                hm.put(curKey, 1);
            }
        } 
        
        for (java.util.Map.Entry<Character,Integer> entry : hm.entrySet()) {
            pq.add(new Pair(entry.getKey(), entry.getValue()));
        }


        
        if(pq.size() < 2)
        {
            // pq.size() == 1
            Pair poll = pq.poll();
            if(poll.count > 1)
            {
                // eg: aa
                return "";
            }else{
                // eg: a
                return "" + poll.c;
            }
        }
        
        
        // there is atleast 2 characters
        
        StringBuilder sb = new StringBuilder("@");

        while (pq.size() > 1) {
            // atleast has 2 elements

            Pair poll1 = pq.poll();
            Pair poll2 = pq.poll();

            if(sb.charAt(sb.length()-1) == poll1.c)
            {
                sb.append(poll2.c);
                sb.append(poll1.c);
            }else{
                sb.append(poll1.c);
                sb.append(poll2.c);
            }

            poll1.count--;
            poll2.count--;

            if(poll1.count > 0)
            {
                pq.add(poll1);
            }

            if(poll2.count > 0)
            {
                pq.add(poll2);
            }

        }

        // here pq can have 0 or 1 element
        if(pq.size() == 0)
        {
            return sb.substring(1).toString();
        }        


        // there is 1 elemtent left
        Pair remaining = pq.poll();

        if(remaining.count > 1)
        {
            return "";
        }

        if(sb.charAt(sb.length()-1) == remaining.c)
        {
            return "";
        }

        sb.append(remaining.c);

        return sb.substring(1).toString();
     
    }
}