class Solution {
public:
    int maxFrequency(vector<int>& A, int k) {
        sort(begin(A), end(A));
        long i = 0, sz = A.size(), ans = 1, sum = 0;
        
        int j = 0;
        
        
        while (j < sz) {
            
            sum += A[j];
            
            while ((j - i + 1) * A[j] > k + sum)
            {
                sum = sum -  A[i];
                i++;
                
            }
            ans = max(ans, j - i + 1);
            j++;
        }
        return ans;
        
    }
};