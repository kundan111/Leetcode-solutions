class Solution {
    public String longestPalindrome(String s) {
        

        int sz = s.length();
        char[] charArray = s.toCharArray();


        for (int curLen = sz;  curLen >= 1; curLen--) {
            int start = 0;
            while (start + curLen - 1 < sz) {
                if(isPalindrome(charArray, start, start+curLen-1)){
                    return PalindromeBuilder(charArray, start, start+curLen-1);
                }
                start++;

            }
        }
  
        return "";
    }

    boolean isPalindrome(char[] s, int start, int end)
    {
        while(start <= end)
        {
            if(s[start] != s[end])
            {
                return false;
            }
            start++;
            end--;
        }

        return true;
    
    }
    String PalindromeBuilder(char[] s, int start, int end)
    {
        String ret = "";
        for (int i = start; i <= end; i++) {
            ret += s[i];
        }

        return ret;
    }
}