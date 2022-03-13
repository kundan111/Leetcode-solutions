class Solution {
    public boolean isHappy(int n) {

        HashMap<Integer,Integer> hm = new HashMap<>();
        while (true) {

            n = mutate(n);

            if(n == 1)
            {
                return true;
            }

            if(hm.containsKey(n))
            {
                return false;
            }

            hm.put(n, 1);

            
        }
        

    }

    int mutate(int n)
    {
        int res = 0;
        while (n > 0) {
            int unitVal = n%10;

            res += unitVal*unitVal;

            n /= 10;

        }
        return res;
    }
}