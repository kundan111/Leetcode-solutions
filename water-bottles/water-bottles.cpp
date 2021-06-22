class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        
        int res  = numBottles;
        while(numBottles >= numExchange)
        {
            int newEmpty = numBottles/numExchange;
            res = res + newEmpty;
            int oddBottles = numBottles % numExchange;
            numBottles = newEmpty + oddBottles;
        }
        
        return res;
        
    }
};