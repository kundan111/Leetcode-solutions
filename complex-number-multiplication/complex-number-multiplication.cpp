class Solution {
public:
    string complexNumberMultiply(string num1, string num2) {
        
        auto r1 = parser(num1);
        auto r2 = parser(num2);
        
        int a = r1[0],b = r1[1];
        int c = r2[0],d = r2[1];
        
        
        int e = (a*c) + (-1)*(b*d);
        int f = (a*d) + (b*c);
        return to_string(e) + "+" + to_string(f) + "i";
    }
    
    vector<int> parser(string &num)
    {
        int sz = num.size();
        
        bool f = true;
        string a,b;
        
        for(char &c: num)
        {
            if(c == '+')
            {
                f = false;
            }
            
            if(f)
            {
                a += c;
            }else{
                if(c != 'i' && c != '+')
                {
                    b += c;
                }
            }
        }
        
        return {stoi(a),stoi(b)};
        
    }
};