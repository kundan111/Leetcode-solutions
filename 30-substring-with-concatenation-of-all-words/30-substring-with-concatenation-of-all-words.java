class Solution {
    public List<Integer> findSubstring(String s, String[] words) {

        if(s == null || words ==  null)
        {
            throw new IllegalArgumentException("words or s can not be empty");
        }

        
        
        HashMap<String, Integer> freqMap = buildFreqMap(words);

        int wordLength = words[0].length();
        int totalNumOfWords = words.length;

        return sol(freqMap, s, wordLength, totalNumOfWords);
    }

    HashMap<String, Integer> buildFreqMap(String[] words)
    {
        HashMap<String, Integer> freqMap = new HashMap<>();

        for (String string : words) {
            freqMap.put(string, freqMap.getOrDefault(string, 0) +1 );
        }


        return freqMap;
    }

    List<Integer> sol(HashMap<String, Integer> freqMap, String s, int wordLength, int totalNumOfWords)
    {
        List<Integer> ans = new ArrayList<>();

        for (int i = 0; i <= s.length() - wordLength*totalNumOfWords; i++) {
            
            Map<String,Integer> seenWords = new HashMap<>();

            for (int j = 0; j < totalNumOfWords; j++) {
                
                int wordIndex = i + j * wordLength;

                String word = s.substring(wordIndex, wordIndex+wordLength);
                
                if(!freqMap.containsKey(word))
                {
                    break;
                }

                seenWords.put(word, seenWords.getOrDefault(word, 0) + 1);

                if(seenWords.get(word) > freqMap.getOrDefault(word, 0))
                {
                    break;
                }

                if(j+1 == totalNumOfWords)
                {
                    ans.add(i);
                }


            }
        }


        return ans;

    }
}