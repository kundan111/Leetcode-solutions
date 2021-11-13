class Solution {
public:
    int kthFactor(int n, int k) {
        int div = 1;
        int temp = 0;
        while(div <= n)
        {
            if(n%div == 0)
            {
                temp++;
            }
            if(temp == k)
            {
                return div;
            }
            div++;
        }
        
        return -1;
    }
};