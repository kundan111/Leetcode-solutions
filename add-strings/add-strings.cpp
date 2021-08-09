class Solution {
public:
    string addStrings(string num1, string num2) {
        
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        
        int sz1 = num1.size();
        int sz2 = num2.size();
        
        int i = sz1-1;
        int j = sz2-1;
        
        int carry = 0;
        string res = "";
        while( i >=0  && j >= 0)
        {
            char curf = num1[i];
            char curs = num2[j];
            
            int s = ((curf - '0') + (curs - '0')) + carry;
            int newDigit = s%10;
            
            res.insert(res.begin(),(char)(newDigit + 48));
            
            if(s > 9)
            {
                carry = 1;
            }else{
                carry = 0;
            }
            i--;
            j--;
        }
        
        if(i < 0 && j < 0)
        {
            if(carry)
            {
                res.insert(res.begin(),(char)(49));    
            }
            
            return res;
        }
        
        int remaining;
        string longer;
        if(i < 0)
        {
            remaining = j;
            longer = num2;
        }else{
            remaining = i;
            longer = num1;
        }
        
        
        
        while(remaining >= 0)
        {
            int sum = ((longer[remaining] - '0') + carry);
            res.insert(res.begin(),(char)(48 + (sum%10)));
            if(sum > 9)
            {
                carry = 1;
            }else{
                carry = 0;
            }
            remaining--;
        }
        
        if(carry)
        {
            res.insert(res.begin(),(char)(49)); 
        }
        
        return res;
    
    }
};