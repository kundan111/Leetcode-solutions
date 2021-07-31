class Solution {
public:
    int minCost(string s, vector<int>& cost) {
        int i = 0;
        int sz = s.size();
        
        int res = 0;
        
        while( i < sz)
        {
            int j = i;
            // find repeting characters 
            int count = 0;
            int start = j;
            while(j < sz-1 && s[j] == s[j+1])
            {
                count++;
                j++;
            }
            
            // j will point to next to non-repeating char or sz
            /// remove count characters
            if(count)
            {
                // i have found repeating characters
                priority_queue<int, vector<int>, greater<>> pq;
                int z = start;
                while(z <= j)
                {
                    pq.push(cost[z]);
                    z++;
                }
                while(count)
                {
                     res = res + pq.top();
                     pq.pop();
                    count--;
                }
                
            }
            
            i = j;
        
            i++;
        }
        
        
        return res;
    }
};