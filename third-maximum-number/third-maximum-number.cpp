class Solution {
public:
    int thirdMax(vector<int>& n) {
    set<int> m (n.begin(), n.end());
    auto it = m.end();
    if (m.size() < 3) {
        advance(it, -1);
        return *it;
    }
   advance(it, -3) ;
    return *it;
}
};