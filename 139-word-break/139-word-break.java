class Solution {
    
    HashMap<String,Integer> hm = new HashMap<>();
    
    HashMap<Integer,Boolean> cache = new HashMap<>();
    
    public boolean wordBreak(String s, List<String> wordDict) {
        
        for (String string : wordDict) {
            hm.put(string, 1);
        }

        return recur(s, 0);
    }
    
    
    boolean recur(String original, int curIndex)
    {
        // System.out.println("recur(original," + curIndex + ")");
        if(curIndex == original.length())
        {
            return true;
        }

        if(cache.containsKey(curIndex))
        {
            return cache.get(curIndex);
        }

        // index is within range
        String tempString = "";
        for (int i = curIndex; i < original.length(); i++) {
            tempString += original.charAt(i);
            if(hm.containsKey(tempString))
            {
                // call for rest part
                 boolean recurRes = recur(original, i+1);
                 if(recurRes)
                 {
                     // System.out.println(tempString + " is part");
                     cache.put(curIndex, true);
                     return  true;
                 }else{
                     continue;
                 }
            }
        }
        
        cache.put(curIndex, false);
        return false;
    }
}