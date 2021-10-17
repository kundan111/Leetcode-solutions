class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        int sz = nums.size();
        vector<int> prefSum(sz+1);
        
        prefSum[0] = 0;
        int prevSum = 0;
        int i = 1;
        int prev = 0;
        for(int val : nums)
        {
            // cout << "i: " << i << endl << "val: " << val << endl;
            
            prefSum[i] = prefSum[i-1] + nums[i-1];
            i++;
        }
        
        // for(int v : prefSum)
        // {
        //     cout << v << " "; 
        // }
        
        // cout << "yo" << endl;
        
        
        
        // ss(i,j) = pref[j+1] - pref[i]
        
        i = 0;
        int maxSum = -1;
        
        int fl = 0;
        int fr = firstLen - 1;
        
        while(fr < sz)
        {
            
            int fSum = prefSum[fr+1] - prefSum[fl];
            int sl = 0;
            int sr = secondLen - 1;
            
            
            // cout << "fl: " << fl << endl  << "fr: " << fr << endl;
            // cout << "-------------" << endl;
            while(sr < sz)
            {
                if((sl < fl && sr < fl) || (sl > fr))
                {
                    maxSum = max(maxSum, fSum + prefSum[sr+1] - prefSum[sl]);
                    // cout << "sl: " << sl << endl  << "sr: " << sr << endl;
                    // cout << "prefSum["<< sr << "] - prefSum[" << sl << "]: "  << prefSum[sr+1] - prefSum[sl] << endl;
                }
                sl++;
                sr++;
            }
            
            // cout << endl << "fsum: " << fSum << endl << "maxSum: " << maxSum << endl << endl;
            
            
            fl++;
            fr++;
            
        }
    
        
        return maxSum;
    }
};