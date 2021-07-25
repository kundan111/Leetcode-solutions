class Solution {
public:
    int getLucky(string s, int k) {
        int res = 0;
        
        for(char c: s)
        {
            if(c-'a' + 1 > 9)
            {
                int cur = (c-'a' + 1);
                while(cur)
                {
                    res = res + cur%10;
                    cur = cur/10;
                }
            }else{
                res = res + (c - 'a' + 1);    
            }
            
        }
        k--;
        if(!k)
        {
            return res;
        }
        int new_sum = res;
        while(k && new_sum >= 10)
        {
            new_sum = f(new_sum);
            k--;
        }
        
        return new_sum;
    }
    
    int f(int res)
    {
        int new_sum = 0;
        while(res)
        {
            new_sum = new_sum + res%10;
            res = res/10;
            
        }
        return new_sum;
    }
};