class Solution {
public:
    string defangIPaddr(string address) {
        string res = "";
        string temp = "";
        int i = 0;
        int sz = address.size();
        int dot_counter = 0;
        while(i < sz)
        {
            if(address[i] != '.')
            {
                temp += address[i];
            }else{
                // is a dot
                res = res + temp;
                dot_counter++;
                if(dot_counter < 4)
                {
                    res = res + "[.]";
                }
                    
                temp = "";
            }
            i++;
            if( i == sz)
            {
                res = res + temp;
            }
        }
        
        return res;
        
        
}
};