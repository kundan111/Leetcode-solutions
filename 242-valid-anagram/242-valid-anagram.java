class Solution {
    public boolean isAnagram(String s, String t) {

   int lengthOfS = s.length();
        int lengthOfT = t.length();

        if(lengthOfS != lengthOfT)
        {
            return false;
        }
        HashMap<Character,Integer> hm = new HashMap<>();

        for (int i = 0; i < lengthOfS; i++) {
            if(hm.containsKey(s.charAt(i)))
            {
                hm.put(s.charAt(i), hm.get(s.charAt(i)) +1 );
            }else{
                hm.put(s.charAt(i), 1);
            }
        }


        for (int i = 0; i < lengthOfT; i++) {
            if(!hm.containsKey(t.charAt(i)))
            {
                return false;
            }
            hm.put(t.charAt(i), hm.get(t.charAt(i)) - 1);
            if(hm.get(t.charAt(i)) == 0)
            {
                hm.remove(t.charAt(i));
            }
        }
        

        return true;
    }
}