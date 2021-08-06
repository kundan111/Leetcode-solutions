class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int sz = num.size();
        int carry = 0;
        for(int i =sz-1; i >= 0; i--)
        {
            int curDigit = k%10;
            k = k/10;
            
            int s = (curDigit + num[i] + carry);
            num[i] =  s%10;
            
            if(s > 9)
            {
                carry = 1;
            }else{
                carry = 0;
                
            }
            
        }
        
        while(k || carry)
        {
            int curDigit = k%10;
            num.insert(num.begin(),(curDigit+carry)%10);
            if(curDigit+carry > 9)
            {
                carry = 1;
            }else{
                
                carry = 0;
                
                
                
            }
            k = k/10;
        }
        
        
        
        return num;
            
    }
};