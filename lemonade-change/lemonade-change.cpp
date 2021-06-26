class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        unordered_map<int,int> m;
        if(!bills.size())
            return true;
        
        for(int i = 0; i < bills.size(); i++)
        {
            m[bills[i]]++;
            
            if(bills[i] == 10)
            {
                if(m[5])
                {
                    m[5]--;
                }else{
                    return false;
                }
            }else if(bills[i] == 20){
                if((m[10] && m[5]) || m[5] >= 3)
                {
                    if((m[10] && m[5]))
                    {
                        m[10]--;
                        m[5]--;    
                    }else{
                        m[5] = m[5] - 3;        
                    }
                }else{
                    return false;        
                }
            }
        }
        
        return true;
    }
};