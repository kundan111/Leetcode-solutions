class pair
{
    char character;
    int count;

    public pair(char character, int count) {
        this.character = character;
        this.count = count;
    }

    @Override
    public String toString() {
        return "[" + character + "," + count + "]";
    }

}
class Solution {
    public String removeDuplicates(String s, int k) {
     
        

        Stack<pair> st = new Stack<>();
        for (int i = 0; i < s.length(); i++) {
            
            char curChar = s.charAt(i);
            if(st.size() > 0)
            {
                // stack not empty
                if(st.peek().character == curChar)
                {
                    st.peek().count++;
                }else{
                    st.push(new pair(curChar, 1));
                }
            }else{
                st.push(new pair(curChar, 1));
            }

            if(st.size() > 0 )
            {
                if(st.peek().count == k)
                {
                    st.pop();
                }

            }

            // System.out.println("st: " + st);



        }

        StringBuilder res = new StringBuilder();
        while (st.size() > 0) {
            pair pop = st.pop();
            int curCount = pop.count;
            char c = pop.character;

            while (curCount-- > 0) {
                
                res.append(c);
            }

        }

        return res.reverse().toString();

    }
}