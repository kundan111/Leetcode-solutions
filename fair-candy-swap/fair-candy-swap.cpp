class Solution {
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
        int s1 = accumulate(aliceSizes.begin(),aliceSizes.end(),0);
        int s2 = accumulate(bobSizes.begin(),bobSizes.end(),0);
        
        
        vector<int>large,small;
        
        if(s1 > s2)
        {
            large = move(aliceSizes);
            small = move(bobSizes);
        }else{
            large = move(bobSizes);
            small = move(aliceSizes);
        }
        
        int c = abs((s2-s1)/2);
        
        // y = (s2-s1)/2 + x;
        
        if(c == 0)
        {
            return {0,0};
        }
        
        // cout << "small" << endl;
        for(int val: small)
        {
            cout << val << " ";
        }
        // cout << endl;
        // cout << "large" << endl;
        for(int val: large)
        {
            cout << val << " ";
        }
        // cout << endl;
        sort(small.begin(),small.end());
        
        int sz = small.size();
        int l = 0;
        
        for(int val : large)
        {
            int ret = binary_search(0,sz-1,small,c,val);
            if(ret != -1)
            {
                // cout << "ret: " << ret << endl << "val: " << val << endl;
                if(s1 > s2)
                {
                    return {val,ret};
                }else{
                    return {ret,val};
                    
                }
            }
        }
        
        
        return {-1,-1};
        
    }
    
    
    int binary_search(int l, int r, vector<int> &small, int c, int curVal)
    {
        int sz = small.size();
        while(l <= r)
        {
            int mid = l + (r-l)/2;
            int midVal = small[mid];
            
            if(curVal - midVal == c)
            {
                // cout << endl;
                // cout << "curVal: " << curVal << " " << "midVal: " << midVal << "c: " << c << endl;
                // cout << "yo" << endl;
                return midVal;
            }
            
            if(midVal > curVal)
            {
                r = mid-1;
            }else{
                if(curVal - midVal < c)
                {
                    r = mid - 1;
                }else{
                    l = mid + 1;
                }
            }
        }
        
        return -1;
    }
};