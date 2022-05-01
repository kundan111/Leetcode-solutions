class Solution {
    public int tribonacci(int n) {
        if(n == 0)
        {
            return 0;
        }

        if(n == 1 || n == 2)
        {
            return 1;
        }


        int first = 0;
        int second = 1;
        int third = 1;

        int i = 0;

        while (i != n-3) {
            int temp1 = first;
            first = second;
            int temp2 = second;
            second = third;
            third = temp1 + temp2 + third;
            i++;
        }
        
        return first + second + third;
    }
}