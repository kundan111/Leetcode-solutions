class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string s1 = "",s2 = "";
        concatenate(word1,s1);
        concatenate(word2,s2);
        
        
        return s1 == s2;
    }
    
    void concatenate(vector<string>& word, string &res)
    {
        for(string str: word)
        {
            
            res = res + str;
        }
    }
};