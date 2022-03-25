class Solution {
    public String longestPalindrome(String s) {
        
        int[] units = new int[128];
        boolean isCharRepeting = false;
        int sz = s.length();

        for (int i = 0; i < sz; i++) {
            if(units[(int)s.charAt(i)] > 0)
            {
                isCharRepeting = true;
            }
            units[(int)s.charAt(i)]++;
        }

        if(!isCharRepeting)
        {
            return "" + s.charAt(0);
        }

        int maxPlindromeLen = 0;
        int start = -1;
        int end = -1;

        char[] charArray = s.toCharArray();

        for (int i = sz-1; i >= 0; i--) {
            for (int j = 0; j < sz; j++) {

                if(isPalindrome(charArray, j, i) && i-j + 1 > maxPlindromeLen)
                {
                    
                    start = j;
                    end = i;  
                    maxPlindromeLen = i-j + 1; 
                }
                
                
            }
        }

        StringBuilder sb = new StringBuilder();

        for (int i = start; i <= end; i++) {
            sb.append(s.charAt(i));
        }
        
        
        // System.out.println("start: " + start + "\n" + "end: " + end);

        return sb.toString();
    }

    public boolean isPalindrome(char[] s, int start, int end)
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
}