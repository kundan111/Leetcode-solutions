class Solution {
    public boolean isAnagram(String s, String t) {

        if(s.length() != t.length())
        {
            return false;
        }


        // sort both the string
        char[] charArrayOfS = s.toCharArray();
        char[] charArrayOfT = t.toCharArray();
        
        Arrays.sort(charArrayOfS);
        Arrays.sort(charArrayOfT);

        for (int i = 0; i < charArrayOfT.length; i++) {
            if(charArrayOfS[i] != charArrayOfT[i])
            {
                return false;
            }
        }
        
        return true;
    }
}