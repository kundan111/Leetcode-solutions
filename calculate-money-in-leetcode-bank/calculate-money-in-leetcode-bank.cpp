class Solution {
public:
    int totalMoney(int n) {
     int weeks = n/7;
     int days = n%7;
        
        int res = 0;
     
        for(int i =1; i <= weeks; i++)
        {
            res = res + (7*i + 21);
        }
        
        int newWeekStarting = weeks + 1;
        
        return days*newWeekStarting + days*(days-1)/2 + res;
        
        
    }
};