class Solution {
public:
    int subtractProductAndSum(int n) {
        int sum = 0;
        int prd = 1;
        
        while(n)
        {
            int last = n%10;
            sum += last;
            prd *= last;
            n = n/10;
        }
        
        return prd - sum;
    }
};