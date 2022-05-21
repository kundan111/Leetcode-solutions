class Solution {
    public String minWindow(String s, String t) {
        
        HashMap<Character, Integer> freqMap = buildFreqMap(t);
        

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
                
                 if(curMatchCount == matchCount)
                {
                    if(right - left + 1 < ans)
                    {
                        ans = right - left + 1;
                        finalLeft = left;
                        finalRight = right;
                        
                        if(ans == matchCount)
                        {
                            return s.substring(finalLeft , finalRight+1);
                        }
                    }
                }
            }

            // release
            

            while (right < sz && left < sz && curMatchCount == matchCount) {
                
                if(right - left + 1 < ans)
                {
                    ans = right - left + 1;
                    finalLeft = left;
                    finalRight = right;
                    
                    if(ans == matchCount)
                    {
                        return s.substring(finalLeft , finalRight+1);
                    }
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
                }
                
                left++;
                
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


    
}