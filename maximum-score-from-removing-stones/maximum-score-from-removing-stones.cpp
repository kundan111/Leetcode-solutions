class Solution {
public:
    int maximumScore(int a, int b, int c) {
        
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        
        vector<int> v{a,b,c};
        int res = 0;
        while( (v[0] && v[1]) || (v[1] && v[2]) || (v[0] && v[2]))
        {
        
            res++;
            // sort(v.begin(),v.end());
            cusSort(v);
            v[1]--;
            v[2]--;
        }
        
        return res;
        
        
    }
    
    void cusSort(vector<int> &arr)
    {
        // Insert arr[1]
        if (arr[1] < arr[0])
           swap(arr[0], arr[1]);

        // Insert arr[2]
        if (arr[2] < arr[1])
        {
           swap(arr[1], arr[2]);
           if (arr[1] < arr[0])
              swap(arr[1], arr[0]);
        }
    }
   
};