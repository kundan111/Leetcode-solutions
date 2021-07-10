class Solution {
public:
    int numDifferentIntegers(string word) {
        
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        
        unordered_set<string>s;
        int sz = word.size();
        
        for(int i = 0; i < sz; i++)
        {
            
            int j = i;
            if(j < sz && isdigit(word[j]))
            {
                
                string temp = "";
                while(j < sz && isdigit(word[j]))
                {
                    
                    temp += word[j];
                    j++;
                }
                
                int z=0;
                while(z<temp.length() && temp[z] == '0') z++;
                temp = temp.substr(z);
                
                s.insert(temp);
                
            }
            i = j;
        }
        
        return s.size();
    }
};