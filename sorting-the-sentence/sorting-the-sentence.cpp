class Solution {
public:
    string sortSentence(string s) {
        vector<string> wordArray;
        
        int sz = s.size();
        
        int i = 0;
        while( i < sz )
        {
            string temp = "";
            while(i < sz && s[i] != ' ')
            {
                temp = temp + s[i];
                i++;
            }
            i++;
            wordArray.push_back(temp);
        }
        
        sort(wordArray.begin(),wordArray.end(),comp);
        
        string res = "";
        for(string word: wordArray)
        {
            res = res + word.substr(0,word.size()-1) + " ";
        }
        
        res = res.substr(0,res.size()-1);
        
        return res;
    }
    
    static bool comp(string s1, string s2)
    {
        return s1[s1.size()-1] < s2[s2.size()-1];
    }
};