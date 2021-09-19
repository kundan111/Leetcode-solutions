class Solution {
    
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
    
        
        auto comp = [&](int a,int b)-> bool {

             if(abs(a - x) != abs(b - x))
             {
                return abs(a - x) < abs(b - x);
             }
        
        return a < b;
        };
        
        sort(arr.begin(),arr.end(), comp);
        
        vector<int> ret (arr.begin(),arr.begin()+k);
        
        sort(ret.begin(),ret.end());
        
        return ret;
        
        
        
    }
    
//     static bool comp(int a, int b)
//     {
//         if(abs(a - _x) != abs(b - _x))
//         {
//             return abs(a - _x) < abs(b - _x);
//         }
        
//         return a < b;
//     }
};