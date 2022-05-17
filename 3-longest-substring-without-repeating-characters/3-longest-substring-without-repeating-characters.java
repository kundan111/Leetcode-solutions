class Solution {
    public int lengthOfLongestSubstring(String s) {
        
        int[] alpha = new int[256];

        int l = 0;
        int r = 0;

        int sz = s.length();

        int ans = 0;
        

        while (r < sz) {
            while (r < sz && alpha[s.charAt(r)] < 1) {
                ans = Math.max(ans, r-l+1);
                alpha[s.charAt(r)]++;
                r++;
            }

            while (r < sz && l < sz && alpha[s.charAt(r)] > 0) {
                alpha[s.charAt(l)]--;
                l++;
            }
        }
    return ans;
    }
}