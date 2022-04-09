class Solution {
    int totalParan;
    public List<String> generateParenthesis(int n) {
        
        totalParan = 2*n;
        Set<String> res = new HashSet<>();

        parenthesisRecur("(", ')', res);
        // System.out.println("===========================");
        parenthesisRecur("(", '(', res);
        


        // System.out.println("printing res ");
        // System.out.println(res);
     
     
        return res.stream().collect(Collectors.toList());
    }
    
    void parenthesisRecur(String currentStr, char currentChar, Set<String> res)
    {
        // System.out.println("currentStr: " + currentStr + " and currentChar: " + currentChar);
        // base case
        if(currentStr.length() == totalParan)
        {
            if(isBalanced(currentStr))
            {
                res.add(currentStr);
                // System.out.println("final one: " + currentStr);
            }
            return;
        }
        
        currentStr += currentChar;
        parenthesisRecur(currentStr, ')', res);
        parenthesisRecur(currentStr, '(', res);

    }
    boolean isBalanced(String s)
    {
        
        // odd length string can never be balanced
        if((s.length() & 1)  != 0)
        {
            return false;
        }

        

        Map<Character,Character> mapper = new TreeMap<>();
        mapper.put(')', '(');
        mapper.put('}', '{');
        mapper.put(']', '[');

        
        Stack<Character> st = new Stack<>();
        int sz = s.length();

        for (int i = 0; i < sz; i++) {
            char character = s.charAt(i);
            if(character == '(' || character == '{' || character == '[')
            {
                st.push(character);
            }else{
                if(st.isEmpty())
                {
                    return false;
                }
                if(mapper.get(character) != st.pop())
                {
                    return false;
                }
            }
            
        }

        return st.size() == 0;
    }
}