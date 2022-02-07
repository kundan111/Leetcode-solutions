class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        Map<String,List<String>> m = new HashMap();
        for(String s : strs)
        {
            String ori = s;
            // char[] charArr = ori.toCharArray();
            // Arrays.sort(charArr);
            // String key = String.valueOf(charArr);
            
            String key = cusSort(ori);
            if(!m.containsKey(key))
            {
                m.put(key,new ArrayList<>());
            }
            m.get(key).add(s);
        }
        
        // System.out.println(m.values());
        
        return new ArrayList<>(m.values());
    }
    
    
    static String cusSort(String ori)
    {
        char[] cArr = new char[26];
        int sz = ori.length();
        for(int i = 0; i < sz; i++)
        {
            char c = ori.charAt(i);
            cArr[c-'a']++;
        }
        
        StringBuilder s = new StringBuilder();
        for(int i = 0; i < 26; i++)
        {
            StringBuilder temp = new StringBuilder();
            for(int j = 0; j < cArr[i]; j++)
            {
                temp.append(i+'a');
            }
            
            s.append(temp);
        }
        
        return s.toString();
    }
    
}