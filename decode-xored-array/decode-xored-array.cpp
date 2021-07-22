class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        vector<int> res;
        res.push_back(first);
        for(int val:encoded)
        {
            first = first^val;
            res.push_back(first);
        }
        return res;
    }
};