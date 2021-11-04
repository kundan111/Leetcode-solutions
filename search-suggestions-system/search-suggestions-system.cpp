class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        
        
        sort(products.begin(),products.end());
        vector<vector<string>> res;
        int curSz = 1;
        int i = 0;
        int wsz = searchWord.size();
        while(curSz <= wsz)
        {
            string curWord = searchWord.substr(0,curSz);
            res.push_back(recommender(products,curWord));
            curSz++;
        }
        
        return res;
    }
    
    vector<string> recommender(vector<string>& products, string &curword)
    {
        
        // cout << "curword: " << curword << endl;
        int sz = products.size();
        int wsz = curword.size();
        vector<string> res;
        int count = 0;
        int i = 0;
        while(i < sz)
        {
            if(count < 3)
            {
                if(products[i].substr(0,wsz) == curword)
                {
                    res.push_back(products[i]);
                    count++;
                }
                
            }else{
                break;
            }
            i++;
        }
        
        return res;
    }
    
    
};