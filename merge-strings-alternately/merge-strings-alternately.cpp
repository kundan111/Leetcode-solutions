class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int i = 1;
        int sz1 = word1.size(),sz2 = word2.size();
        
        
        
        for(int j = 0; j < word2.size(); j++)
        {
            word1.insert(word1.begin()+i, word2[j]);
            i = i +1;
            
            if(word1.begin() + i == word1.end())
            {
               word1 = word1 + word2.substr(j+1)   ;
                return word1;
            }
            
            i = i +1;
            
            if(word1.begin() + i == word1.end())
            {
               word1 = word1 + word2.substr(j+1)   ;
                return word1;
            }
        }
        
        
        
        return word1;
    }
};