class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
    unordered_map<char,int>m;
    int i = 0;
    int stonesSz = stones.size();
    while(i < stonesSz)        
    {
        m[stones[i]]++;
        i++;
    }
    i = 0;
    int res = 0;
    int jewelsSz = jewels.size();
    while(i < jewelsSz)
    {
        res = res + m[jewels[i]];
        i++;
    }

    return res;
}
};