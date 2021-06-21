class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        int i = 0;
        int odd_counter = 0;
        int sz = position.size();
        while(i < sz)
        {
            
            if(position[i] & 1)
                odd_counter++;
            
            i++;
        }
        return min(odd_counter,sz-odd_counter);
    }
};