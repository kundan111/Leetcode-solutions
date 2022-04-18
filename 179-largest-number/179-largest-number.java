class Solution {
    public String largestNumber(int[] nums) {
    
        String[] numsStrArr = new String[nums.length];

        int i = 0;
        for (int val : nums) {
            numsStrArr[i] = Integer.toString(val);
            i++;
        }

        
        Comparator<String> comp = new Comparator<String>() {
            @Override
            public int compare(String s1, String s2) {

                String p1 = s1 + s2;
                String p2 = s2 + s1;

                
                return -p1.compareTo(p2);

            }
        };

        Arrays.sort(numsStrArr,comp);

        if (numsStrArr[0].equals("0")) {
            return "0";
        }

        StringBuilder sb = new StringBuilder();

        for (String sVal : numsStrArr) {
            sb.append(sVal);
        }

        return sb.toString();
    }

    int countNumberOfZeros(String s)
    {
        int res = 0;
        for (int i = 0; i < s.length(); i++) {
            if(s.charAt(i) == '0')
            {
                res++;
            }
        }
        return res;
    }

}