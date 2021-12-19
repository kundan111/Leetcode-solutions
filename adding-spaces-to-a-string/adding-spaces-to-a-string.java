class Solution {
    public String addSpaces(String s, int[] spaces) {
        StringBuffer res = new StringBuffer("");
        int sz1 = s.length();
        int sz2 = spaces.length;
        int prev = 0;
        for(int i = 0; i < sz2; i++)
        {
            int curIndx = spaces[i];
            StringBuffer temp = new StringBuffer("");
            int cur = prev;
            
            while(cur < sz1 && cur < curIndx)
            {
                temp.append(s.charAt(cur));
                cur++;
            }
            
            
            res.append(temp + " ");
            
            prev = cur;
        }
        
        if(prev < sz1)
        {
            res.append(s.substring(prev));
        }
        
        return res.toString();
    }
}