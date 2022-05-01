class Solution {
    public int countPrefixes(String[] words, String s) {
        
        int count = 0;
        for (String word : words) {
            if(isPrefix(word, s))
            {
                // System.out.println(word);
                count++;
            }
        }

        return count;
    }

    boolean isPrefix(String word, String s)
    {
        int sz1 = word.length();
        int sz2 = s.length();

        int i = 0;
        int j = 0;
        while (i < sz1 && j < sz2) {
            if(word.charAt(i) != s.charAt(j))
            {
                return false;
            }
            i++;
            j++;
        }

        if(i < sz1)
        {
            return false;
        }

        return true;
    }
}