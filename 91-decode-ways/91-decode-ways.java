class Solution {
    HashMap<Integer,Integer> hm = new HashMap<>();
    public int numDecodings(String s) {
        
        if(s.length() == 0)
        {
            return 0 ;
        }

        if(s.charAt(0) == '0')
        {
            return 0;
        }
     
        return recur(s, 0);
    }
    

    int recur(String s, int curPos)
    {
        if(s.length() == curPos)
        {
            return 1;
        }

        if(s.charAt(curPos) == '0')
        {
            return 0;
        }

        if(hm.containsKey(curPos))
        {
            return hm.get(curPos);
        }

        int takingOneChar = recur(s, curPos+1);
        int takingTwoChar = 0;
        if(s.length() - curPos >= 2)
        {
            // check validity then call
            String checkIt = s.substring(curPos, curPos+2);
            if(isWithinRange(checkIt))
            {
                // check if checkit is between 10 and 26 inclusive
                takingTwoChar = recur(s, curPos+2);
            }
        }
        int retValue = takingOneChar + takingTwoChar;

        hm.put(curPos, retValue);

        return retValue;
    }

    boolean isWithinRange(String s)
    {
        int val = Integer.parseInt(s);

        return 10 <= val && val <= 26;
    }
}