class Solution {
public:
    int canBeTypedWords(string t, string b) {
        int notAbletotype = 0;
        int i = 0;
        
        int sz = t.size();
        int arr[26] = {0};
        
        for(char c : b)
        {
            arr[c-'a']++;
        }
        
        int spaces = 0;
        while(i < sz)
        {
            int j = i;
            bool flag = false;
            while( j < sz && t[j] != ' ')
            {
                if(!flag)
                {
                    if(arr[t[j]-'a'])
                    {
                        notAbletotype++;
                        flag  = true;
                    }
                }
                j++;
            }
            if(j < sz && t[j] == ' ')
            {
                spaces++;
                j++;
            }
            i = j;
        }
        
        return (spaces + 1 - notAbletotype);
    }
};