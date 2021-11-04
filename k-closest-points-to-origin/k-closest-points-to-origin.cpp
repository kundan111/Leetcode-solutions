class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
       
        // sort(points.begin(),points.end(),comp);
        
        sort(points.begin(),points.end(),[this](vector<int> &point1, vector<int> &point2)
                    {
                        return distFromOrigin(point1) < distFromOrigin(point2);
                    }
            );
        
        // for(auto val : points)
        // {
        //     cout << "(" << val[0] << ", " << val[1] << ") " << " -> " << distFromOrigin(val) << endl;  
        // }
        // cout << endl;
        
        // vector<vector<int>> res;
        
        vector<vector<int>> res = vector<vector<int>>(points.begin(), points.begin() + k);
        
        return res;
        
    }
    
    long long int distFromOrigin(vector<int> &point)
    {
        return 1LL*pow(point[0],2) + 1LL*pow(point[1],2);
    }
    
    // static bool comp(vector<int> &point1, vector<int> &point2)
    // {
    //     return distFromOrigin(point1) < distFromOrigin(point2);
    // }
};