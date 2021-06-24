class Solution {
public:
    string largestOddNumber(string num) {
        int i = num.size()-1;
        int oddIndx = -1;
        while(i >= 0)
        {
            if((num[i] - '0') & 1)
            {
                oddIndx = i;
                break;
                
            }
            i--;
        }
        
        return (oddIndx == -1) ? "" : num.substr(0, oddIndx+1);
        
    }
};