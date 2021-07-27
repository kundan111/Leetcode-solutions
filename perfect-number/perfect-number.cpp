class Solution {
public:
    bool checkPerfectNumber(int num) {
        
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        
        if(num == 1)
            return false;

        
        int res = 1;
        int divisor = 2;
        while(divisor*divisor <= num)
        {
            if(num % divisor  == 0)
            {
                res = res + divisor;
                if(num/divisor != divisor)
                {
                    res += num/divisor;
                }
            }
            
            if(res > num)
            {
                return false;
            }
            
            divisor++;
        }
        
        return res == num;
    }
};