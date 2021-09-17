class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        for(auto &row: mat)
        {
            if(bs(row,target))
            {
                return true;
            }
        }
        return false;
    }
    
    
    bool bs(vector<int> &vec, int val)
    {
        int l = 0;
        int r = vec.size()-1;
        
        while(l <= r)
        {
            int mid = l + (r-l)/2;
            if(vec[mid] == val)
            {
                return true;
            }else if(vec[mid] > val)
            {
                r = mid-1;
            }else{
                l = mid+1;
            }
        }
        return false;
    }
};