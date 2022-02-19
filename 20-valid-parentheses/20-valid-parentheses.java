class Solution {
public boolean isValid(String s) {
        
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