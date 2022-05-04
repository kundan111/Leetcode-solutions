class BracketPositionPair{
    
    char bracket;
    int position;

    public BracketPositionPair(char bracket, int position) {
        this.bracket = bracket;
        this.position = position;
    }

    @Override
    public String toString() {
        return "[" + bracket + "," + position + "]";
    }

    
}
class Solution {
    public String minRemoveToMakeValid(String s) {
        

        List<BracketPositionPair> bracketSymbolList = buildSanitisedInput(s);
        List<BracketPositionPair> errorBrackets = removeOddBrackets(bracketSymbolList);

        HashMap<Integer,Integer> hm = new HashMap<>();
        for (BracketPositionPair bracketPositionPair : errorBrackets) {
            hm.put(bracketPositionPair.position, 1);
        }

        StringBuilder sb = new StringBuilder();
        
        for (int i = 0; i < s.length(); i++) {
            if(!hm.containsKey(i))    
            {
                sb.append(s.charAt(i));
            }
        }

        return sb.toString();
    }

    

    List<BracketPositionPair> removeOddBrackets(List<BracketPositionPair> bracketSymbolList)
    {
        List<BracketPositionPair> res = new ArrayList<>();

        Stack<BracketPositionPair> st = new Stack<>();

        for (BracketPositionPair bracket : bracketSymbolList) {
            
            char curBracket = bracket.bracket;

            if(curBracket == '(')
            {

                st.push(bracket);

            }else{

                if(st.isEmpty())
                {
                    // not balanced
                    res.add(bracket);
                }else{
                    st.pop();
                }

            }
        }

        while (!st.empty()) {
            res.add(st.pop());
        }


        return res;
    }


    List<BracketPositionPair> buildSanitisedInput(String s)
    {
        List<BracketPositionPair> res = new ArrayList<>();

        for (int i = 0; i < s.length(); i++) {
            if(s.charAt(i) == ')' || s.charAt(i) == '(')
            {
                res.add(new BracketPositionPair(s.charAt(i), i));
            }
        }

        return res;
    }
}