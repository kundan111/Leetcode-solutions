class Solution {
    public boolean isPowerOfTwo(int n) {
            return isPowerof2(n);
    }
    boolean isPowerof2(int n)
    {
        if(n <= 0)
        {
            return false;
        }
        if(n == 1)
        {
            return true;
        }
        if(n%2 == 1)
        {
            return false;
        }

        return isPowerof2(n/2);
    }
}