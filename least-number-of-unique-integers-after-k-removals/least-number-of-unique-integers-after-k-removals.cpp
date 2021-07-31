class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        
        unordered_map<int,int> m;
        for(int val:arr)
        {
            m[val]++;
        }
        
        vector<pair<int,int> > A;
        
        Cussort(m,A);
        
        int i = 0;
        
        int sz = A.size();
        while( i < sz && k)
        {
            while(A[i].second && k)
            {
                A[i].second--;
                k--;
            }
            
            i++;
        }
        
        int res = 0;
        for(auto val:A)
        {
            if(val.second)
            {
                res++;
            }
        }
        
        return res;
        
        
    }
    
    
    static bool cmp(pair<int, int>& a,pair<int, int>& b)
    {
        return a.second < b.second;
    }
  

    
    void Cussort(unordered_map<int, int>& M, vector<pair<int,int>> &A)
    {




        for (auto& it : M) {
            A.push_back(it);
        }
        


        sort(A.begin(), A.end(), cmp);

        M.clear();


    }
};