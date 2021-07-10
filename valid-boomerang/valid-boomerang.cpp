class Solution {
public:
     bool isBoomerang(vector<vector<int>>& points) {
         
         set<pair<int,int>>s;
         for(auto v: points)
         {
             s.insert(make_pair(v[0],v[1]));
         }
         
         if(s.size() < 3)
         {
             return false;
         }
         
        int delta_y_1 =(points[1][1] - points[0][1]);
        int delta_x_1 = (points[1][0] - points[0][0]);
        
        // float slope_1 = delta_x != 0 ? (float)delta_y/delta_x  : 0;
        
        int delta_y_2 =(points[2][1] - points[1][1]);
        int delta_x_2 = (points[2][0] - points[1][0]);
        
        // float slope_2 = delta_x != 0 ? (float)delta_y/delta_x  : 0;
         
         return delta_y_1*delta_x_2 != delta_y_2*delta_x_1;
        
        
        // return slope_1 != slope_2;
    }
};