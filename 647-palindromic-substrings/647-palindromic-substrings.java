class Solution {
    int sz;
    public int countSubstrings(String s) {
       
        this.sz = s.length();

        int res = 0;
        for (int i = 0; i < sz; i++) {
            res += countPalindromes(s, i, i);
        }

        for (int i = 0; i < sz; i++) {
            res += countPalindromes(s, i, i+1);
        }

        
        return res;
        
    }

    boolean isWithin(int l ,int r)
    {
        return (l >=0 && r < sz);
    }

    int countPalindromes(String s, int l, int r)
    {
        int res = 0;
        while (isWithin(l, r)) {
            if(s.charAt(l) == s.charAt(r))
            {
                res++;
            }else{
                break;
            }
            l--;
            r++;
        }
        
        return res;
        
    }
}