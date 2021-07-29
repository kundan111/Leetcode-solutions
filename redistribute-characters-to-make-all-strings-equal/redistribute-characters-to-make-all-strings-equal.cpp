class Solution {
public:
    bool makeEqual(vector<string>& words) {
        
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        
        int arr[26] = {0};
        int eachCharCount = words.size();
        if(eachCharCount == 1)
        {
            return true;
        }
        for(string word: words)
        {
            for(char c: word)
            {
                arr[c-'a']++;
            }
            
        }
        
        bool flag = true;
        int commVal;
        for(int i = 0; i < 26; i++)
        {
           if(arr[i])
           {
               if(arr[i]%eachCharCount != 0)
               {
                   return false;
               }
           }
        }
        
        return true;
    }
};