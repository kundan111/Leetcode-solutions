class Solution {
    public boolean validPalindrome(String s) {

        int[] alpha = new int[26];
        int sz = s.length();

        char[] charArray = s.toCharArray();

        for (int i = 0; i < sz; i++) {
            alpha[charArray[i]-'a']++;
        }

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

        while (i <= j) {
            if(charArray[i] != charArray[j])
            {
                return isPalindrome(charArray, i, j-1) || isPalindrome(charArray, i+1, j);
            }
            i++;
            j--;
        }

        
        return true;
        
    }

    boolean isPalindrome(char[] charArray, int l, int r)
    {
        while(l <= r)
        {
            if(charArray[l] != charArray[r])
            {
                return false;
            }
            l++;
            r--;
        }

        return true;
    }
}