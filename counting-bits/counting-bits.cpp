class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res(n+1);
        for(int i = 0; i <= n; i++)
        {
            res[i] = OneCounter(i);
        }
        
        return res;
    }
    
    int OneCounter(int n)
    {
        int counter = 0;
        while(n)
        {
            if(n%2)
                counter++;
            n = n/2;
        }
        return counter;
    }
};