class Solution {
    public boolean isAnagram(String s, String t) {

   int lengthOfS = s.length();
        int lengthOfT = t.length();

        if(lengthOfS != lengthOfT)
        {
            return false;
        }

        int[] arr = new int[26];

        for (int i = 0; i < lengthOfS; i++) {
            arr[s.charAt(i) - 'a']++;
        }

        for (int i = 0; i < lengthOfT; i++) {
            if(arr[t.charAt(i) - 'a'] == 0)
            {
                return false;
            }

            arr[t.charAt(i) - 'a']--;
        }
        

        return true;
    }
}