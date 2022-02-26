class Solution {
    public int mostWordsFound(String[] sentences) {
        
        int res = -1;
        for (int i = 0; i < sentences.length; i++) {
            int count = 0;
            for (int j = 0; j < sentences[i].length(); j++) {
                if(sentences[i].charAt(j) == ' ')
                {
                    count++;
                }
            }
            res = Math.max(count+1, res);
        }
        
        return res;
        
    }
}