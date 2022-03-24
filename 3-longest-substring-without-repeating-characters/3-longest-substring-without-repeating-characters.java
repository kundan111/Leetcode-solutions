class Solution {
    public int lengthOfLongestSubstring(String s) {
        
        int[] alpha = new int[128];

        int left = 0;
        int right = 0;

        int sz = s.length();
        int res = 0;

        while (right < sz) {
            alpha[(int)s.charAt(right)]++;

            while (alpha[(int)s.charAt(right)] > 1) {
                alpha[(int)s.charAt(left)]--;
                left++;
            }
            res = Math.max(res, right-left+1);
            right++;
        }

        return res;
        
    }
}