class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(),arr.end(),comp);
        
        
        return arr;
        
    }
    
    static bool comp(int a, int b)
    {
        bitset<15>f(a);
        bitset<15>s(b);
        
        if(f.count() < s.count())
        {
            return true;
        }else if(f.count() > s.count())
        {
            return false;
        }else{
            return a < b;
        }
    }
};