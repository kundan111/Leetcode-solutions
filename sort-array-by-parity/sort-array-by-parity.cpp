class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
         int n = A.size();    
    int s = 0;int e = n-1;
    vector <int> temp(n);
    for(int i = 0; i < n ; i++)
    {
        if(A[i]%2 == 0)
            temp[s++] = A[i];
        else
            temp[e--] = A[i];
    }
    A.clear();
    copy(temp.begin(),temp.end(),back_inserter(A));
    return A;
    }
};