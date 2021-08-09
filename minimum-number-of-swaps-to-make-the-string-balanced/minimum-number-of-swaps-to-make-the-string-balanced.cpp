class Solution {
public:
    int minSwaps(string s) {
        int closing = 0;
        int maxClosing  = 0;
        for(auto c: s)
        {
            if(c == '[')
                closing -= 1;
            else{
                closing += 1;
            }
            
            maxClosing = max(closing,maxClosing);
        }
        return (maxClosing + 1)/2;
    }
};