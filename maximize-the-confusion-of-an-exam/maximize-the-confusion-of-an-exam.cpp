class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        vector<int>n;
        int sz = answerKey.size();
        for(int i = 0; i < sz; i++)
        {
            if(answerKey[i] == 'T')
            {
                n.push_back(1);
            }else{
                n.push_back(0);
            }
        }
        
        int m1 = longestSubSeg(n,k);
        
        for(int i = 0; i < sz; i++)
        {
            if(n[i])
            {
                n[i] = 0;
            }else{
                n[i] = 1;
            }
        }
        
        int m2 = longestSubSeg(n,k);
        
        return max(m1,m2);
        
        
        
    }
    
    int longestSubSeg(vector<int> &a, int k)
    {
        int n = a.size();
        int cnt0 = 0;
        int l = 0;
        int max_len = 0;

        
        for (int i = 0; i < n; i++) {
            if (a[i] == 0)
                cnt0++;

            while (cnt0 > k) {
                if (a[l] == 0)
                    cnt0--;
                l++;
            }

            max_len = max(max_len, i - l + 1);
        }

        return max_len;
    }
};