class Solution {
    public boolean isPalindrome(String s) {
        
        int sz = s.length();

        int i = 0;
        int j = s.length() - 1;

        while (j >= i) {
            while(i < sz && !isChar(s.charAt(i)))
            {
                i++;
            }
            while(j >= 0 && !isChar(s.charAt(j)))
            {
                j--;
            }

            if(i < sz && j >= 0 &&  Character.toLowerCase(s.charAt(i))  !=  Character.toLowerCase(s.charAt(j)))
            {
                return false;
            }
            i++;
            j--;
        }


        return true;
    }

    boolean isChar(char c)
    {
        return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'));
    }
}