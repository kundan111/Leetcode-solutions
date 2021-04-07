bool comp(pair<int,int> a, pair<int,int> b)
    {
        if(a.first < b.first)   
            return true;
        return false;
    }
class Solution {
public:
    
    vector<int> twoSum(vector<int>& vec, int t) {
        
        int n =  vec.size();
        vector <pair<int,int> >newArr(n);
        for(int i = 0; i < n;i++)
        {
            newArr[i].first = vec[i];
            newArr[i].second = i;
        }
        int f = 0; int s = n-1;
        sort(newArr.begin(),newArr.end(), comp);
        while(f<s)
        {
            if(newArr[f].first+newArr[s].first == t)
                break;
            else if(newArr[f].first+newArr[s].first > t)
                s--;
            else
                f++;
        }
        
        vector<int>res;
        res.push_back(newArr[f].second);
        res.push_back(newArr[s].second);
        
        return res;
    }
};