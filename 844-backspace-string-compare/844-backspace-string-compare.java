class Solution {
    public boolean backspaceCompare(String s, String t) {
        
        Stack<Character> st1 = new Stack<>();
        Stack<Character> st2 = new Stack<>();

        sanitise(st1, s);
        sanitise(st2, t);

        if(st1.size() != st2.size())
        {
            return false;
        }


        while (st1.size() > 0) {
            if(st1.pop() != st2.pop())
            {
                return false;
            }
        }

        

        return true;
    }

    void sanitise(Stack<Character> st1, String s)
    {
        

        for (int i = 0; i < s.length(); i++) {
            
            char curChar = s.charAt(i);
            if(curChar != '#')
            {
                st1.push(curChar);
            }else{
                // backspace
                if(st1.size() > 0)
                {
                    // atleast one element
                    st1.pop();
                }
            }

        }
    }
}