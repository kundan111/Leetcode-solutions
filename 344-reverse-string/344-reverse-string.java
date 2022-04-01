class Solution {
    public void reverseString(char[] s) {
        int sz = s.length;
        for (int i = 0; i < sz/2; i++) {
            char temp = s[i];
            s[i] = s[sz-i-1];
            s[sz-i-1] = temp;
        }
}
    
}