class Solution {
public:
    bool areOccurrencesEqual(string s) {
           int arr[26] = {0};
            for(auto c: s)
            {
                arr[c-'a']++;
            }
        
        bool flag = true;
        int val;
        for(int i = 0; i < 26; i++)
        {
            if(arr[i] && flag)
            {
                val = arr[i];
                flag = false;
            }
            if(!flag && arr[i])
            {
                if(arr[i] != val)
                {
                    return false;
                }
            }
        }
        
        return true;
    }
};