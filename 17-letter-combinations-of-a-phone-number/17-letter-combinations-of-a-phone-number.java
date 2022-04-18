class Solution {
    private static HashMap<Character,String> hm = new HashMap<>();
    static{
        hm.put('2', "abc");
        hm.put('3', "def");
        hm.put('4', "ghi");
        hm.put('5', "jkl");
        hm.put('6', "mno");
        hm.put('7', "pqrs");
        hm.put('8', "tuv");
        hm.put('9', "wxyz");
    }
    List<String> res = new ArrayList<>();
    public List<String> letterCombinations(String digits) {
            if(digits.length() == 0)
            {
                return res;
            }
            recur(digits, 0, new StringBuilder());
            return res;
    }

    void recur(String s , int curIndex, StringBuilder sb)
    {
        if(s.length() == curIndex)
        {
            res.add(sb.toString());
            return;
        }

        String curString = hm.get(s.charAt(curIndex));

        for (int i = 0; i < curString.length(); i++) {
            sb.append(curString.charAt(i));
            recur(s, curIndex+1, sb);
            sb.deleteCharAt(sb.length()-1);
        }
        
    }
    
}