class Solution {
public:
    bool squareIsWhite(string c) {
        
         if((c[0]-'a')%2 == 0 )
         {
             return !((c[1]-1) % 2 == 0);
         }else{
             return ((c[1]-1) % 2 == 0);
         }
        return 1;
             
    }
};