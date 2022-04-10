class Solution {
    public int calPoints(String[] ops) {
        return approach1(ops);
    }
    
    int approach1(String[] ops)
    {
        // List<Integer> al = new ArrayList<>();
        int[] al = new int[ops.length+2];
        al[0] = Integer.parseInt(ops[0]);

        int first = 0;
        int second = -1;

        int index = 1;
        int sz = ops.length;

        while (index < sz) {
            if(ops[index].equals("C"))
            {
                first--;
                second--;
            }else if(ops[index].equals("D"))
            {
               int newVal = 2*al[first];
               second = first;
               first++;
               al[first]=newVal;
            }else if(ops[index].equals("+"))
            {
                int newVal = al[first] + al[second];
                second = first;
                first++;
                al[first] = newVal;
            }
            else{
                second = first;
                first++;
                al[first] = Integer.parseInt(ops[index]);
            }
            index++;
        }

        int res = 0;
        while (first >= 0) {
            res += al[first];
            first--;
        }

        // System.out.println(Arrays.toString(al));
        


        return res;
    }
}