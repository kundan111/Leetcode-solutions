class Solution {
    public String longestPalindrome(String s) {
                int len = s.length();

        if(len == 0)
        {
            return "";
        }

        boolean[][] arr = new boolean[len][len];

        int maxLen = 1;
        int start = 0;
        int end = 0;

        for (int i = 0; i < len; i++) {
            arr[i][i] = true;
        }

        for (int curLen = 1; curLen <= len; curLen++) {
            for (int i = 0; i < len-1; i++) {
                
                int x = i;
                int y = i + curLen;

                if(isWithin(x, y, len))
                {

                    if(s.charAt(x) != s.charAt(y))
                    {
                        arr[x][y] = false;
                        continue;
                    }

                    int withinX = x + 1;
                    int withinY = y - 1;

                    if(withinY < withinX)
                    {
                        arr[x][y] = (s.charAt(x) == s.charAt(y));
                        
                    }else{
                        arr[x][y] = (s.charAt(x) == s.charAt(y)) && arr[withinX][withinY];
                    }
                    if(arr[x][y] && y - x + 1 > maxLen )
                    {
                        start = x;
                        end = y;
                        maxLen = y-x+1;
                    }
                }

            }
        }

        StringBuilder sb = new StringBuilder();

        for (int i = start; i <= end; i++) {
            sb.append(s.charAt(i));
        }
        
        return sb.toString();
    }
    boolean isWithin(int x, int y, int sz)
    {
        return ((x >=0 && x < sz) && (y >=0 && y < sz));
    }
}