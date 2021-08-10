class Solution {
public:
    int countPrimes(int n) {
        // vector<bool>Prime(n,false);
        
        if(n < 2)
            return 0;
        
        bool prime[n];
        
        memset(prime, false, sizeof(prime));
        prime[0] = true;
        prime[1] = true;
        
        
        for(int i = 2; i < n ; i++)
        {
            for(int j = 2 ; i*j < n; j++)
            {
                prime[i*j] = true;
            }
        }
        
//         for(auto v: prime)
//         {
//             cout << v << " ";
            
//         }
        
        int count = 0;
        for(int i = 0; i < n ; i++)
        {
            if(!prime[i])
                count++;
        }
        return count;
        
    }
};