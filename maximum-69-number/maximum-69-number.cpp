class Solution {
public:
    int maximum69Number (int num) {
        string numString = to_string(num);
        int sz = numString.size();
        
        for(int i = 0; i < sz; i++)
        {
            if(numString[i] == '6')
            {
                numString[i] = '9';
                break;
            }
        }
        
        return stoi(numString);
    }
};