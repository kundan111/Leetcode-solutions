class Solution {
public:
    int findKthLargest(vector<int>& v, int k) {
        int sz = v.size();
        int i = 0;
        int ori = k;
        while(k)
        {
            int _max = INT_MIN;
            int max_ind = -1;
            int j = i;
            for(int k = j; k <sz; k++)
            {
                if(v[k] > _max)
                {
                    _max = v[k];
                    max_ind = k;
                }
            }
            
            swap(v[j],v[max_ind]);
            i++;
            k--;
        }
        
        
        return v[ori-1];
    }
};