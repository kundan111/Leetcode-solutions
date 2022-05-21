class Solution {
    public String minWindow(String s, String t) {
        
        HashMap<Character, Integer> freqMap = buildFreqMap(t);
        // List<Integer> charIndexList = buildCharIndex(freqMap, s);

        // return sol1(s, charIndexList, freqMap,t);

        return sol2(freqMap, s, t.length());
    }

    String sol2(HashMap<Character, Integer> freqMap, String s, int matchCount)
    {

        int left = 0;
        int right = 0;


        int sz = s.length();
        int curMatchCount = 0;
        int ans = Integer.MAX_VALUE;
        HashMap<Character, Integer> tempHm = new HashMap<>();
        int finalLeft = -1;
        int finalRight = -1;

        while (right < sz) {

            // acquire 
            while (right < sz && curMatchCount < matchCount) {
                
                char curChar = s.charAt(right);
                if(freqMap.containsKey(curChar))
                {
                    
                    int curCount = tempHm.getOrDefault(curChar, 0);

                    if(freqMap.get(curChar) > curCount)
                    {
                        curMatchCount++;
                    }

                    tempHm.put(curChar, curCount + 1);
                }
                if(curMatchCount < matchCount)
                {

                    right++;
                }
            }

            
            

            if(curMatchCount == matchCount)
            {
                if(right - left + 1 < ans)
                {
                    ans = right - left + 1;
                    finalLeft = left;
                    finalRight = right;
                }
                // System.out.println("intermediate1: "  + s.substring(finalLeft, finalRight+1));
                
            }

            // release

            while (right < sz && left < sz && curMatchCount == matchCount) {
                
                if(right - left + 1 < ans)
                {
                    ans = right - left + 1;
                    finalLeft = left;
                    finalRight = right;
                    // System.out.println("intermediate2: "  + s.substring(finalLeft, finalRight+1));
                }

                char curChar = s.charAt(left);

                if(tempHm.containsKey(curChar))
                {
                    int val = tempHm.get(curChar);
                    tempHm.put(curChar, val-1);
                    
                    if(val-1 < freqMap.get(curChar))
                    {
                        curMatchCount--;
                    }
                    left++;
                }else{
                    left++;
                }
                
            }
            right++;

        }

        // "ADOBECODEBANC"

        if(ans == Integer.MAX_VALUE)
        {
            return "";
        }

        
        return s.substring(finalLeft , finalRight+1);
    }







    HashMap<Character, Integer> buildFreqMap(String t)
    {
        HashMap<Character, Integer> freqMap = new HashMap<>();

        for (int i = 0; i < t.length(); i++) {
            freqMap.put(t.charAt(i), freqMap.getOrDefault(t.charAt(i), 0) +1 );
        }


        return freqMap;
    }


    List<Integer> buildCharIndex(HashMap<Character, Integer> freqMap, String s)
    {
        List<Integer> res = new ArrayList<>();

        for (int i = 0; i < s.length(); i++) {
            if(freqMap.containsKey(s.charAt(i)))
            {
                res.add(i);
            }
        }

        return res;
    }


    String sol1(String s, List<Integer> charIndexList, HashMap<Character, Integer> freqMap, String t)
    {

        int sz = charIndexList.size();
        int start = -1;
        int end = -1;
        HashMap<Character, Integer> original = new HashMap<>(freqMap);
        int i = 0;
        int minLen = Integer.MAX_VALUE;
        int finalStart = -1;
        int finalEnd = -1;
        while(i < sz)
        {
            
            start = charIndexList.get(i);
            int k = i;

            
            
            while (k < sz && freqMap.size() > 0) {
                char curChar = s.charAt(charIndexList.get(k));
                if(freqMap.containsKey(curChar))
                {
                    deleteFromHash(freqMap, curChar);   
                }
                if(freqMap.size() == 0)
                {
                    end = charIndexList.get(k);  
                    // System.out.println("intermediate: " + s.substring(start, end+1));
                    if((end - start + 1) < minLen) 
                    {
                        finalStart = start;
                        finalEnd = end;
                        minLen = (end - start + 1);

                        if(minLen == t.length())
                        {
                            return s.substring(finalStart , finalEnd+1);
                        }
                    }
                }
                k++;
            }

            freqMap = new HashMap<>(original);

            i++;

            

        }


        if(finalEnd == -1 || finalStart == -1)
        {
            return "";
        }

        return s.substring(finalStart , finalEnd+1);
        
    }
    
    void deleteFromHash(HashMap<Character, Integer> hash, char key)
    {
        if(!hash.containsKey(key))
        {
            return;
        }

        int newVal = hash.get(key) - 1;

        if(newVal == 0)
        {
            hash.remove(key);
            return;
        }

        hash.put(key, newVal);
    }
}