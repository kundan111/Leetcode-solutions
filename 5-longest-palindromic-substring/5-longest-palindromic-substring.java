class Solution {
    int sz;
    int ans = 1;
    int finalLeft = 0;
    int finalRight = 0;
    
    
    public String longestPalindrome(String s) {
        this.sz = s.length();

        for (int i = 0; i < sz; i++) {
            countPalindromes(s, i, i);
        }

        for (int i = 0; i < sz; i++) {
            countPalindromes(s, i, i+1);
        }


        return s.substring(finalLeft, finalRight+1);
    }

    boolean isWithin(int l ,int r)
    {
        return (l >=0 && r < sz);
    }

    void countPalindromes(String s, int l, int r)
    {
        while (isWithin(l, r)) {
            if(s.charAt(l) == s.charAt(r))
            {
                if(r-l + 1 > ans)
                {
                    ans = r-l+1;
                    finalLeft = l;
                    finalRight = r;
                }
                l--;
                r++;


            }else{
                break;
            }
        }
        
        return;
        
        
    }
}