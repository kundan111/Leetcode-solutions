class Solution {
    public boolean validPalindrome(String s) {

        int[] alpha = new int[26];
        int sz = s.length();

        // char[] charArray = s.toCharArray();

        // O(N)
        for (int i = 0; i < sz; i++) {
            alpha[s.charAt(i)-'a']++;
        }

        // O(1)
        int oddCount = 0;
        for (int val : alpha) {
            if((val & 1) != 0)
            {
                oddCount++;
            }
            if(oddCount > 2)
            {
                return false;
            }
        }

        /*
        Here we have to check if deleting atmost one character can make it a palindrome
        */

        int i = 0;
        int j = sz-1;

        // O(N)
        while (i <= j) {
            if(s.charAt(i) != s.charAt(j))
            {
                return isPalindrome(s, i, j-1) || isPalindrome(s, i+1, j);
            }
            i++;
            j--;
        }

        
        return true;
        
    }
    
    boolean isPalindrome(String s, int l, int r)
    {
        while(l <= r)
        {
            if(s.charAt(l) != s.charAt(r))
            {
                return false;
            }
            l++;
            r--;
        }

        return true;
    }
}