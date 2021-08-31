class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int sz  = arr.size();
        int n = 1;
        for(int i = 0; i < sz; )
        {
            if(arr[i] == n)
            {
                i++;
            }else{
                k--;
                if(k == 0)
                {
                    return n;
                }
            }
            n++;
            cout << "n: "  << n << " k: " << k << endl;
        }
        return --n + k;
        
    }
};